#include <stdio.h>
void main()
{
	float a, b, c, op;
	
	printf("Enter a Number: ");
	scanf("%f", &a);

	printf("Enter a Number: ");
	scanf("%f", &b);

	printf("Enter 1 for addition, 2 for subtraction, 3 for multiplication & 4 for division.\n");
	printf("Enter Operator: ");
	scanf("%f", &op);


	if (op == 1)
	{
		c = a + b;
		printf("Answer = %f", c);
	}
	else if (op == 2)
	{
		c = a - b;
		printf("Answer = %f", c);
	}
	else if (op == 3)
	{
		c = a * b;
		printf("Answer = %f", c);
	}
	else if (op == 4)
	{
		c = a / b;
		printf("Answer = %f", c);
	}
	else
	{
		printf("Error!!");
	}
}
