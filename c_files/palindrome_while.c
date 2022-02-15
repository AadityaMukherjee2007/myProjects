#include <stdio.h>

int main()
{
	int n; 
	
	printf("Enter Number: ");
	scanf("%d", &n);
	
	int d = n;
	
	int r = 0, s = 0;
	while(n != 0)
	{
		r = n % 10;
		s = s * 10 + r;
		n = n / 10;
	}
	
	if (d == s)
	{
		printf("Palindrome!");
	}
	else
	{
		printf("Not Palindrome!");
	}
	
	return 0;
}

