🚛 OOP Tabanlı Modüler ECU Telemetri Simülasyonu
Ağır vasıtalar ve endüstriyel gömülü sistemler için C++ ile geliştirilmiş, Nesne Yönelimli Programlama (OOP) prensiplerini merkeze alan dinamik bir Elektronik Kontrol Ünitesi (ECU) telemetri altyapısı.

Bu proje, donanım-yazılım ortak tasarımı (Hardware/Software Co-Design) mantığıyla inşa edilmiş olup, karmaşık sensör ağlarını "Spagetti Kod" ve yüksek gecikme (latency) sorunlarından arındırarak profesyonel bir mimaride yönetmeyi hedefler.

🎯 Projenin Amacı
Gerçek dünya senaryolarında, araç üzerindeki her donanımın (şanzıman, turbo, fren balatası vb.) arıza karakteristiği farklıdır. Sıcaklık artış gösterdiğinde tehlikeliyken, basınç düştüğünde arıza kaydı oluşturur. Bu proje, metin (string) karşılaştırmalarının yarattığı işlemci yükünü ortadan kaldırarak; Kalıtım (Inheritance) ve Çok Biçimlilik (Polymorphism) mimarisiyle sensörlerin kendi arıza kurallarını dinamik olarak işlediği merkezi bir veri yolu (CAN Bus simülasyonu) sunar.

⚙️ Mimari ve OOP Yaklaşımı
Sistem, fiziksel donanımların yazılımsal karşılıklarını üretmek için gelişmiş C++ prensiplerini kullanır:

Kapsülleme (Encapsulation): Sensörlere ait eşik değerleri ve anlık veriler protected ve private erişim belirleyicileri ile dış müdahalelere kapatılmış, veri güvenliği sağlanmıştır.

Merkezi Bellek Yönetimi (Pointers & Vectors): Tüm sensörler TelemetriYoneticisi (ECU) sınıfı içindeki bir std::vector<Sensor*> veri yoluna (Bus) bellek adresleri (&) ile bağlanır. ECU donanımları kopyalamaz, RAM üzerindeki fiziksel adresleri üzerinden canlı tarama yapar.

Sanal Yönlendirme ve Kalıtım (Virtual & Override):

Ana Sensor kalıbı, virtual tehlikeSiniriAsildiMi() arayüzü ile genel bir haberleşme portu açar.

Türetilen SicaklikSensoru ve BasincSensoru sınıfları, bu kuralı override ederek kendi fiziksel doğalarına uygun algoritmaları (biri sınırın üstünde, diğeri altında arıza verecek şekilde) sisteme entegre eder.

🚀 Spagetti Kod vs. Modüler Polimorfizm
Yaklaşım	Çalışma Mantığı	Performans ve Ölçeklenebilirlik
Geleneksel (Hatalı) Yapı	Her döngüde if (isim == "Turbo Basinci") şeklinde harf harf string karşılaştırması yapılır.	Ağır işlemci yükü, yüksek gecikme (latency). Yeni donanım eklendiğinde ana çekirdek kodunun değiştirilmesi gerekir (Açık/Kapalı prensibi ihlali).
Bu Projedeki (OOP) Yapı	ECU karşısındaki donanımın tipini umursamaz. ->tehlikeSiniriAsildiMi() çağrısı dinamik bağlama ile doğrudan alt sınıfın özel kuralına yönlendirilir.	Sıfır metin karşılaştırması, anında reaksiyon. Ana koda dokunmadan sınırsız sayıda yeni sensör tipi eklenebilir.
💻 Konsol Çıktısı (Test Senaryosu)
Sistem, çalışma anında sensör verilerindeki değişimleri (örneğin basınç kaçağı) dinamik olarak yakalar ve polimorfizm sayesinde doğru arıza kuralını çalıştırır:

Plaintext
--- DURUM 1: HER SEY NORMAL ---
Sanziman Yag Sicakligi is normal.
Turbo Basinci is normal.

--- DURUM 2: BASINC KACAGI ---
Sanziman Yag Sicakligi is normal.
Kritik Ariza Turbo Basinci: 1.2
🛠️ Gelecek Geliştirmeler (Roadmap)
Bu modüler C++ iskeleti, doğrudan SoC ve donanım entegrasyonlarına hazır olarak tasarlanmıştır. Gelecek fazlarda sisteme eklenebilecek modüller:

Donanım Haberleşmesi (SoC/IP Core): Klavye girdileri yerine, Zynq/ARM mimarilerinde I2C, SPI protokolleri veya FPGA tabanlı LVDT/Resolver IP Core arayüzleri üzerinden gerçek donanım okumalarının entegrasyonu.

Veri Telemetrisi: C++ üzerinden üretilen arıza (DTC) ve anlık performans verilerinin Prometheus metriklerine dönüştürülerek Grafana üzerinde görselleştirilmesi.

Aktif Geri Besleme (PID): Sadece arıza tespiti değil, fan ve soğutma sistemlerini tetikleyecek kapalı çevrim kontrol mekanizmalarının sınıflara dahil edilmesi.

Geliştirici: Mehmet Ali Başlı
