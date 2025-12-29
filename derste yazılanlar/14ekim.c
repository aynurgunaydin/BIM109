#include<stdio.h>
int main()
 {
    // int sayi;
    // printf("lütfen bir sayi giriniz\n");
    // scanf("%d",&sayi);

    // //if((sayi>1)&&(sayi<100))

    // if(sayi>1)
    //   if(sayi<100)
    //     printf("%d, 1 ile 100 arasinda\n",sayi);
    
    //   else 
    //     printf("%d, 1 ile 100 arasinda değil\n",sayi);
    // else 
    // printf("%d, 1 ile 100 arasinda değildir\n",sayi);

    // ((sayi>1)&&(sayi<100)) ? printf("arasinda") : printf("degil");


// iki sayıdan büyük olanı ekrana üçlü işlev şeklinde yazdırın

//  int a,b;
//    printf("iki sayi giriniz:\n");
//    scanf("%d %d",&a,&b);

//    (a>b) ? printf("%d büyük olan sayidir",a) : printf("%d büyük olan sayidir",b);

//haftanın günlerini yazdıran kod

//   int day;
//   printf("1 ile 7 arasinda bir deger girin\n");
//   scanf("%d",&day);

//   switch (day)
//   {
//   case 1:
//     printf("pazartesi");
//     break;
//   case 2:
//     printf("sali");
//     break;
//   case 3:
//     printf("çarşamba");
//     break;
//   case 4:
//     printf("perşembe");
//     break;
//   case 5:
//     printf("cuma");
//     break;
//   case 6:
//     printf("cumartesi");
//     break;
//   case 7:
//     printf("pazar");
//     break;

//   default:
//     printf("iyi haftalaarrrr");
    
//   }
    

int a,b,c,max;

printf("üç sayi giriniz:\n");
scanf("%d %d %d",&a,&b,&c);

// if (a>b && a>c)
// {
//     printf("a en büyük sayidir");
// }
// else if(b>a && b>c)
// {
//     printf("b en büyük sayidir");
// }
// else{
//     printf("c en büyük sayidir");
// }

max = a;

if (b>max)
{
    max = b;
}
else if (c>max)
{
    max = c ;
}
else{
    max = a;

}
 printf("en büyük sayi %ddir",max);














    return 0;
}