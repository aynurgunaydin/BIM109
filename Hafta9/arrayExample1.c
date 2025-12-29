#include<stdio.h>
main()
{
	int i;
	char A[] = {'s', 'e', 'n', 'g', 'u', 'l', '\0'};
	
	for(i = 0; i < 6; i++)
		printf("A[%d]: %c\n", i, A[i]);
}
