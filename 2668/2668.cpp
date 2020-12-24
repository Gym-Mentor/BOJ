#include<iostream>
#include<vector>
#include<algorithm>
/*
	* dfs문제로 사이클이 되는지 판단한다
*/

using namespace std;

#define endl '\n'

// Set up : Global Variables
int cnt;
int node[101];
bool cycle[101];
bool visited[101];

// Set up : Functions Declaration
int dfs(int startNum, int nodeNum)
{
	if (visited[nodeNum])
		return false;
	visited[nodeNum] = true;
	if (startNum == nodeNum || dfs(startNum, node[nodeNum]))
	{
		cnt++;
		cycle[nodeNum] = true;
		return true;
	}
	return false;
}

int main()
{
	//Set up : I/O
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//input
	int N; cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> node[i];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			visited[j] = cycle[j];
		}
		dfs(i, node[i]);
	}

	cout << cnt << endl;

	for (int i = 1; i <= N; i++)
		if (cycle[i]) //사이클 이루는 노드들 출력
			cout << i << endl;

	return 0;
}