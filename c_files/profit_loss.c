#include <stdio.h>

int main()
{
	float cp, sp;
	
	printf("Cost Price: ");
	scanf("%f", &cp);
	
	printf("Selling Price: ");
	scanf("%f", &sp);
	
	if (sp > cp)
	{
		float profit = sp - cp;
		float pp = (profit / cp) * 100;
		
		printf("Profit : %f", profit);
		printf("\nProfit percent : %f%%", pp);
	}
	else
	{
		float loss = cp - sp;
		float lp = (loss / cp) * 100;
		
		printf("Loss : %f", loss);
		printf("\nLoss percent : %f%%", lp);
	}
	return 0;
}
