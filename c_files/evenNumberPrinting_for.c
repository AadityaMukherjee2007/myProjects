#include <stdio.h>

int main()
{
	int r = 0, x = 2;
	
	printf("Enter Range: ");
	scanf("%d", &r);
	
	for (int i = 1; i <= r; i++)
	{
		if (x % 2 == 0)
		{
			printf("%d\n", x);
		}
		x += 2;
	}
	
	return 0;
}

