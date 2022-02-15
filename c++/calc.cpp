#include <iostream>
using namespace std;

double add(double a, double b)
{
	double c = a + b;
	return c;
}

double sub(double a, double b)
{
	double c = a - b;
	return c;
}

double mul(double a, double b)
{
	double c = a * b;
	return c;
}

double div(double a, double b)
{
	double c = a / b;
	return c;
}


int main()
{
	double a, b, ans;
	char op;

	cout << "Calculator: \n";

	cout << "Enter Number: ";
	cin >> a;

	cout << "Enter Number: ";
	cin >> b;

	cout << "\nOperations:\n'+' --. addition\n'-' --> subtraction\n'*' --> multiplication\n'/' --> division\n";
	cout << "\nEnter Operator: ";
	cin >> op;

	if (op == '+')
	{
		ans = add(a, b);
	}
	else if (op == '-')
	{
		ans = sub(a, b);
	}
	else if (op == '*')
	{
		ans = mul(a, b);
	}
	else if (op == '/')
	{
		ans = div(a, b);
	}

	cout << "\n" << a << " " << op << " " << b << " = " << ans << "\n";
	return 0;
}