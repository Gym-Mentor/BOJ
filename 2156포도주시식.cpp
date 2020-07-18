#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	int Dp[10000 + 1];
	int drink[10000 + 1];

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> drink[i];
	}
	Dp[0] = 0;
	Dp[1] = drink[1];
	Dp[2] = Dp[1] + drink[2];
	for (int i = 3; i <= n; i++)
	{
		Dp[i] = max(Dp[i - 2] + drink[i], Dp[i - 3] + drink[i - 1] + drink[i]);
		cout << Dp[i] << "\n";
	}
	cout << Dp[n];
}