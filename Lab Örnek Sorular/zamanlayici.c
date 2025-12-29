#include <stdio.h>

void zamanaCevir(int dakika)
{
    int saat = dakika / 60;
    int dk = dakika % 60;

    printf("Sure: %d:%d\n", saat, dk);
}

int main()
{
    int toplamDakika;

    printf("Pisme suresini dakika olarak giriniz: ");
    scanf("%d", &toplamDakika);

    zamanaCevir(toplamDakika);

    return 0;
}

/*
Fırınınız için bir zamanlayıcı yazmak istiyorsunuz. Kullanıcıdan
toplam pişirme süresini dakika cinsinden alan ve bunu saat:dakika
biçiminde ekrana yazan C programını fonksiyon kullanarak yazınız.
*/