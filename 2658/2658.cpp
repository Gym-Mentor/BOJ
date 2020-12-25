#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

typedef pair<int,int> pii;

char arr[10][10];
pii ans[3];

void input()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cin >> arr[i][j];
		}
	}
}
void output()
{
	for (int i = 0; i < 3; i++)
	{
		cout << ans[i].first+1 << " " << ans[i].second+1<<"\n";
	}
}
void rotate()
{
	char temp[10][10];

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			temp[i][j] = arr[i][j];
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			arr[i][j] = temp[9 - j][i];
		}
	}
}
bool checkType1() 
{
	int y = -1, x = -1;
	for (int i = 0; i < 10; i++) // 첫번째 줄 꼭지점 찾기
	{
		for (int j = 0; j < 10; j++)
		{
			if (arr[i][j]=='1')
			{
				y = i, x = j;
				break;
			}
		}
		if (y != -1)break;
	}
	if (y == -1) return false;
	ans[0] = { y,x };
	char temp[10][10];
	memset(temp, '0', sizeof(temp));
	for (int i = 0; i + y < 10; i++)
	{
		if (arr[i + y][x]=='1')
		{
			if (x-i < 0) return false;
			for (int j = 0; j<= i; j++)
			{
				temp[i+y][x-j] = '1';
				ans[1] = { i + y,x };
				ans[2] = { i + y,x - j };
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (temp[i][j] != arr[i][j])return false;
		}
	}
	return true;
}
bool checkType2()
{
	int y = -1, x = -1;
	for (int i = 0; i < 10; i++) // 첫번째 줄 꼭지점 찾기
	{
		for (int j = 0; j < 10; j++)
		{
			if (arr[i][j]=='1')
			{
				y = i, x = j;
				break;
			}
		}
		if (y != -1)break;
	}
	if (y == -1) return false;
	ans[0] = { y,x };
	char temp[10][10];
	memset(temp, '0', sizeof(temp));
	for (int i = 0; i + y < 10; i++)
	{
		if (arr[i + y][x] == '1')
		{

			if (x - i < 0 || x + i>9) return false;
			for (int j = 0; j <= i; j++)
			{
				temp[i + y][x - j] = '1';
				temp[i + y][x + j] = '1';
				ans[1] = { i + y,x - j };
				ans[2] = { i + y,x + j };
			}
		}
	}
	cout << "\n";
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (temp[i][j] != arr[i][j])return false;
		}
	}
	return true;
}
void rotateReverse(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int y = ans[j].second, x = ans[j].first;
			ans[j].first = 9 - y;
			ans[j].second = x;
		}
	}
}
int main()
{
	input();
	for (int i = 0; i < 4; i++)
	{
		rotate();
		if (checkType1())
		{
			rotateReverse(i + 1);
			sort(ans, ans + 3);
			output();
			return 0;
		}
		if (checkType2())
		{
			rotateReverse(i + 1);
			sort(ans, ans + 3);
			output();
			return 0;
		}
	}
	cout << "0";
}