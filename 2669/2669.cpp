#include<iostream>

using namespace std;

/*
	2차원 배열을 만들고
	bool값으로 면적을 구한다
*/

int main()
{
	bool arr[101][101] = { false, };
	for (int i = 0; i < 4; i++)
	{
		int num1, num2, num3, num4;
		cin >> num1 >> num2 >> num3 >> num4;
		for (int j = num1; j < num3; j++)
		{
			for (int k = num2; k < num4; k++)
			{
				arr[j][k] = true;
			}
		}
	}
	int cnt=0;
	for (int i = 1; i <= 100; i++)
	{
		for (int j = 1; j <= 100; j++)
		{
			if (arr[i][j])
				cnt++;
		}
	}
	cout << cnt;
}