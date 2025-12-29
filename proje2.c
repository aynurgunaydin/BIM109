 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// --- YAPI TANIMLAMALARI ---
struct Urun {
    int id;
    char ad[50];
    int stokMiktari;
    int kritikSeviye;
    float birimFiyat;
    float birimStokTutmaMaliyeti;
};

// --- FONKSİYON PROTOTİPLERİ ---
void urunleriListele(struct Urun *liste, int boyut);
void stokGuncelle(int *hedefStok, int degisim);
void rafGorsellestir(struct Urun *liste, int boyut);
void veritabaniKaydet(struct Urun *liste, int boyut); // Bilgisayar icin kayit
void raporOlustur(struct Urun *liste, int boyut);     // Insan icin rapor
struct Urun* dosyadanYukle(int *boyut);               // Okuma Fonksiyonu
void yeniUrunEkle(struct Urun **liste, int *boyut);
int guvenliSayiAl();
float guvenliFloatAl();

int main() {
    setbuf(stdout, NULL); 

    struct Urun *stokListesi = NULL; 
    int urunSayisi = 0;
    int secim, islemID, miktar;

    printf("--- AKILLI DEPO YONETIM SISTEMI ---\n");

    // --- OTOMATİK YÜKLEME KISMI ---
    // Program baslarken dosyadan verileri cekmeye calisiyoruz
    stokListesi = dosyadanYukle(&urunSayisi);

    if (stokListesi != NULL) {
        printf("--> Onceki veritabanindan %d adet urun yuklendi.\n", urunSayisi);
    } else {
        printf("--> Kayitli veri bulunamadi. Sifirdan baslatiliyor.\n");
        printf("Baslangic urun cesidi sayisi: ");
        urunSayisi = guvenliSayiAl();

        stokListesi = (struct Urun*) malloc(urunSayisi * sizeof(struct Urun));
        if (stokListesi == NULL) { printf("Hafiza Hatasi!\n"); return 1; }

        for (int i = 0; i < urunSayisi; i++) {
            stokListesi[i].id = i + 1;
            printf("\n--- %d. Urun Kaydi ---\n", i + 1);
            printf("Urun Adi: "); scanf("%s", stokListesi[i].ad);
            printf("Mevcut Stok: "); stokListesi[i].stokMiktari = guvenliSayiAl();
            printf("Kritik Seviye: "); stokListesi[i].kritikSeviye = guvenliSayiAl();
            printf("Birim Fiyat: "); stokListesi[i].birimFiyat = guvenliFloatAl();
            printf("Tutma Maliyeti: "); stokListesi[i].birimStokTutmaMaliyeti = guvenliFloatAl();
        }
    }

    // --- ANA MENÜ ---
    while (1) {
        printf("\n\n--- ANA MENU ---\n");
        printf("1. Stok Durumu ve Maliyet Raporu\n");
        printf("2. Depo Raf Plani\n");
        printf("3. Stok Giris / Cikis Islemleri\n");
        printf("4. Yeni Urun Tanimla\n");
        printf("5. Kaydet ve Cikis\n");
        printf("Seciminiz: ");
        secim = guvenliSayiAl();

        switch (secim) {
            case 1: urunleriListele(stokListesi, urunSayisi); break;
            case 2: rafGorsellestir(stokListesi, urunSayisi); break;
            case 3:
                printf("Islem yapilacak Urun ID: ");
                islemID = guvenliSayiAl();
                if (islemID >= 1 && islemID <= urunSayisi) {
                    printf("Miktar (+/-): "); miktar = guvenliSayiAl();
                    stokGuncelle(&stokListesi[islemID - 1].stokMiktari, miktar);
                } else printf("Hatali ID!\n");
                break;
            case 4: yeniUrunEkle(&stokListesi, &urunSayisi); break;
            case 5:
                veritabaniKaydet(stokListesi, urunSayisi); // Verileri sakla
                raporOlustur(stokListesi, urunSayisi);     // Raporu arsivle
                free(stokListesi);
                printf("Program kapatildi. Veriler 'stok_data.txt'ye kaydedildi.\n");
                return 0;
            default: printf("Gecersiz secim.\n");
        }
    }
}

// --- DOSYA OKUMA VE YAZMA FONKSİYONLARI ---

// 1. OKUMA FONKSİYONU (LOAD)
struct Urun* dosyadanYukle(int *boyut) {
    FILE *dosya = fopen("stok_data.txt", "r");
    if (dosya == NULL) return NULL; // Dosya yoksa NULL doner

    // Dosyanin ilk satirinda kac urun oldugu yazar
    fscanf(dosya, "%d", boyut);

    struct Urun *liste = (struct Urun*) malloc(*boyut * sizeof(struct Urun));
    
    for (int i = 0; i < *boyut; i++) {
        // Sirayla: ID, Ad, Stok, Kritik, Fiyat, Maliyet okur
        fscanf(dosya, "%d %s %d %d %f %f", 
               &liste[i].id, 
               liste[i].ad, 
               &liste[i].stokMiktari, 
               &liste[i].kritikSeviye, 
               &liste[i].birimFiyat, 
               &liste[i].birimStokTutmaMaliyeti);
    }
    fclose(dosya);
    return liste;
}

// 2. KAYDETME FONKSİYONU (SAVE - Bilgisayar İçin)
void veritabaniKaydet(struct Urun *liste, int boyut) {
    FILE *dosya = fopen("stok_data.txt", "w"); // "w" ile ustune yazar (Guncel halini tutar)
    if (dosya == NULL) return;

    // İlk satira toplam urun sayisini yaziyoruz ki okurken bilelim
    fprintf(dosya, "%d\n", boyut);

    for (int i = 0; i < boyut; i++) {
        // Verileri bosluklarla ayirarak saf formatta yaziyoruz
        fprintf(dosya, "%d %s %d %d %.2f %.2f\n", 
               liste[i].id, 
               liste[i].ad, 
               liste[i].stokMiktari, 
               liste[i].kritikSeviye, 
               liste[i].birimFiyat, 
               liste[i].birimStokTutmaMaliyeti);
    }
    fclose(dosya);
}

// 3. RAPORLAMA FONKSİYONU (ARCHIVE - İnsan İçin)
void raporOlustur(struct Urun *liste, int boyut) {
    FILE *dosya = fopen("DepoRaporu.txt", "a"); // "a" append modu (arsivleme)
    if (dosya == NULL) return;
    
    fprintf(dosya, "\n=== TARIHLI RAPOR KAYDI ===\n");
    for (int i = 0; i < boyut; i++) {
        float maliyet = liste[i].stokMiktari * liste[i].birimStokTutmaMaliyeti;
        fprintf(dosya, "ID:%d | Urun:%s | Stok:%d | Deger:%.2f TL\n",
                liste[i].id, liste[i].ad, liste[i].stokMiktari, maliyet);
    }
    fprintf(dosya, "===========================\n");
    fclose(dosya);
}

// --- DİĞER YARDIMCI FONKSİYONLAR ---

int guvenliSayiAl() {
    int sayi;
    while (scanf("%d", &sayi) != 1) {
        while(getchar() != '\n');
        printf("Hatali giris! Sayi giriniz: ");
    }
    return sayi;
}

float guvenliFloatAl() {
    float sayi;
    while (scanf("%f", &sayi) != 1) {
        while(getchar() != '\n');
        printf("Hatali giris! Sayi giriniz: ");
    }
    return sayi;
}

void yeniUrunEkle(struct Urun **liste, int *boyut) {
    (*boyut)++;
    struct Urun *gecici = (struct Urun*) realloc(*liste, (*boyut) * sizeof(struct Urun));
    if (gecici != NULL) {
        *liste = gecici;
        int i = *boyut - 1;
        (*liste)[i].id = *boyut;
        printf("\n--- Yeni Urun ---\n");
        printf("Ad: "); scanf("%s", (*liste)[i].ad);
        printf("Stok: "); (*liste)[i].stokMiktari = guvenliSayiAl();
        printf("Kritik: "); (*liste)[i].kritikSeviye = guvenliSayiAl();
        printf("Fiyat: "); (*liste)[i].birimFiyat = guvenliFloatAl();
        printf("Maliyet: "); (*liste)[i].birimStokTutmaMaliyeti = guvenliFloatAl();
        printf("Eklendi.\n");
    } else {
        printf("Hafiza Dolu!\n"); (*boyut)--;
    }
}

void urunleriListele(struct Urun *liste, int boyut) {
    float topMal = 0.0;
    printf("\n%-4s %-15s %-8s %-10s\n", "ID", "URUN", "STOK", "DURUM");
    printf("--------------------------------------\n");
    for (int i = 0; i < boyut; i++) {
        float m = liste[i].stokMiktari * liste[i].birimStokTutmaMaliyeti;
        printf("%-4d %-15s %-8d ", liste[i].id, liste[i].ad, liste[i].stokMiktari);
        if (liste[i].stokMiktari <= liste[i].kritikSeviye) printf("SIPARIS!"); else printf("Normal");
        printf("\n");
        topMal += m;
    }
    printf("TOPLAM STOK TUTMA MALIYETI: %.2f TL\n", topMal);
}

void stokGuncelle(int *hedefStok, int degisim) {
    *hedefStok += degisim;
    printf("Yeni stok: %d\n", *hedefStok);
}

void rafGorsellestir(struct Urun *liste, int boyut) {
    int raf[5][5] = {0};
    int k = 0;
    for(int i=0; i<5; i++) for(int j=0; j<5; j++) if(k<boyut) raf[i][j] = liste[k++].stokMiktari;
    
    printf("\n--- RAF DUZENI ---\n");
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            if((i*5+j)>=boyut) printf("[ -- ] "); else printf("[%04d] ", raf[i][j]);
        }
        printf("\n");
    }
}