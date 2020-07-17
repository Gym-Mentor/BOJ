#include<iostream>
using namespace std;
int Dp[101][10];
int main() {
	int N;
	cin >> N;
	Dp[0][0] = 0;
	for (int i = 1; i < 10; i++)
	{
		Dp[0][i] = 1;
	}
	for (int i = 1; i < N; i++)
	{
		Dp[i][0] = Dp[i - 1][1];
		Dp[i][9] = Dp[i - 1][8];
		for (int j = 1; j < 9; j++)
		{
			Dp[i][j] = Dp[i - 1][j - 1] + Dp[i - 1][j + 1];
		}
	}
	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		sum += Dp[N - 1][i];
	}
	cout << sum;
}