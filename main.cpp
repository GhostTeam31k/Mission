#include <iostream>

using namespace std;

int A()
{
	int Number = 10;

	return 0;

}

int main()
{
	int B = 0;
	{
		int B = 1;
	}

	cout << B << endl;

	cout << B << endl;

	return 0;

}