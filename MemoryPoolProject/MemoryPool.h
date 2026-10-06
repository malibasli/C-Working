#ifndef MEMORYPOOL_H        // "bu dosya daha once eklendiyse tekrar ekleme" korumasi
#define MEMORYPOOL_H

#include <cstddef> 
#include <new>    // placement new icin    

class MemoryPool {
public:
    MemoryPool();
    unsigned char* allocate();
    bool deallocate(unsigned char* p);
    size_t tepe() const;   // en yuksek dolu raf sayisi
    size_t kullanilan() const;   // kac raf dolu

    template <typename T>
	T* create();     // havuzdan raf al, uzerinde T insa et, T* dondur
	template <typename T>
    bool destroy(T* p);

private:
	static const size_t BLOCK_SIZE  = 32;
    static const size_t BLOCK_COUNT = 8;
    alignas(8) unsigned char storage_[BLOCK_SIZE * BLOCK_COUNT];   // baslangic adresi 8'in kati olsun
    unsigned char dolu_maske_;   // bit i = 1 ise i. raf dolu
    unsigned char* next_free_; // Sadece tek bir pointer: Her zaman siradaki ilk bos rafi gosterecek
    size_t dolu_sayisi_;   // su an kac raf kullanimda
    size_t tepe_sayisi_;   // ulasilan en yuksek dolu raf sayisi
};

template <typename T>
T* MemoryPool::create() {
    static_assert(sizeof(T) <= BLOCK_SIZE, "Tip rafa sigmiyor!");

    unsigned char* ham = allocate();
    if (ham == NULL) {	
        return NULL;
    }

    return new (ham) T;                 // placement new: T'yi 'ham' adresinde kur ve adresini dondur
}

template <typename T>
bool MemoryPool::destroy(T* p) {
    if (p == NULL) {
        return false;
    }

    p->~T();
    return deallocate(reinterpret_cast<unsigned char*>(p));
}

#endif
