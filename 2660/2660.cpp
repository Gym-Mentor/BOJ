#include<iostream>

using namespace std;

int N;
int graph[51][51];
int score[51];
void floyd()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= N; k++)
			{
				if (graph[j][k] > graph[j][i] + graph[i][k])
					graph[j][k] = graph[j][i] + graph[i][k];
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			graph[i][j] = (i == j) ? 0 : 123456789;
		}
	}
	while (1)
	{
		int num1, num2;
		cin >> num1 >> num2;
		if (num1 == -1)break;
		graph[num1][num2] = 1;
		graph[num2][num1] = 1;
	}
	floyd();
	for (int i = 1; i <= N; i++)
	{
		int max = 0;
		for (int j = 1; j <= N; j++)
		{
			if (max < graph[i][j])
				max = graph[i][j];
		}
		score[i] = max;
	}
	int min = 123456789;
	for (int i = 1; i <= N; i++)
	{
		if (min > score[i])
			min = score[i];
	}
	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		if (min == score[i])
		{
			cnt++;
		}
	}
	cout << min << " " << cnt << "\n";
	for (int i = 1; i <= N; i++)
	{
		if (min == score[i])
		{
			cout << i << " ";
		}
	}

}