#include<stdio.h>
#define SIZE 12//dizinin kaç elamanlı olduğunu yazıyoruz, SIZE içinde saklayabiliriz
main()
{
	
	//int n[5] = {32, 27, 64, 18, 95, 14}; //Array Index out of exception - dizi taşması
	
	int i, c[] = {-45, 6, 0, 72, 1543, -89, 0, 62, -3, 1, 6453, 78};
	int z[100];
	
	for(i = 0; i < SIZE; i++)
		printf("c[%d]: %d\n", i, c[i]);	
}