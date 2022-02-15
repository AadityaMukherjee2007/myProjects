#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}

int main()
{
	int x, y;
	cout << "Enter first number: ";
	cin >> x;
	
	cout << "Enter second number: ";
	cin >> y;

	swap(x, y);
	cout << "\nAfter swap: " << "\nFirst number: " << x << "\nSecond number: " << y;
	
	return 0;
}
