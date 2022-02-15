#include <stdio.h>

void main()
{
	int num = 0;
	printf("Enter a Number: ");
	scanf("%d", &num);

	if(num % 2 == 0)
	{
		printf("Even");
	}
	else
	{
		printf("Odd");
	}
}
