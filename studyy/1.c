//Klavyeden bir tamsayı giriniz.
//Girilen sayıdan küçük olan 1 ile 100 arasındaki tüm çift sayıları ekrana listeleyen bir C programı yazınız.
#include <stdio.h>
int main() {
    int a,i;
    printf("bir sayi giriniz:");
    scanf("%d",&a);
    if(a<1 || a>100){
        printf("geçersiz giriş");
    
    }
    else{
        for (i=1; i<a; i++)
        {
            if (i%2==0)
            {
                printf(" %d",i);
            }
            
        }
      

    }

    return 0 ;
}





