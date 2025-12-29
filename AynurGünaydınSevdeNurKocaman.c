#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h> 

// YAPILAR
struct Urun {
    int id;
    char ad[50];
    int stokMiktari;
    int kritikSeviye;
    float birimFiyat;
    float birimStokTutmaMaliyeti;
};

// FONKSİYONLAR
void urunleriListele(struct Urun *liste, int boyut);
void stokGuncelle(int *hedefStok, int degisim);
void rafGorsellestir(struct Urun *liste, int boyut);
void veritabaniKaydet(struct Urun *liste, int boyut); // Bilgisayar icin (Save)
void raporOlustur(struct Urun *liste, int boyut);     // Bizim için
struct Urun* dosyadanYukle(int *boyut);               // Okuma (Load)
void yeniUrunEkle(struct Urun **liste, int *boyut);
int guvenliSayiAl();
float guvenliFloatAl();

int main() {
    setbuf(stdout, NULL); // Terminal cikti sorununu cozer

    struct Urun *stokListesi = NULL; 
    int urunSayisi = 0;
    int secim, islemID, miktar;

    printf("--- AKILLI DEPO YONETIM SISTEMI (v2.0) ---\n");

    // 1. ADIM: OTOMATİK VERİ YÜKLEME 
    // Program baslarken veritabani dosyasini kontrol et
    stokListesi = dosyadanYukle(&urunSayisi);

    if (stokListesi != NULL) {
        printf("--> Onceki oturumdan %d adet urun basariyla yuklendi.\n", urunSayisi);
    } else {
        printf("--> Kayitli veri bulunamadi. Sifirdan kurulum yapiliyor.\n");
        printf("Baslangic urun cesidi sayisi: ");
        urunSayisi = guvenliSayiAl();

        // Hafiza tahsisi (Malloc)
        stokListesi = (struct Urun*) malloc(urunSayisi * sizeof(struct Urun));
        if (stokListesi == NULL) { printf("Hafiza Hatasi!\n"); return 1; }

        // Ilk veri girisi
        for (int i = 0; i < urunSayisi; i++) {
            stokListesi[i].id = i + 1;
            printf("\n--- %d. Urun Kaydi ---\n", i + 1);
            printf("Urun Adi: "); scanf("%s", stokListesi[i].ad);
            printf("Mevcut Stok: "); stokListesi[i].stokMiktari = guvenliSayiAl();
            printf("Kritik Seviye: "); stokListesi[i].kritikSeviye = guvenliSayiAl();
            printf("Birim Fiyat: "); stokListesi[i].birimFiyat = guvenliFloatAl();
            printf("Birim Stok Tutma Maliyeti: "); stokListesi[i].birimStokTutmaMaliyeti = guvenliFloatAl();
        }
    }

    // 2. ADIM: ANA MENÜ 
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
                    printf("Miktar (Ekleme +, Azaltma -): "); miktar = guvenliSayiAl();
                    stokGuncelle(&stokListesi[islemID - 1].stokMiktari, miktar);
                } else printf("Hatali ID!\n");
                break;
            case 4: yeniUrunEkle(&stokListesi, &urunSayisi); break;
            case 5:
                // Hem bilgisayar icin kaydet hem rapor al
                veritabaniKaydet(stokListesi, urunSayisi); 
                raporOlustur(stokListesi, urunSayisi);     
                
                free(stokListesi); // Bellek temizligi
                printf("Program kapatildi. Veriler 'stok_data.txt'ye islendi.\n");
                printf("Detayli rapor 'DepoRaporu.txt' dosyasina eklendi.\n");
                return 0;
            default: printf("Gecersiz secim.\n");
        }
    }
}

// DOSYA YÖNETİM FONKSİYONLARI 

// YUKLEME (LOAD): Program acilisinda calisir
struct Urun* dosyadanYukle(int *boyut) {
    FILE *dosya = fopen("stok_data.txt", "r");
    if (dosya == NULL) return NULL; // Dosya yoksa NULL doner, main anlar

    fscanf(dosya, "%d", boyut); // Ilk satirda urun sayisi var

    struct Urun *liste = (struct Urun*) malloc(*boyut * sizeof(struct Urun));
    
    for (int i = 0; i < *boyut; i++) {
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

// VERITABANI KAYIT (SAVE): Bilgisayarin okuyacagi format
void veritabaniKaydet(struct Urun *liste, int boyut) {
    FILE *dosya = fopen("stok_data.txt", "w"); // "w" modunda acar, guncel hali yazar
    if (dosya == NULL) return;

    fprintf(dosya, "%d\n", boyut); // Basina kac urun oldugunu yaziyoruz

    for (int i = 0; i < boyut; i++) {
        fprintf(dosya, "%d %s %d %d %.2f %.2f\n", 
               liste[i].id, liste[i].ad, liste[i].stokMiktari, 
               liste[i].kritikSeviye, liste[i].birimFiyat, liste[i].birimStokTutmaMaliyeti);
    }
    fclose(dosya);
}

// RAPORLAMA (ARCHIVE): Insanin okuyacagi tarihli format
void raporOlustur(struct Urun *liste, int boyut) {
    FILE *dosya = fopen("DepoRaporu.txt", "a"); // "a" modunda acar, ekleme yapar
    if (dosya == NULL) return;
    
    // TARIH VE SAAT ALMA 
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    
    fprintf(dosya, "\n=======================================================\n");
    fprintf(dosya, "   RAPOR TARIHI: %02d.%02d.%04d  -  SAAT: %02d:%02d\n", 
            tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900, 
            tm->tm_hour, tm->tm_min);
    fprintf(dosya, "=======================================================\n");
    
    for (int i = 0; i < boyut; i++) {
        float maliyet = liste[i].stokMiktari * liste[i].birimStokTutmaMaliyeti;
        fprintf(dosya, "ID:%-3d | Urun:%-12s | Stok:%-5d | Deger:%-8.2f TL\n",
                liste[i].id, liste[i].ad, liste[i].stokMiktari, maliyet);
    }
    fprintf(dosya, "-------------------------------------------------------\n");
    fclose(dosya);
}

// YARDIMCI VE GUI FONKSİYONLARI 

int guvenliSayiAl() {
    int sayi;
    while (scanf("%d", &sayi) != 1) {
        while(getchar() != '\n');
        printf("Hatali giris! Lutfen tam sayi giriniz: ");
    }
    return sayi;
}

float guvenliFloatAl() {
    float sayi;
    while (scanf("%f", &sayi) != 1) {
        while(getchar() != '\n');
        printf("Hatali giris! Sayi giriniz (Orn: 10.5): ");
    }
    return sayi;
}

void yeniUrunEkle(struct Urun **liste, int *boyut) {
    (*boyut)++;
    // Realloc ile hafizayi genislet
    struct Urun *gecici = (struct Urun*) realloc(*liste, (*boyut) * sizeof(struct Urun));
    
    if (gecici != NULL) {
        *liste = gecici;
        int i = *boyut - 1;
        (*liste)[i].id = *boyut;
        
        printf("\n--- Yeni Urun Tanimlama ---\n");
        printf("Urun Adi: "); scanf("%s", (*liste)[i].ad);
        printf("Baslangic Stogu: "); (*liste)[i].stokMiktari = guvenliSayiAl();
        printf("Kritik Seviye: "); (*liste)[i].kritikSeviye = guvenliSayiAl();
        printf("Birim Fiyat: "); (*liste)[i].birimFiyat = guvenliFloatAl();
        printf("Stok Tutma Maliyeti: "); (*liste)[i].birimStokTutmaMaliyeti = guvenliFloatAl();
        printf("Urun basariyla eklendi.\n");
    } else {
        printf("Hafiza Dolu! Ekleme yapilamadi.\n"); (*boyut)--;
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
    printf("--------------------------------------\n");
    printf("TOPLAM STOK TUTMA MALIYETI: %.2f TL\n", topMal);
}

void stokGuncelle(int *hedefStok, int degisim) {
    *hedefStok += degisim;
    printf("Guncel stok: %d\n", *hedefStok);
}

void rafGorsellestir(struct Urun *liste, int boyut) {
    int raf[5][5] = {0};
    int k = 0;
    // Matris doldurma
    for(int i=0; i<5; i++) for(int j=0; j<5; j++) if(k<boyut) raf[i][j] = liste[k++].stokMiktari;
    
    printf("\n--- DEPO RAF PLANI ---\n");
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            if((i*5+j)>=boyut) printf("[ -- ] "); else printf("[%04d] ", raf[i][j]);
        }
        printf("\n");
    }
}