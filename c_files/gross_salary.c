#include <stdio.h>

int main()
{
	float s, gs;
	
	printf("Input basic salary of an employee: ");
	scanf("%f", &s);
	
	if (s <= 10000.0)
	{
		float da = s * (80.0 / 100.0);
		float hra = s * (20.0 / 100.0);
		
		gs = s + da + hra;
	}
	else if (s > 10000.0 && s <= 20000.0)
	{
		float da = s * (90.0 / 100.0);
		float hra = s * (25.0 / 100.0);
		
		gs = s + da + hra;
	}
	else if (s > 20000.0)
	{
		float da = s * (95.0 / 100.0);
		float hra = s * (30.0 / 100.0);
		
		gs = s + da + hra;
	}
	printf("Gross Salary: %f", gs);
	
	return 0;
}
