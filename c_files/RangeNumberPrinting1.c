#include <stdio.h>
void main()
{
	int n, x = 1;
	printf("Enter Range: ");
	scanf("%d", &n);
	
	c:
		if (x <= n)
		{
			printf("%d\n", x);
			x++;
			goto c;
		}
}
