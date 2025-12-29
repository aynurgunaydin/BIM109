#include <stdio.h>

int toplam(int dizi[], int n)
{
    int t = 0;
    for (int i = 0; i < n; i++)
        t += dizi[i];
    return t;
}

float ortalama(int dizi[], int n)
{
    return (float)toplam(dizi, n) / n;
}

int max(int dizi[], int n)
{
    int m = dizi[0];
    for (int i = 1; i < n; i++)
        if (dizi[i] > m)
            m = dizi[i];
    return m;
}

int min(int dizi[], int n)
{
    int m = dizi[0];
    for (int i = 1; i < n; i++)
        if (dizi[i] < m)
            m = dizi[i];
    return m;
}

int mod(int dizi[], int n)
{
    int enCokSayi = dizi[0];
    int enCok = 1;

    for (int i = 0; i < n; i++)
    {
        int sayac = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (dizi[i] == dizi[j])
                sayac++;
        }
        if (sayac > enCok)
        {
            enCok = sayac;
            enCokSayi = dizi[i];
        }
    }
    return enCokSayi;
}

void sirala(int dizi[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (dizi[j] > dizi[j + 1])
            {
                int temp = dizi[j];
                dizi[j] = dizi[j + 1];
                dizi[j + 1] = temp;
            }
}

float medyan(int dizi[], int n)
{
    int temp[n];
    for (int i = 0; i < n; i++)
        temp[i] = dizi[i];

    sirala(temp, n);

    if (n % 2 == 1)
        return temp[n / 2];
    else
        return (temp[n / 2 - 1] + temp[n / 2]) / 2.0;
}

int main()
{
    int n;

    printf("Kac adet sayi gireceksiniz: ");
    scanf("%d", &n);

    int dizi[n];

    for (int i = 0; i < n; i++)
    {
        printf("%d. sayiyi girin: ", i + 1);
        scanf("%d", &dizi[i]);
    }

    printf("\nToplam: %d\n", toplam(dizi, n));
    printf("Ortalama: %.2f\n", ortalama(dizi, n));
    printf("En buyuk: %d\n", max(dizi, n));
    printf("En kucuk: %d\n", min(dizi, n));
    printf("Mod (en cok tekrar eden): %d\n", mod(dizi, n));
    printf("Medyan: %.2f\n", medyan(dizi, n));

    return 0;
}

/*
Kullanıcıdan n adet sayı alıp bu sayılar üzerinde çeşitli matematiksel
işlemler yapan bir program geliştirmeniz beklenmektedir. Programın:
Toplam
Ortalama
En büyük (max)
En küçük (min)
Mod (en sık tekrar eden sayı)
Medyan (ortanca değer)
değerlerini hesaplaması gerekmektedir. Her işlem ayrı bir fonksiyon içinde yazılıdır.
*/