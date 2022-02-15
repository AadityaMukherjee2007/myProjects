#include <stdio.h>

void main()
{
	int num;
	printf("Enter a Number: ");
	scanf("%d", &num);
	
	if (num < 0)
	{
		printf("Negative Number!");
	}
	else
	{
		printf("Positive Number!");
	}
}
