#include<iostream>
using namespace std;
int Dp[1001][10];
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < 10; i++) {
		Dp[0][i] = 1;
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = j; k < 10; k++)
			{
				Dp[i][j] = (Dp[i][j] + Dp[i - 1][k]) % 10007;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		sum+=Dp[N - 1][i];
		sum %= 10007;
	}
	cout << sum;
}