#include<stdio.h>

main()
{
	float x =  5 / 2;
	float y = (float) 5 / 2;
	
	printf("result:%d\n", x);
	printf("result: %lf\n", x);
	printf("result: %lf\n", y);
	printf("result: %.1lf\n", y);
	printf("result: %.2lf\n", y);
	
}