#include <stdio.h>
int main()
{
	int num;
	printf("Enter number from 0 to 9 : ");
	scanf("%d", &num);
	
	switch (num)
	{
		case 0 : printf("Zero");
		break;
		
		case 1 : printf("One");
		break;
		
		case 2 : printf("Two");
		break;
		
		case 3 : printf("Third");
		break;
		
		case 4 : printf("Four");
		break;
		
		case 5 : printf("Five");
		break;
		
		case 6 : printf("Six");
		break;
		
		case 7 : printf("Seven");
		break;
		
		case 8 : printf("Eight");
		break;
		
		case 9 : printf("Nine");
		break;
		
		default : printf("Wrong Input!");
		break;
	}
	return(0);
}
