#include <iostream>
#include "MemoryPool.h"

using namespace std;

struct Sensor {
    int id;
    float deger;
    float matris[6];   // 4 + 4 + 24 = 32 byte, raf'a tam sigar
};

static int hataSayisi = 0;

// Bir kosulu kontrol eder, sonucu ekrana yazar, basarisizsa sayaci artirir
void kontrol(const char* ad, bool sonuc) {
    cout << (sonuc ? "  [OK]   " : "  [HATA] ") << ad << endl;
    if (!sonuc) hataSayisi++;
}

// TEST 1: Baslangic durumu
// Kurucu sayaclari sifirlamali; cop deger kalmamali
void test1_baslangic() {
    cout << "TEST 1: Baslangic durumu" << endl;
    MemoryPool pool;
    kontrol("kullanilan == 0", pool.kullanilan() == 0);
    kontrol("tepe == 0", pool.tepe() == 0);
}

// TEST 2: create / destroy temel akis
// Nesne rafta kurulur, kullanilir, sonra raf iade edilir
void test2_create_destroy() {
    cout << "TEST 2: create / destroy" << endl;
    MemoryPool pool;
    Sensor* s = pool.create<Sensor>();
    kontrol("create NULL donmedi", s != NULL);
    kontrol("create sonrasi kullanilan == 1", pool.kullanilan() == 1);

    s->id = 7;
    s->deger = 36.6f;
    kontrol("nesneye yazilan deger okunabiliyor", s->id == 7 && s->deger == 36.6f);

    kontrol("destroy true dondu", pool.destroy(s) == true);
    kontrol("destroy sonrasi kullanilan == 0", pool.kullanilan() == 0);
}

// TEST 3: Raf geri donusumu (reuse, LIFO)
// Iade edilen raf zincirin basina baglanir, siradaki create onu almali
void test3_reuse() {
    cout << "TEST 3: Raf geri donusumu" << endl;
    MemoryPool pool;
    Sensor* s1 = pool.create<Sensor>();
    Sensor* s2 = pool.create<Sensor>();
    Sensor* s3 = pool.create<Sensor>();

    pool.destroy(s2);                          // ortadaki rafi iade et
    Sensor* s4 = pool.create<Sensor>();        // ayni rafi geri almali
    kontrol("s4 == s2 (ayni fiziksel raf)", s4 == s2);

    pool.destroy(s1);
    pool.destroy(s3);
    pool.destroy(s4);
}

// TEST 4: Raflar ardisik ve araliklar esit
// Ardisik tahsis edilen raflar arasinda tam 32 byte olmali
void test4_ardisik_adresler() {
    cout << "TEST 4: Raf adres araliklari" << endl;
    MemoryPool pool;
    unsigned char* a = pool.allocate();
    unsigned char* b = pool.allocate();
    unsigned char* c = pool.allocate();
    kontrol("a -> b farki 32 byte", (b - a) == 32);
    kontrol("b -> c farki 32 byte", (c - b) == 32);
    pool.deallocate(a);
    pool.deallocate(b);
    pool.deallocate(c);
}

// TEST 5: Havuz dolu (Out of Memory)
// 8 raf bitince create cokmemeli, NULL donmeli
void test5_havuz_dolu() {
    cout << "TEST 5: Havuz dolu" << endl;
    MemoryPool pool;
    Sensor* dizi[8];
    bool hepsiAlindi = true;
    for (int i = 0; i < 8; i++) {
        dizi[i] = pool.create<Sensor>();
        if (dizi[i] == NULL) hepsiAlindi = false;
    }
    kontrol("ilk 8 create basarili", hepsiAlindi);
    kontrol("kullanilan == 8", pool.kullanilan() == 8);

    Sensor* fazla = pool.create<Sensor>();     // 9. istek
    kontrol("9. create NULL dondu", fazla == NULL);
    kontrol("basarisiz create sayaci bozmadi", pool.kullanilan() == 8);

    for (int i = 0; i < 8; i++) pool.destroy(dizi[i]);
}

// TEST 6: Havuz disindaki adres reddedilmeli
// Stack'teki bir degisken havuza ait degil
void test6_havuz_disi_adres() {
    cout << "TEST 6: Havuz disi adres" << endl;
    MemoryPool pool;
    unsigned char disarida = 0;
    kontrol("deallocate(&disarida) false", pool.deallocate(&disarida) == false);
    kontrol("deallocate(NULL) false", pool.deallocate(NULL) == false);
    kontrol("kullanilan == 0 kaldi", pool.kullanilan() == 0);
}

// TEST 7: Rafin ortasindan verilen adres reddedilmeli
// Raf basi + 5 gecerli bir raf adresi degil
void test7_rafin_ortasi() {
    cout << "TEST 7: Rafin ortasi" << endl;
    MemoryPool pool;
    unsigned char* p = pool.allocate();
    kontrol("deallocate(p + 5) false", pool.deallocate(p + 5) == false);
    kontrol("raf hala dolu (kullanilan == 1)", pool.kullanilan() == 1);
    pool.deallocate(p);
}

// TEST 8: Cift iade (double free) yakalanmali
// Ayni raf iki kez iade edilirse zincir bozulmamali
void test8_cift_iade() {
    cout << "TEST 8: Cift iade" << endl;
    MemoryPool pool;
    Sensor* s = pool.create<Sensor>();
    kontrol("ilk destroy true", pool.destroy(s) == true);
    kontrol("ikinci destroy false", pool.destroy(s) == false);
    kontrol("kullanilan 0'in altina inmedi", pool.kullanilan() == 0);

    // Zincir saglam mi: iki create farkli raf vermeli
    Sensor* x = pool.create<Sensor>();
    Sensor* y = pool.create<Sensor>();
    kontrol("zincir bozulmadi (x != y)", x != y);
    pool.destroy(x);
    pool.destroy(y);
}

// TEST 9: NULL pointer ile destroy
// Bos pointer sessizce reddedilmeli, program cokmemeli
void test9_null_destroy() {
    cout << "TEST 9: NULL destroy" << endl;
    MemoryPool pool;
    Sensor* bos = NULL;
    kontrol("destroy(NULL) false", pool.destroy(bos) == false);
}

// TEST 10: Hizalama
// Her rafin adresi 8'in kati olmali
void test10_hizalama() {
    cout << "TEST 10: Hizalama" << endl;
    MemoryPool pool;
    bool hepsiHizali = true;
    unsigned char* raflar[8];
    for (int i = 0; i < 8; i++) {
        raflar[i] = pool.allocate();
        if (reinterpret_cast<size_t>(raflar[i]) % 8 != 0) hepsiHizali = false;
    }
    kontrol("8 rafin hepsi 8'in kati adreste", hepsiHizali);
    for (int i = 0; i < 8; i++) pool.deallocate(raflar[i]);
}

// TEST 11: Kullanim sayaci ve tepe degeri
// kullanilan duser, tepe (high-water mark) dusmez
void test11_sayac_ve_tepe() {
    cout << "TEST 11: Sayac ve tepe" << endl;
    MemoryPool pool;
    Sensor* a = pool.create<Sensor>();
    Sensor* b = pool.create<Sensor>();
    Sensor* c = pool.create<Sensor>();
    kontrol("3 create sonrasi kullanilan == 3", pool.kullanilan() == 3);

    pool.destroy(b);
    pool.destroy(c);
    kontrol("2 destroy sonrasi kullanilan == 1", pool.kullanilan() == 1);
    kontrol("tepe == 3 kaldi", pool.tepe() == 3);

    pool.destroy(a);
}

int main() {
    test1_baslangic();
    test2_create_destroy();
    test3_reuse();
    test4_ardisik_adresler();
    test5_havuz_dolu();
    test6_havuz_disi_adres();
    test7_rafin_ortasi();
    test8_cift_iade();
    test9_null_destroy();
    test10_hizalama();
    test11_sayac_ve_tepe();

    cout << endl;
    if (hataSayisi == 0) {
        cout << "TUM TESTLER GECTI" << endl;
    } else {
        cout << hataSayisi << " TEST BASARISIZ" << endl;
    }
    return hataSayisi;
}
