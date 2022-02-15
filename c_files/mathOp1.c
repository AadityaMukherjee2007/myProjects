#include <stdio.h>
void main()
{
	int a = 6, b = 3, c;
	
	c = a + b;
	printf("%d + %d = %d", a, b, c);
	c = a - b;
	printf("\n%d - %d = %d", a, b, c);
	c = a * b;
	printf("\n%d * %d = %d", a, b, c);
	c = a / b;
	printf("\n%d / %d = %d", a, b, c);
	c = a % b;
}
