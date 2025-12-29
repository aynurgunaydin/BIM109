//Ex:1 Klavyeden girilen tam sayinin i negatif mi 
//pozitif mi olduğunu hesaplayan C kodunu yaziniz
#include<stdio.h>

int main(void)
{
	//Example 3:
	
	int x, y, z;
	printf("Enter x value:\n");
	scanf("%d", &x);
	
	if(x < 0)
	{
		y = (x * x) + (2 * x);
		z = 3 * x;
	}
	else
	{
		y = x;
		z = x * x;
	}
	printf("y = %d z = %d\n", y, z);
	
	/*
	//Example 2:
	//Klavyeden a ve b tamsayilari giriliyor. 
	//a nın b nin tam kati olup olmadğını 
	//hesaplayan C kodunu yaziniz
	
	int a, b;
	printf("Enter 2 numbers\n");
	scanf("%d%d", &a, &b);
	
	if(a % b == 0)
		printf("%d %d nin tam kati", a, b);
	else
		printf("%d %d nin tam kati degildir", a, b);
	*/
	/*Example 1:
	
	int number;
	
	printf("Enter a number\n");
	scanf("%d", &number);
	
	if(number < 0)
		printf("%d is a negative number", number);
	else
		printf("%d is a positive number", number);
	*/
}