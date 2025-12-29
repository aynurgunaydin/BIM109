//Example 2: Klavyeden girilen bir sayının 
//çift mi tek mi olduğunu 
//ekrana yazdıran C kodunu yazınız

#include<stdio.h>

int main()
{
	int number;
	printf("Enter a number:\n");
	scanf("%d", &number);
	
	if((number % 2) == 0)
	{
		printf("%d is even number", number);
	}
	else
	{
			printf("%d is odd number", number);
	}
	return 0;
}