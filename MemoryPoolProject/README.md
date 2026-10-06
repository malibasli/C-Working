# Fixed-Size Memory Pool Allocator

Gömülü sistemler için, heap kullanmayan, sabit boyutlu bloklardan oluşan bir C++ bellek havuzu.
`new` / `delete` mekanizmasının arka planını, pointer aritmetiğini ve bellek parçalanmasını (fragmentation) anlamak amacıyla sıfırdan yazılmıştır.

## Neden bu proje?

Genel amaçlı heap (`new` / `delete`) gömülü ve gerçek zamanlı sistemlerde iki sorun çıkarır:

- **Fragmentation:** Farklı boyutlarda tahsis ve iade sonrası toplam boş bellek yeterli olsa bile tek parça blok bulunamayabilir.
- **Belirsiz süre:** Tahsisin ne kadar süreceği önceden bilinemez, bu da deterministik davranış isteyen sistemler için sorundur.

Bu havuz belleği başta bir kez ayırır ve eşit boyutlu bloklara böler. Böylece:

- Fragmentation yapısal olarak oluşmaz (her boş blok her isteğe uyar).
- `allocate` / `deallocate` sabit zamanlıdır, O(1).
- Heap kullanılmaz, bellek miktarı derleme zamanında bellidir.

## Özellikler

- **Free list:** Boş bloklar kendi içlerinde "sıradaki boş blok" adresini taşır. Ek RAM harcanmaz, tarama döngüsü yoktur.
- **Güvenlik kontrolleri:** Havuz dışı adres, bloğun ortasından verilen adres, `NULL` ve çift iade (double free) reddedilir.
- **Bit maskesi:** Hangi bloğun dolu olduğu 1 byte'ta tutulur, çift iade bu sayede yakalanır.
- **`create<T>()` / `destroy<T>()`:** Havuzdan blok alıp üzerinde placement new ile nesne kurar; yıkıcıyı çağırıp bloğu iade eder.
- **Derleme zamanı kontrolleri (`static_assert`):** Bloğa sığmayan tip veya hatalı yapılandırma derlenmez.
- **Hizalama:** Depo `alignas(8)` ile hizalanır.
- **İstatistik:** Anlık kullanım sayacı ve tepe değeri (high-water mark) sunulur. Havuz boyutunu ölçmek için kullanılır.

## Dosya yapısı

| Dosya | Görev |
|---|---|
| `MemoryPool.h` | Sınıf bildirimi, `create<T>` / `destroy<T>` şablon gövdeleri |
| `MemoryPool.cpp` | Kurucu, `allocate`, `deallocate`, `kullanilan`, `tepe` gövdeleri |
| `main.cpp` | 11 testlik doğrulama programı |

## Derleme ve çalıştırma

C++11 gerekir (`static_assert`, `alignas`).

```bash
g++ -std=c++11 main.cpp MemoryPool.cpp -o pool_test
./pool_test
```

Dev-C++ kullanıyorsanız bir **proje** oluşturup üç dosyayı projeye ekleyin ve `Tools > Compiler Options > Settings > Code Generation > Language standard` ayarını `ISO C++11` yapın.

## Kullanım

```cpp
#include "MemoryPool.h"

struct Sensor {
    int id;
    float deger;
    float matris[6];   // 32 byte, bir bloğa tam sığar
};

int main() {
    MemoryPool pool;

    Sensor* s = pool.create<Sensor>();   // blok al + nesneyi kur
    if (s != NULL) {
        s->id = 7;
        s->deger = 36.6f;
    }
    pool.destroy(s);                     // yıkıcı + bloğu iade et

    return 0;
}
```

Ham bellek için doğrudan `allocate()` / `deallocate()` da kullanılabilir.

## Tasarım

- Depo: `8 blok x 32 byte = 256 byte`, tek bir statik diziden oluşur.
- Blok adresi: `storage_ + i * BLOCK_SIZE`
- Adresten blok numarası: `(adres - storage_) / BLOCK_SIZE`
- Boş bloklar tek yönlü bağlı liste oluşturur. `next_free_` her zaman ilk boş bloğu gösterir.
- `allocate`: `next_free_` bloğunu verir, işaretçiyi sıradaki boş bloğa kaydırır.
- `deallocate`: İade edilen bloğu listenin başına bağlar (LIFO). Bu yüzden iade edilen blok bir sonraki istekte ilk verilen bloktur.

## Testler

`main.cpp` içinde 11 test ve 28 kontrol bulunur:

| # | Test | Doğruladığı davranış |
|---|---|---|
| 1 | Başlangıç durumu | Sayaçlar sıfırdan başlar |
| 2 | create / destroy | Nesne kurulur, kullanılır, iade edilir |
| 3 | Blok geri dönüşümü | İade edilen blok yeniden verilir |
| 4 | Adres aralıkları | Ardışık bloklar arası tam 32 byte |
| 5 | Havuz dolu | 9. istek `NULL` döner, sayaç bozulmaz |
| 6 | Havuz dışı adres | Reddedilir |
| 7 | Bloğun ortası | `p + 5` reddedilir, blok dolu kalır |
| 8 | Çift iade | İkinci iade `false` döner, zincir bozulmaz |
| 9 | NULL destroy | Sessizce reddedilir |
| 10 | Hizalama | Tüm blok adresleri 8'in katı |
| 11 | Sayaç ve tepe | Kullanım düşer, tepe düşmez |

Beklenen son satır: `TUM TESTLER GECTI`

## Bilinen sınırlamalar

- Blok boyutu ve sayısı (`32 x 8`) şu an `MemoryPool.h` içinde sabittir.
- Bit maskesi 8 bitlik olduğu için en fazla 8 blok desteklenir (`static_assert` ile korunur).
- Thread-safe veya kesme (ISR) güvenli değildir. Kritik bölge koruması yoktur.
- `alignas(8)` ve blok içi pointer saklama, 64 bit hedef varsayar.

## Olası geliştirmeler

- `MemoryPool<BLOCK_SIZE, BLOCK_COUNT>` şablon parametreleri
- Daha büyük havuzlar için genişletilmiş bit haritası
- Kesme güvenliği için kritik bölge (mutex / interrupt disable)

## Öğrenme çıktıları

Bu proje ile şu konular uygulamalı olarak çalışıldı: pointer aritmetiği, `reinterpret_cast`, placement new ve nesne ömrü, free list, hizalama (alignment), `static_assert`, sınıf tasarımı ve `.h` / `.cpp` ayrımı.
