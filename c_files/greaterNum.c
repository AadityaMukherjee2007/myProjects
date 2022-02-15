#include <stdio.h>

void main()
{
	int a, b;
	printf("Enter 1st. Number: ");
	scanf("%d", &a);

	printf("Enter 2nd. Number: ");
	scanf("%d", &b);

	if(a > b)
	{
		printf("%d is greater.", a);
	}
	else if(a == b)
	{
		printf("Equal");
	}
	else if(a < b)
	{
		printf("%d is greater.", b);
	}
}
