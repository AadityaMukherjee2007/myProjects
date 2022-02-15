#include <stdio.h>
#include <limits.h>
int main()
{
	int a = sizeof(int), b = sizeof(char);
	printf("Storage size for int is %d\n", a);
	printf("Storage size for char is %d\n", b);
	return(0);
}
