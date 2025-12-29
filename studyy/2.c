// Soru 2
// Klavyeden girilen sayının pozitif, negatif veya sıfır olduğunu ekrana yazdıran bir C programı yazınız.
#include<stdio.h>
int main() {
    int a;
    printf("bir sayi giriniz:");
    scanf("%d",&a);
    if (a<0)
    {
        printf("%d sayisi negatiftir",a);
    }
    else if (a==0)
    {
        printf("%d sayısı 0'a eşittir",a);
    }
    
    else{
        printf("%d sayisi pozitiftir",a);
    }
    



    return 0 ;
}