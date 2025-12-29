#include <stdio.h>

int main()
{
    int adet;
    int i;
    int sayi;
    int toplam = 0;

    printf("Kac adet sayi gireceksiniz? ");
    scanf("%d", &adet);

    if (adet <= 0)
    {
        printf("Hata: Sayi adedi sifirdan buyuk olmalidir!\n");
        return 1;
    }

    for (i = 0; i < adet; i++)
    {
        printf("%d. sayi girin: ", i + 1);
        scanf("%d", &sayi);
        toplam = toplam + sayi;
    }

    printf("Ortalama = %d\n", toplam / adet);

    return 0;
}
