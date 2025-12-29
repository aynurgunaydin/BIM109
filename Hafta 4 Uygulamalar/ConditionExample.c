#include<stdio.h>

main()
{
	int a, b;
	
	printf("Lütfen 2 sayi giriniz:");
	scanf("%d%d", &a, &b);
	
	if(a > b)
	{	
		printf("%d > %d", a, b);
	}
	else
	{
		printf("%d < %d", a, b);
	}
}