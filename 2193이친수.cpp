#include<iostream>
using namespace std;
long long Dp[90 + 1][3];
int main()
{
	int N;
	cin >> N;

	Dp[1][0] = 0;
	Dp[1][1] = 1;
	for (int i = 2; i < N + 1; i++)
	{
		Dp[i][0] = Dp[i - 1][0] + Dp[i - 1][1];
		Dp[i][1] = Dp[i - 1][0];
	}
	Dp[N][2] = Dp[N][1] + Dp[N][0];
	cout << Dp[N][2];
}