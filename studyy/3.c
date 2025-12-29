// Soru 3
// Klavyeden girilen bir sayının faktöriyelini hesaplayan bir C programı yazınız.
// (Örnek: Girdi=5 → Çıktı=120)
#include <stdio.h>
int main(){
    int a,i ;
    unsigned long long faktoriyel =1;
    printf("faktoriyelini hesaplamak için bir sayi giriniz: ");
    scanf("%d",&a);

    if (a<0)
    {
        printf("negatif sayilarin faktoriyeli hesaplanamaz!!!!");
    }
    else{
        for (i=1;i<=a;i++)
        {
            faktoriyel=faktoriyel*i;
        }

        printf("%d! = %llu\n",a,faktoriyel);

    }


    return 0;
}