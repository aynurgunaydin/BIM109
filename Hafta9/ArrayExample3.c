//100 elamanlı A dizisinin elemanalarına 2'den başlayarak
//cift sayilari atayan C kodunu yazınız 

#include<stdio.h>
#define SIZE 100

main()
{
	int i, A[100];
	
	for(i = 0; i < SIZE; i++)
		A[i] = (i + 1) * 2;
		
	for(i = 0; i < SIZE; i++)
		printf("A[%d]: %d\n", i, A[i]);	
}








