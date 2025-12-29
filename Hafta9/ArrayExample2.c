//Klavyeden girilen bir degeri 5 elemanlı 
//A dizisine atayan C kodunu yazın

#include<stdio.h>
#define SIZE 5
main()
{
	int A[5], n, i, k;
	
	printf("Lutfen bir sayi girin: ");
	scanf("%d", &n);
	
	for(i = 0; i < SIZE; i++)
		A[i] = n;
		
	for(i = 0; i < SIZE; i++)
		printf("A[%d]: %d\n", i, A[i]);
	
}





