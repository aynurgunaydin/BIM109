#include <stdio.h>

#define PI 3.14159f

float calculateAreaCircle(int radius)
{
    return PI * radius * radius;
}

float calculateAreaSquare(int edge)
{
    return (float)edge * edge;
}

float calculateAreaTriangle(int base, int height)
{
    return (float)(base * height) / 2.0f;
}

int main()
{
    int secim;
    float alan = 0.0f;

    printf("Alan Hesaplama Menusu:\n");
    printf("1 - Daire\n");
    printf("2 - Kare\n");
    printf("3 - Ucgen\n");
    printf("Seciminizi girin (1, 2 veya 3): ");
    scanf("%d", &secim);

    switch (secim)
    {
    case 1:

        int yaricap;
        printf("Dairenin yaricapini girin: ");
        scanf("%d", &yaricap);
        alan = calculateAreaCircle(yaricap);
        printf("Dairenin Alani: %.2f\n", alan);
        break;

    case 2:

        int kenar;
        printf("Karenin kenar uzunlugunu girin: ");
        scanf("%d", &kenar);
        alan = calculateAreaSquare(kenar);
        printf("Karenin Alani: %.2f\n", alan);
        break;

    case 3:

        int taban, yukseklik;
        printf("Ucgenin taban uzunlugunu girin: ");
        scanf("%d", &taban);
        printf("Ucgenin yuksekligini girin: ");
        scanf("%d", &yukseklik);
        alan = calculateAreaTriangle(taban, yukseklik);
        printf("Ucgenin Alani: %.2f\n", alan);
        break;

    default:
        printf("Gecersiz secim.\n");
        break;
    }

    return 0;
}