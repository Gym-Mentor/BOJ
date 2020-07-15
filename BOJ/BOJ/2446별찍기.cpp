#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}
		for (int k = 0; k < 2 * n - i * 2-1; k++)
			cout << "*";
		cout << "\n";
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = n - i; j > 0; j--)
			cout << " ";
		for (int k = 1; k < i * 2; k++)
			cout << "*";
		cout << "\n";

	}
}