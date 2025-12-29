#include<stdio.h>

main()
{
	int a, b, c, max;
	
	printf("Lütfen biribirinden farklı 3 sayı giriniz:\n");
	scanf("%d%d%d", &a, &b, &c);
	
	//2.yol
	max = a;
	if(b > max)
		max = b;
	if(c > max)
		max = c;
	
	printf("Max number: %d", max);
	
	
	/*1.yol
	if((a > b) && (a > c))
		printf("En buyuk Sayi: %d", a);
	else if((b > a) && (b > c))
		printf("En buyuk Sayi: %d", b);
	else
		printf("En buyuk Sayi: %d", c);
		*/
		
}