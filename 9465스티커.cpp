#include<iostream>
#include<algorithm>
using namespace std;
int Dp[100000 + 1][2];
int main()
{
	int T, n;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		memset(Dp, 0, sizeof(Dp));
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> Dp[i][0];
		}
		for (int i = 0; i < n; i++) {
			cin >> Dp[i][1];
		}
		for (int i = 1; i < n; i++)
		{
			Dp[i][0] += max(Dp[i - 1][1], Dp[i - 2][1]);
			Dp[i][1] += max(Dp[i - 1][0], Dp[i - 2][0]);
		}
		cout << max(Dp[n - 1][0], Dp[n - 1][1])<<"\n";
	}
}