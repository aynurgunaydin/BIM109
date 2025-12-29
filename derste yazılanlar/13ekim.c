//klavyeden verile sayının pozitif mi negati mi olduğunu yazdır ekrana

#include<stdio.h>

int main(){

// int sayi;

// printf("bir sayı giriniz:\n");
// scanf("%d",&sayi);

// if (sayi>0)
// {
//     printf("%d sayisi pozitiftir\n",sayi);
// }
// else
// {
//     printf("%d sayisi negatiftir\n",sayi);
// }

//iki sayı birbirinin katı mı yazdır

// int sayi1,sayi2;
// printf("iki sayi giriniz:\n");

// scanf("%d %d",&sayi1,&sayi2);
// if (sayi1%sayi2==0)
// {
//     printf("%d %dnin katidir\,n",sayi1,sayi2);
// }
// else
// {
//     printf("%d %dnin tam kati değildir\n",sayi1,sayi2);
// }

//klavyeden girilen x değerine göre y ve ze değerleirni ekrana yazdıran c kodunu yazınız

// int x,y,z;

// printf("x sayisini giriniz:\n",x);
// scanf("%d",&x);
// if (x>0)
// {
//     y=x*x+2*x;
//     z=3*x;
//     printf("y:%d\nz:%d\n",y,z);
// }
// else
// {
//     y=x;
//     z=x*x;
//     printf("y:%d\nz:%d\n",y,z);


// }


//a ve b değerleri girdir a ile b earsındaki büyüklük ilişkisini ekrana yazdır

int a,b;
printf("a ve b sayilarini giriniz:\n",a,b);
scanf("%d %d",&a,&b);
if (a>b)
{
    printf("a b'den büyüktür");
}
else if (a<b)
{
    printf("a b'den küçüktür");
}
else
{
    printf("a b'ye eşittir");
}
return 0;

}