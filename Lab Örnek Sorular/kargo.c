#include <stdio.h>

float ucretHesapla(float kg)
{
    float ucret;

    if (kg <= 2)
        ucret = 35;
    else
        ucret = 35 + (kg - 2) * 8;

    return ucret;
}

int main()
{
    float kg, ucret;

    printf("Agirlik giriniz: ");
    scanf("%f", &kg);

    ucret = ucretHesapla(kg);
    printf("Toplam Ucret = %.2f TL\n", ucret);

    return 0;
}

/*
Bir kargo firması ilk 2 kg için 35 TL, sonraki her 1 kg için 8 TL almaktadır.
Kullanıcıdan paketin ağırlığını (kg cinsinden, ondalıklı olabilir) alan ve toplam
ücreti hesaplayıp ekrana yazan C programını fonksiyon kullanarak yazınız.
*/
