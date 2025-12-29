#include <stdio.h>

int main()
{

    int yas;
    char cinsiyet;
    int secim;

    printf("Yasinizi giriniz: ");
    scanf("%d", &yas);

    printf("Cinsiyetinizi giriniz (E/K): ");
    scanf(" %c", &cinsiyet);

    printf("\n--- Girilen Bilgiler ---\n");
    printf("Yas: %d\n", yas);
    printf("Cinsiyet: %c\n\n", cinsiyet);

    while (1)
    {
        printf("Lutfen bir secenek seciniz:\n");
        printf("1 - Vucut Kitle Indeksi (VKI) Hesapla\n");
        printf("2 - Fahrenheit --> Celcius Donustur\n");
        printf("Seciminiz: ");
        scanf("%d", &secim);

        switch (secim)
        {

        case 1:

            float kilo, boy, vki;

            printf("Kilonuzu (kg) giriniz: ");
            scanf("%f", &kilo);

            printf("Boyunuzu metre cinsinden giriniz (Orn: 1.75): ");
            scanf("%f", &boy);

            if (kilo <= 0)
            {
                printf("Kilo sifir veya negatif olamaz!\n\n");
                break;
            }
            if (boy <= 0)
            {
                printf("Boy sifir veya negatif olamaz!\n\n");
                break;
            }

            vki = kilo / (boy * boy);
            printf("\nVucut Kitle Indeksiniz: %.2f\n", vki);

            if (vki < 18.5)
            {
                printf("Durum: Zayif\n");
            }

            else if (vki >= 18.5 && vki <= 24.9)
            {
                printf("Durum: Saglikli\n");
            }
            else if (vki >= 25)
            {
                printf("Durum: Hekime baEvurabilirsiniz.\n");
            }
            else
            {
                printf("Hata.\n");
            }

            break;

        case 2:

            float f, c;

            printf("Fahrenheit degerini giriniz: ");
            scanf("%f", &f);

            c = (f - 32) * 5.0 / 9.0;
            printf("\nCelcius: %.2f B0C\n", c);

            if (c <= 0)
                printf("Hava: Soguk\n");
            else if (c > 0 && c <= 10)
                printf("Hava: Serin / Hafif Soguk\n");
            else if (c >= 11 && c <= 20)
                printf("Hava: Ilik\n");
            else if (c >= 21 && c <= 30)
                printf("Hava: Sicak\n");
            else
                printf("Hava: Cok Sicak / Yakici\n");

            break;

        default:
            printf("Hatali secim yaptiniz! Lutfen tekrar deneyin.\n\n");
            break;
        }
    }

    return 0;
}
