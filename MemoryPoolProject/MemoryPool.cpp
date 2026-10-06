#include "MemoryPool.h"    // kendi basligimiz: tirnak ile, cunku bizim dosyamiz (<> sistem basliklari icin)

MemoryPool::MemoryPool() {
	static_assert(BLOCK_SIZE >= sizeof(unsigned char*), "Raf, bir pointer'i tutamayacak kadar kucuk!");
	static_assert(BLOCK_COUNT <= 8, "dolu_maske_ 8 bitlik: en fazla 8 raf desteklenir!");
	static_assert(BLOCK_SIZE % 8 == 0, "BLOCK_SIZE 8'in kati olmali: raflar hizasiz kalir!");
    next_free_ = storage_; // Zincirin basi ilk raf
    dolu_maske_ = 0;   // basta hicbir raf dolu degil
    dolu_sayisi_ = 0;
    tepe_sayisi_ = 0;

    // Son raf haric hepsinin icine, bir sonraki rafin adresini yazalim
    for (size_t i = 0; i < BLOCK_COUNT - 1; i++) {
        unsigned char* su_anki_raf = storage_ + (i * BLOCK_SIZE);
        unsigned char* sonraki_raf = storage_ + ((i + 1) * BLOCK_SIZE);

        // Su anki rafin bellekteki ilk byte'larini "adres tutan bir degisken" (pointer) olarak gor:
        unsigned char** raf_ici_not = reinterpret_cast<unsigned char**>(su_anki_raf);
        
        // O not kagidina, bir sonraki rafin adresini fiziksel olarak yaz:
        *raf_ici_not = sonraki_raf;
    }

    // Son rafin icine NULL yaziyoruz, cunku ondan sonra bos raf yok zincir bitiyor
    unsigned char* son_raf = storage_ + ((BLOCK_COUNT - 1) * BLOCK_SIZE);
    unsigned char** son_not = reinterpret_cast<unsigned char**>(son_raf);
    *son_not = NULL; 
}


bool MemoryPool::deallocate(unsigned char* p) {
    // 1. Donaným Güvenliði: Gelen adres gerçekten bizim fiziksel depomuzun sýnýrlarý içinde mi?
    if (p < storage_ || p >= storage_ + BLOCK_SIZE * BLOCK_COUNT) {
        return false;
    }

    // 2. Hizalama (Alignment) Kontrolü: Adres tam olarak bir rafýn baþlangýç noktasý mý?
    // Yanlýþlýkla rafýn ortasýndan bir adres verildiyse (pointer kaymasý), sistemi çökertmeden reddet.
    if ((p - storage_) % BLOCK_SIZE != 0) {
        return false;
    }
    
    size_t index = (p - storage_) / BLOCK_SIZE;
	if ((dolu_maske_ & (1 << index)) == 0) {   // bit zaten 0: raf zaten bos, cift iade
	    return false;
	}
	dolu_maske_ &= ~(1 << index);          // i. biti 0 yap: raf bos
	dolu_sayisi_--;

    // 3. Ýade edilen rafý, boþ listesinin en baþýna (LIFO/Stack mantýðý) baðla
    unsigned char** raf_ici_not = reinterpret_cast<unsigned char**>(p);
    *raf_ici_not = next_free_;

    // 4. Havuzun "ilk boþ raf" göstergesini, iade edilen bu yeni raf olarak güncelle
    next_free_ = p;

    return true;
}

unsigned char* MemoryPool::allocate() {
    // 1. Havuzda hic bos raf kalmadiysa NULL dondur (Out of Memory korumasi)
    if (next_free_ == NULL) {
        return NULL; 
    }

    // 2. Kullaniciya tahsis edecegimiz rafi kenara ayir
    unsigned char* verilecek_raf = next_free_;

    // 3. Bu rafin icindeki "notu" (siradaki bos rafin adresini) oku
    unsigned char** raf_ici_not = reinterpret_cast<unsigned char**>(verilecek_raf);
    
    // 4. Havuzun "ilk bos raf" gostergesini, okudugumuz bu yeni adrese kaydir
    next_free_ = *raf_ici_not;
    
    size_t index = (verilecek_raf - storage_) / BLOCK_SIZE;
	dolu_maske_ |= (1 << index);          // i. biti 1 yap: raf dolu
	dolu_sayisi_++;
	
	if (dolu_sayisi_ > tepe_sayisi_) {   // yeni rekor mu?
    	tepe_sayisi_ = dolu_sayisi_;
	}

    // 5. Adresi kullaniciya (oradaki nesneyi insa etmesi icin) teslim et
    return verilecek_raf;
}

size_t MemoryPool::kullanilan() const {
    return dolu_sayisi_;
}
size_t MemoryPool::tepe() const {
    return tepe_sayisi_;
}
