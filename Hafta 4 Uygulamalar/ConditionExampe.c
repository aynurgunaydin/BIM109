

#include<stdio.h>

main()
{
	//Example 4:
	/*Klavyeden a ve b degerleri giriliyor. "a > b", "a < b","a = b"
	a ile b arasındaki büyüklük ilişkisini 
	ekrana yazdıran C kodunu yazınız*/
	int a, b;
	printf("a ve b sayilarini giriniz: ");
	scanf ("%d%d", &a, &b);
	
	if(a > b)
		printf("%d > %d", a, b);
	else if(a == b)
		printf("%d = %d", a, b);
	else
		printf("%d < %d", a, b);
//Example 3:
/*	int x, y, z;
	
	printf("x degerini giriniz: ");
	scanf("%d", &x);
	
	if(x < 0)
	{
		y = (x * x) + (2 * x); 
		z = 3 * x ;
	else
	{
		y = x;
		z = x * x;
	}
	
	printf("y = %d, z = %d", y, z);
*/	
//Example 2: Klavyeden girilen a ve b tamsayıları için 
//a nın b nin tam katı olup olmadığını
//ekrana yazdıran C kodunu yazınız
/*
	int a, b;
	printf("a ve b sayilarini girin: ");
	scanf("%d%d", &a, &b);
	
	if(a % b == 0)
		printf("%d %d nin tam katidir", a, b);
	else
		printf("%d %d nin tam kati degildir", a, b);	
*/
//Example 1: Klavyeden girilen sayının pozitfi mi
	//negatif mi olduğunu ekrana yazdıran 
	//C kodunu yazınız
/*	int number;
	
	printf("Enter a number: ");
	scanf("%d", &number);
	
	if(number < 0)
	
		printf("%d is negative", number);
	   
	else
	
		printf("%d is positive", number);
		*/
}