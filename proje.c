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
void dosyayaKaydet(struct Urun *liste, int boyut);
void yeniUrunEkle(struct Urun **liste, int *boyut);
int guvenliSayiAl();
float guvenliFloatAl();

int main() {
    // Ekrana yazdirma sorununu cozen satir
    setbuf(stdout, NULL); 

    struct Urun *stokListesi; 
    int urunSayisi;
    int secim, islemID, miktar;

    printf("--- AKILLI DEPO YONETIM SISTEMI ---\n");
    printf("Baslangic urun cesidi sayisi: ");
    urunSayisi = guvenliSayiAl();

    // Hafiza tahsisi (Malloc)
    stokListesi = (struct Urun*) malloc(urunSayisi * sizeof(struct Urun));

    if (stokListesi == NULL) {
        printf("Sistem hatasi: Bellek yetersiz!\n");
        return 1;
    }

    // Ilk veri girisi dongusu
    for (int i = 0; i < urunSayisi; i++) {
        stokListesi[i].id = i + 1;
        printf("\n--- %d. Urun Kaydi ---\n", i + 1);
        
        printf("Urun Adi: ");
        scanf("%s", stokListesi[i].ad);

        printf("Mevcut Stok: ");
        stokListesi[i].stokMiktari = guvenliSayiAl();

        printf("Kritik Seviye (Siparis Noktasi): ");
        stokListesi[i].kritikSeviye = guvenliSayiAl();

        printf("Birim Satis Fiyati: ");
        stokListesi[i].birimFiyat = guvenliFloatAl();

        printf("Birim Stok Tutma Maliyeti: ");
        stokListesi[i].birimStokTutmaMaliyeti = guvenliFloatAl();
    }

    // Ana Menu Dongusu
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
            case 1:
                urunleriListele(stokListesi, urunSayisi);
                break;

            case 2:
                rafGorsellestir(stokListesi, urunSayisi);
                break;

            case 3:
                printf("Islem yapilacak Urun ID: ");
                islemID = guvenliSayiAl();

                if (islemID >= 1 && islemID <= urunSayisi) {
                    printf("Miktar (Ekleme icin pozitif, Dusurme icin negatif): ");
                    miktar = guvenliSayiAl();
                    stokGuncelle(&stokListesi[islemID - 1].stokMiktari, miktar);
                } else {
                    printf("Hatali ID girisi!\n");
                }
                break;
            
            case 4:
                yeniUrunEkle(&stokListesi, &urunSayisi); 
                break;

            case 5:
                dosyayaKaydet(stokListesi, urunSayisi);
                free(stokListesi);
                printf("Sistemden cikis yapildi ve veriler kaydedildi.\n");
                return 0;

            default:
                printf("Gecersiz secim, tekrar deneyiniz.\n");
        }
    }
}

// --- YARDIMCI FONKSİYONLAR ---

int guvenliSayiAl() {
    int sayi;
    // Sayi girilene kadar dongude kalir
    while (scanf("%d", &sayi) != 1) {
        while(getchar() != '\n'); // Hatali girisi temizle
        printf("Hatali giris! Lutfen gecerli bir tam sayi giriniz: ");
    }
    return sayi;
}

float guvenliFloatAl() {
    float sayi;
    while (scanf("%f", &sayi) != 1) {
        while(getchar() != '\n');
        printf("Hatali giris! Lutfen gecerli bir sayi giriniz (Orn: 10.5): ");
    }
    return sayi;
}

void yeniUrunEkle(struct Urun **liste, int *boyut) {
    (*boyut)++;
    
    // Hafizayi genislet (Realloc)
    struct Urun *geciciListe = (struct Urun*) realloc(*liste, (*boyut) * sizeof(struct Urun));
    
    if (geciciListe != NULL) {
        *liste = geciciListe;
        
        int yeniIndex = *boyut - 1;
        (*liste)[yeniIndex].id = *boyut;
        
        printf("\n--- Yeni Urun Tanimlama ---\n");
        printf("Urun Adi: ");
        scanf("%s", (*liste)[yeniIndex].ad);
        
        printf("Baslangic Stogu: ");
        (*liste)[yeniIndex].stokMiktari = guvenliSayiAl();
        
        printf("Kritik Seviye: ");
        (*liste)[yeniIndex].kritikSeviye = guvenliSayiAl();
        
        printf("Birim Fiyat: ");
        (*liste)[yeniIndex].birimFiyat = guvenliFloatAl();
        
        printf("Stok Tutma Maliyeti: ");
        (*liste)[yeniIndex].birimStokTutmaMaliyeti = guvenliFloatAl();
        
        printf("Urun sisteme basariyla eklendi.\n");
    } else {
        printf("Sistem Hatasi: Bellek genisletilemedi!\n");
        (*boyut)--;
    }
}

void urunleriListele(struct Urun *liste, int boyut) {
    float toplamMaliyet = 0.0;
    printf("\n%-4s %-15s %-8s %-8s %-15s %-10s\n", "ID", "URUN", "STOK", "KRITIK", "TUTMA MAL.", "DURUM");
    printf("----------------------------------------------------------------------\n");

    for (int i = 0; i < boyut; i++) {
        float maliyet = liste[i].stokMiktari * liste[i].birimStokTutmaMaliyeti;
        printf("%-4d %-15s %-8d %-8d %-15.2f ", 
               liste[i].id, liste[i].ad, liste[i].stokMiktari, liste[i].kritikSeviye, maliyet);
        
        if (liste[i].stokMiktari <= liste[i].kritikSeviye) printf("SIPARIS VER!");
        else printf("Normal");
        
        printf("\n");
        toplamMaliyet += maliyet;
    }
    printf("----------------------------------------------------------------------\n");
    printf("TOPLAM STOK TUTMA MALIYETI: %.2f TL\n", toplamMaliyet);
}

void stokGuncelle(int *hedefStok, int degisim) {
    *hedefStok += degisim;
    printf("Stok guncellendi. Yeni miktar: %d\n", *hedefStok);
}

void rafGorsellestir(struct Urun *liste, int boyut) {
    int raf[5][5] = {0}; 
    int k = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (k < boyut) { raf[i][j] = liste[k].stokMiktari; k++; }
        }
    }
    printf("\n--- DEPO RAF DOLULUK PLANI ---\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if ((i * 5 + j) >= boyut) printf("[ -- ] ");
            else printf("[%04d] ", raf[i][j]);
        }
        printf("\n");
    }
}

void dosyayaKaydet(struct Urun *liste, int boyut) {
    FILE *dosya = fopen("DepoRaporu.txt", "w");
    if (dosya == NULL) { printf("Dosya hatasi!\n"); return; }
    
    fprintf(dosya, "--- GUN SONU DEPO RAPORU ---\n\n");
    for (int i = 0; i < boyut; i++) {
        float maliyet = liste[i].stokMiktari * liste[i].birimStokTutmaMaliyeti;
        fprintf(dosya, "ID: %d | Urun: %s | Stok: %d | Maliyet: %.2f TL\n",
                liste[i].id, liste[i].ad, liste[i].stokMiktari, maliyet);
    }
    fclose(dosya);
    printf("Rapor olusturuldu: 'DepoRaporu.txt'\n");
}