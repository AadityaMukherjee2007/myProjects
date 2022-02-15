#include <stdio.h>

void main()
{
	int num = 65;
	printf("Without 'const':\n\n");
	printf("%d\n", num);
	num = 70;
	printf("%d\n", num);

	const int num2 = 40;
	printf("Using 'const':\n\n");
	printf("%d\n", num2);
	//num2 = 50;  <---  if this line is uncommented error will come as num2 is a constant value and cannot be changed.
	printf("%d", num2);
}
