#include <stdio.h>

void geriSay(int n)
{
    if (n == 0)
    {
        printf("Kurabiyeler hazir!\n");
        return;
    }

    printf("%d kurabiye kaliyor...\n", n);

    geriSay(n - 1);
}

int main()
{
    int n;

    printf("Kurabiye sayisini giriniz: ");
    scanf("%d", &n);

    geriSay(n);

    return 0;
}

/*
n kurabiye için “geri sayım” şeklinde çalışan bir
recursive fonksiyon yazınız. Fonksiyon, her çağrıldığında
kalan kurabiye sayısını ekrana yazmalı ve n 0 olduğunda
"Kurabiyeler hazır!" mesajını vermelidir.
*/