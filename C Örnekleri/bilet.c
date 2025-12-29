#include <stdio.h>

float calculateTicketPrice(int type)
{
    if (type == 1)
    {
        return 50.0f;
    }
    else if (type == 2)
    {
        return 80.0f;
    }
    else
    {
        return 0.0f;
    }
}

float applyDayDiscount(float price, int day)
{
    if (day == 1 || day == 3 || day == 5)
    {
        return price * 0.80f;
    }
    return price;
}

float applyAmountIncrease(float price, int count)
{
    if (count >= 5)
    {
        return price + 10.0f;
    }
    return price;
}

int main()
{
    int biletTipi, gun, adet;
    float tekBiletFiyati, nihaiFiyat;

    printf("Bilet tipini girin (1: Ogrenci, 2: Tam): ");
    scanf("%d", &biletTipi);

    printf("Gun numarasini girin (1=Pazartesi, ..., 7=Pazar): ");
    scanf("%d", &gun);

    printf("Bilet adedini girin: ");
    scanf("%d", &adet);

    if (biletTipi != 1 && biletTipi != 2)
    {
        printf("Gecersiz bilet tipi.\n");
        return 1;
    }
    if (gun < 1 || gun > 7 || adet <= 0)
    {
        printf("Gecersiz giris.\n");
        return 1;
    }

    tekBiletFiyati = calculateTicketPrice(biletTipi);
    tekBiletFiyati = applyDayDiscount(tekBiletFiyati, gun);
    tekBiletFiyati = applyAmountIncrease(tekBiletFiyati, adet);

    nihaiFiyat = tekBiletFiyati * adet;

    printf("Nihai Toplam Ucret: %.2f TL\n", nihaiFiyat);

    return 0;
}