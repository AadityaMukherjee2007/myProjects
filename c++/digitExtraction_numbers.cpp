#include <iostream>
using namespace std;

int main()
{
	int n, r = 0, rem = 0;
	cout << "Enter Number: ";
	cin >> n;
	
	int s = n % 10;
	n /= 10;

	while (n != 0)
	{
		r = n % 10;
		s *= 10 + r;		
		n /= 10;
	}
	
	while (s != 0)
	{
		rem = s % 10;
		cout << rem << endl;
		s /= 10;
	}
	return 0;
}
