#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Enter Range: ";
	cin >> n;

	int x = 1;
	while (x <= n)
	{
		int i = 1;
		while (i <= x)
		{
			cout << "* ";
			i++;
		}
		cout << "\n";
		x++;
	}

	return 0;
}
