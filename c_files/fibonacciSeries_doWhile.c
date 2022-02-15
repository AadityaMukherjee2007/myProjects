#include <stdio.h>

int main()
{
	int a = 0, b = 1, c = 0, i = 1, r = 1;
	
	printf("Enter Range: ");
	scanf("%d", &r);
	
	do
	{
		printf("%d\n", c);
		c = a + b;
		b = a;
		a = c;
		i++;
	}while(i <= r);
	
	return 0;
}
