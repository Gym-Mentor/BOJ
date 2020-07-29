#include<iostream>
using namespace std;
int main()
{
	int n;
	int dp[1001], a[1001];
	int max = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < n; i++)
	{
		int min = 0;
		for (int j = 0; j < i; j++)
		{
			if (a[j] > a[i])
				if (min < dp[j])
					min = dp[j];
		}
		dp[i] = min + 1;
		if (max < dp[i])
			max = dp[i];
	}
	cout << max;
}