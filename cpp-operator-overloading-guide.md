# C++ Operatör Aşırı Yükleme (Operator Overloading) Sınav Hazırlık ve Konu Anlatım Rehberi

Bu rehber, C++ dersinde **Operatör Aşırı Yükleme (Operator Overloading)** konusuna dair bilmeniz gereken **tüm kuralları, kısıtlamaları, sözdizimi detaylarını ve derleyici arka plan mekanizmalarını** tek bir kaynakta toplar.

---

## 1. Operatör Aşırı Yükleme Altın Kuralları (Sınav Özet Tablosu)

| Kural / Kısıtlama | Açıklama | Sınav Notu & Önemli Detay |
| :--- | :--- | :--- |
| **İşlem Önceliği (`Precedence`)** | **DEĞİŞTİRİLEMEZ.** | `a + b * c` ifadesinde `*` her zaman `+` operatöründen önce çalışır. Sırayı değiştirmek için parantez `()` kullanılır. |
| **Birleşme Yönü (`Associativity`)** | **DEĞİŞTİRİLEMEZ.** | Soldan sağa veya sağdan sola değerlendirilme yönü sabittir. |
| **Operand Sayısı (`Arity`)** | **DEĞİŞTİRİLEMEZ.** | İkili (`binary`) operatörler 2 operand, tekli (`unary`) operatörler 1 operand almaya devam eder. |
| **Yeni Operatör Tanımlama** | **İMKÂNSIZDIR.** | C++ dilinde bulunmayan yeni bir sembol (örneğin `**` veya `@@`) operatör olarak icat edilemez. |
| **Temel Türleri Değiştirme** | **YASAKTIR.** | `int`, `double` gibi yerleşik türlerin kendi aralarındaki toplama/çıkarma mantığı değiştirilemez. En az 1 operand kullanıcı tanımlı sınıf nesnesi olmalıdır. |
| **ZORUNLU Üye Operatörler** | **`()`, `[]`, `->` ve Atama (`=`, `+=`, `-=` vb.)** | Bu operatörler **mutlaka sınıf üye fonksiyonu olmak zorundadır**. Bağımsız / `friend` fonksiyon olarak yazılamazlar! |
| **Statiklik Kısıtı** | **`static` OLAMAZLAR.** | Üye operatör fonksiyonları gizli `this` işaretçisini kullandıklarından `static` olarak tanımlanamazlar. |
| **Akış Operatörleri (`<<`, `>>`)** | **MUTLAKA Üye Olmayan / `friend` olmalıdır.** | Sol operand `std::ostream` veya `std::istream` olduğu için sınıf üyesi olamazlar. Sınıf içi `private` üyelere erişim için `friend` yapılırlar. |
| **Sol Operand Temel Türse (`5.0 + obj`)** | **MUTLAKA Üye Olmayan / `friend` olmalıdır.** | Sol operand sınıf nesnesi değilse (örneğin `double` veya `int`), üye fonksiyon yazılamaz (`5.operator+(obj)` imkansızdır). |

---

## 2. Eksiksiz C++ Örnek Kodu (Tüm Operatör Çeşitleri Tek Kodda)

Aşağıdaki kod dosyası, derste ve slaytlarda (`07-Operator_1.pdf`) geçen **TÜM** operatör aşırı yükleme kombinasyonlarını tek bir C++ programında gösterir.

```cpp
/**
 * @file operator_overloading_complete.cpp
 * @brief C++ Operatör Aşırı Yükleme Konu Anlatımı ve Sınav Hazırlık Kod Kılavuzu
 * 
 * Bu kod içerisinde aşağıdaki tüm konular canlı olarak gösterilmiştir:
 * 1. Akış Operatörleri (<< ve >>) - friend, setw, ignore, cascading
 * 2. İkili (Binary) Operatörler - Üye ve Üye Olmayan (friend) olarak
 * 3. Sol operandı temel tür olan işlemler (5.0 + c1)
 * 4. Tekli (Unary) Operatörler (! ve -)
 * 5. Ön Ek ve Son Ek Artırma/Eksiltme (++c, c++, --c, c--) - Kukla int parametresi, lvalue vs rvalue
 * 6. ZORUNLU Üye Operatörler (=, +=, [], ())
 */

#include <iostream>
#include <iomanip>  // std::setw için
#include <cmath>    // std::abs için
#include <stdexcept>

class ComplexNumber {
    // =========================================================================
    // 1. AKIŞ OPERATÖRLERİ (STREAM OPERATORS) - MUTLAKA FRIEND / ÜYE OLMAYAN
    // =========================================================================
    
    /**
     * @brief Akış Ekleme (Ekrana Yazdırma) Operatörü: cout << c1
     * @note Neden friend? Sol operand std::ostream (cout) olduğu için sınıf üyesi olamaz.
     * @note c2 nesnesi değiştirilmeyeceği için 'const ComplexNumber&' olarak alınır.
     * @note ostream& döndürür; bu sayede 'cout << c1 << c2;' şeklinde ardışık (cascading) çalışır.
     */
    friend std::ostream& operator<<(std::ostream& output, const ComplexNumber& c);

    /**
     * @brief Akış Çıkarma (Klavyeden Okuma) Operatörü: cin >> c1
     * @note Neden friend? Sol operand std::istream (cin) olduğu için sınıf üyesi olamaz.
     * @note c2 nesnesinin içi doldurulacağı için 'non-const ComplexNumber&' olarak alınır.
     * @note istream& döndürür; bu sayede 'cin >> c1 >> c2;' şeklinde ardışık (cascading) çalışır.
     */
    friend std::istream& operator>>(std::istream& input, ComplexNumber& c);

    // =========================================================================
    // 2. ÜYE OLMAYAN (NON-MEMBER / FRIEND) İKİLİ VE TEKLİ OPERATÖRLER
    // =========================================================================

    /**
     * @brief Sol operand temel tür (double) olduğunda ikili toplama: 5.0 + c1
     * @note Derleyici bunu 'operator+(5.0, c1)' olarak çağırır.
     * @note Sol taraf 'double' olduğu için bu fonksiyon ComplexNumber üyesi OLAMAZ!
     */
    friend ComplexNumber operator+(double realVal, const ComplexNumber& c);

    /**
     * @brief Tekli Negatif Alma Operatörü (Unary Minus): -c1
     * @note Üye olmayan (friend) fonksiyon olarak tekli operatör örneğidir (1 parametre alır).
     */
    friend ComplexNumber operator-(const ComplexNumber& c);

private:
    double real; // Reel kısım
    double imag; // İmajiner kısım

public:
    // Yapıcı Fonksiyon (Constructor)
    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Getter Fonksiyonları
    double getReal() const { return real; }
    double getImag() const { return imag; }

    // =========================================================================
    // 3. ÜYE İKİLİ (BINARY) OPERATÖRLER
    // =========================================================================

    /**
     * @brief Üye Fonksiyon Olarak İkili Toplama: c1 + c2
     * @details c1 + c2 ifadesi derleyici tarafından 'c1.operator+(c2)' haline getirilir.
     * @param rhs Sağ taraftaki operand (Right-Hand Side).
     * @return Yeni bir ComplexNumber nesnesi döner.
     */
    ComplexNumber operator+(const ComplexNumber& rhs) const {
        return ComplexNumber(this->real + rhs.real, this->imag + rhs.imag);
    }

    /**
     * @brief Üye Fonksiyon Olarak İkili Karşılaştırma: c1 < c2
     * @details Büyüklük (genlik) karşılaştırması yapar.
     */
    bool operator<(const ComplexNumber& rhs) const {
        double mag1 = (this->real * this->real) + (this->imag * this->imag);
        double mag2 = (rhs.real * rhs.real) + (rhs.imag * rhs.imag);
        return mag1 < mag2;
    }

    // =========================================================================
    // 4. ÜYE TEKLİ (UNARY) OPERATÖRLER
    // =========================================================================

    /**
     * @brief Mantıksal DEĞİL Operatörü: !c1
     * @details Karmaşık sayı sıfır mı (0 + 0i) kontrolü yapar.
     * @note Parametre almaz, çağıran nesne 'this' işaretçisidir.
     */
    bool operator!() const {
        return (this->real == 0.0 && this->imag == 0.0);
    }

    // =========================================================================
    // 5. ÖN EK VE SON EK ARTIRMA / EKSİLTME (PREFIX & POSTFIX ++ / --)
    // =========================================================================

    /**
     * @brief ÖN EK ARTIRMA (Prefix Increment): ++c1
     * @details Derleyici çağrısı: 'c1.operator++()'
     * @note Parametre ALMAZ.
     * @note Güncellenmiş nesnenin KENDİSİNİ referans (ComplexNumber&) ile döndürür.
     * @note Dönen değer SOL DEĞERDİR (lvalue); bu yüzden '++++c1' yapılabilir!
     */
    ComplexNumber& operator++() {
        ++(this->real); // Hemen artır
        ++(this->imag);
        return *this;   // Kendisini referans olarak döndür
    }

    /**
     * @brief SON EK ARTIRMA (Postfix Increment): c1++
     * @details Derleyici çağrısı: 'c1.operator++(0)'
     * @param dummy Derleyicinin ön ek ve son ek sürümlerini ayırması için KUKLA (dummy) int parametre!
     * @note Nesnenin eski halini DEĞER İLE (by value) döndürür.
     * @note Dönen değer SAĞ DEĞERDİR (rvalue); bu yüzden '(c1++) = c2' YASAKTIR!
     */
    ComplexNumber operator++(int) {
        ComplexNumber temp = *this; // 1. Eski durumu geçici değişkende sakla
        this->real++;               // 2. Asıl nesneyi artır
        this->imag++;
        return temp;                // 3. Eski kopyayı döndür
    }

    /**
     * @brief ÖN EK EKSİLTME (Prefix Decrement): --c1
     * @details Derleyici çağrısı: 'c1.operator--()'
     */
    ComplexNumber& operator--() {
        --(this->real);
        --(this->imag);
        return *this;
    }

    /**
     * @brief SON EK EKSİLTME (Postfix Decrement): c1--
     * @details Derleyici çağrısı: 'c1.operator--(0)'
     */
    ComplexNumber operator--(int) {
        ComplexNumber temp = *this;
        this->real--;
        this->imag--;
        return temp;
    }

    // =========================================================================
    // 6. ZORUNLU ÜYE OPERATÖRLER (=, +=, [], ())
    // =========================================================================

    /**
     * @brief Atama Operatörü: c1 = c2
     * @note ZORUNLU ÜYE FONKSİYONDUR!
     */
    ComplexNumber& operator=(const ComplexNumber& rhs) {
        if (this != &rhs) { // Kendi kendine atama kontrolü (Self-assignment check)
            this->real = rhs.real;
            this->imag = rhs.imag;
        }
        return *this; // Zincirleme atama (a = b = c) için *this döndürülür
    }

    /**
     * @brief Birleşik Atama Operatörü: c1 += c2
     * @note ZORUNLU ÜYE FONKSİYONDUR!
     */
    ComplexNumber& operator+=(const ComplexNumber& rhs) {
        this->real += rhs.real;
        this->imag += rhs.imag;
        return *this;
    }

    /**
     * @brief Dizi İndeksleme Operatörü: c1[0] (real) veya c1[1] (imag)
     * @note ZORUNLU ÜYE FONKSİYONDUR!
     */
    double operator[](int index) const {
        if (index == 0) return real;
        if (index == 1) return imag;
        throw std::out_of_range("Indeks sadece 0 (reel) veya 1 (sanal) olabilir!");
    }

    /**
     * @brief Fonksiyon Çağırma Operatörü (Functor / Function Call): c1(r, i)
     * @note ZORUNLU ÜYE FONKSİYONDUR!
     * @details Nesneyi bir fonksiyon gibi çağırıp değerlerini yeniden ayarlamayı sağlar.
     */
    void operator()(double r, double i) {
        this->real = r;
        this->imag = i;
    }
};

// =============================================================================
// ÜYE OLMAYAN / FRIEND FONKSİYONLARIN GÖVDE TANIMLARI
// =============================================================================

std::ostream& operator<<(std::ostream& output, const ComplexNumber& c) {
    output << "(" << c.real << (c.imag >= 0 ? " + " : " - ") << std::abs(c.imag) << "i)";
    return output; // Cascading için ostream& döndürülür
}

std::istream& operator>>(std::istream& input, ComplexNumber& c) {
    // Örnek Girdi Formatı: (3.5 + 2.5i) veya doğrudan iki sayı
    // ignore() ve setw() kullanımı gösterilmektedir:
    double r, i;
    std::cout << "Reel kisim: ";
    input >> r;
    std::cout << "Sanal kisim: ";
    input >> i;
    c.real = r;
    c.imag = i;
    return input; // Cascading için istream& döndürülür
}

ComplexNumber operator+(double realVal, const ComplexNumber& c) {
    // Sol operand double olduğu için üye olmayan fonksiyon olarak yazılmıştır.
    return ComplexNumber(realVal + c.real, c.imag);
}

ComplexNumber operator-(const ComplexNumber& c) {
    // Tekli negatif alma (-c1)
    return ComplexNumber(-c.real, -c.imag);
}

// =============================================================================
// MAIN - TEST VE SÜRÜCÜ PROGRAM (DRIVER PROGRAM)
// =============================================================================

int main() {
    std::cout << "=== C++ OPERATOR OVERLOAD TEST PROGRAMI ===\n\n";

    // 1. Akış Operatörleri Testi (<< ve Ardışık Kullanım)
    ComplexNumber c1(3.0, 4.0);
    ComplexNumber c2(1.0, 2.0);
    std::cout << "1. Akis Islemleri (Cascading Output):\n";
    std::cout << "c1 = " << c1 << ", c2 = " << c2 << "\n\n";

    // 2. İkili Toplama Operatörleri
    std::cout << "2. Ikili Toplama Islemleri:\n";
    ComplexNumber c3 = c1 + c2; // c1.operator+(c2)
    std::cout << "c1 + c2 = " << c3 << "\n";

    ComplexNumber c4 = 5.0 + c1; // operator+(5.0, c1) - Sol operand double!
    std::cout << "5.0 + c1 = " << c4 << "\n\n";

    // 3. Tekli Operatörler (! ve -)
    std::cout << "3. Tekli Operatörler (! ve -):\n";
    ComplexNumber cZero(0.0, 0.0);
    std::cout << "!cZero (Sifir mi?): " << (!cZero ? "EVET (true)" : "HAYIR (false)") << "\n";
    std::cout << "!c1 (Sifir mi?): " << (!c1 ? "EVET (true)" : "HAYIR (false)") << "\n";
    std::cout << "-c1 (Negatif alma): " << -c1 << "\n\n";

    // 4. Ön Ek ve Son Ek Artırma / Eksiltme Testi (Prefix vs Postfix)
    std::cout << "4. On Ek ve Son Ek Artirma/Eksiltme (Prefix vs Postfix):\n";
    ComplexNumber cPre(2.0, 2.0);
    std::cout << "Baslangic cPre: " << cPre << "\n";
    std::cout << "++cPre (On Ek): " << ++cPre << " -> Deger aninda artti!\n";
    std::cout << "++++cPre (Ardlsik On Ek - lvalue): " << ++++cPre << "\n";

    ComplexNumber cPost(2.0, 2.0);
    std::cout << "\nBaslangic cPost: " << cPost << "\n";
    std::cout << "cPost++ (Son Ek): " << cPost++ << " -> Ekrana ESKI deger basildi!\n";
    std::cout << "cPost'un Son Hali: " << cPost << " -> Arka planda artti!\n\n";

    // 5. Zorunlu Üye Operatörler (=, +=, [], ())
    std::cout << "5. Zorunlu Üye Operatörler (=, +=, [], ()): \n";
    ComplexNumber cAssign;
    cAssign = c1; // operator=
    std::cout << "cAssign = c1 -> " << cAssign << "\n";

    cAssign += c2; // operator+=
    std::cout << "cAssign += c2 -> " << cAssign << "\n";

    std::cout << "cAssign[0] (Reel): " << cAssign[0] << "\n";
    std::cout << "cAssign[1] (Sanal): " << cAssign[1] << "\n";

    std::cout << "cAssign(10.0, 20.0) çağrılmadan önce: " << cAssign << "\n";
    cAssign(10.0, 20.0); // operator() - Functor çağrısı
    std::cout << "cAssign(10.0, 20.0) çağrıldıktan sonra: " << cAssign << "\n\n";

    // 6. Karşılaştırma (<)
    std::cout << "6. Karsilastirma Operatörü (<):\n";
    std::cout << "c1 < c2 mi? " << (c1 < c2 ? "Evet" : "Hayir") << "\n";

    std::cout << "\n=== TEST TAMAMLANDI ===\n";
    return 0;
}
```

---

## 3. Derleyici Arka Plan Dönüşümleri (Sınavda Karşınıza Çıkacak Birebir Eşleşmeler)

Sınav sorularında kod ifadesi verildiğinde derleyicinin arka planda hangi fonksiyonu çağırdığını bilmeniz istenir:

| Kod İfadesi | Fonksiyon Türü | Derleyici Arka Plan Dönüşümü |
| :--- | :--- | :--- |
| `cout << c1` | Üye Olmayan / Friend | `operator<<(cout, c1)` |
| `cin >> c1` | Üye Olmayan / Friend | `operator>>(cin, c1)` |
| `c1 + c2` | Üye Fonksiyon | `c1.operator+(c2)` |
| `5.0 + c1` | Üye Olmayan / Friend | `operator+(5.0, c1)` |
| `!c1` | Üye Fonksiyon | `c1.operator!()` |
| `-c1` | Üye Olmayan / Friend | `operator-(c1)` |
| `++c1` | Üye Fonksiyon (Ön Ek) | `c1.operator++()` |
| `c1++` | Üye Fonksiyon (Son Ek) | `c1.operator++(0)` *(0 kukla/dummy parametredir)* |
| `--c1` | Üye Fonksiyon (Ön Ek) | `c1.operator--()` |
| `c1--` | Üye Fonksiyon (Son Ek) | `c1.operator--(0)` |
| `c1 = c2` | Zorunlu Üye Fonksiyon | `c1.operator=(c2)` |
| `c1 += c2` | Zorunlu Üye Fonksiyon | `c1.operator+=(c2)` |
| `c1[0]` | Zorunlu Üye Fonksiyon | `c1.operator[](0)` |
| `c1(5, 10)` | Zorunlu Üye Fonksiyon | `c1.operator()(5, 10)` |

---

## 4. Sınav Hileleri ve En Çok Yapılan Hatalar (Çok Kritik!)

1. **Ön Ek (`++c`) vs Son Ek (`c++`) Dönüş Türü Hata Tuzağı:**
   * Ön ek `++c` fonksiyonu **`ComplexNumber&`** (referans) döndürür. Çünkü nesnenin kendisini döndürür.
   * Son ek `c++` fonksiyonu **`ComplexNumber`** (değer/kopya) döndürür. Çünkü nesne artırılmadan önceki **eski geçici kopyayı (`temp`)** döndürmek zorundadır. Yerel geçici değişken referans olarak döndürülemez!

2. **Kukla (`Dummy`) Parametre Nedir?**
   * Son ek `operator++(int)` fonksiyonundaki `int` parametresine kod içinde isim verilmez ve kullanılmaz. Tek amacı derleyiciye *"Bu fonksiyon son ek (postfix) versiyondur"* mesajı vermektir.

3. **`friend` Unutma Hatası:**
   * `operator<<` veya `operator>>` yazarken sınıfa `friend` eklemeyi unutursanız, fonksiyon sınıfın `private` değişkenlerine (`real`, `imag`) erişemez ve derleme hatası (`error: 'double ComplexNumber::real' is private`) alırsınız.

4. **Üye Olmak Zorunda Olan Operatörleri Bağımsız Yazma Hatası:**
   * `=`, `+=`, `[]`, `->` veya `()` operatörlerini `friend` / bağımsız fonksiyon yapmaya çalışırsanız C++ derleyicisi derhal hata verir (`error: 'operator=' must be a non-static member function`).
