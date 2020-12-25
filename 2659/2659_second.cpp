#include<iostream>

using namespace std;
void input(int* arr)
{
	for (int i = 0; i < 4; i++)
	{
		cin >> arr[i];
	}
}
int Clock(int num)
{
	int temp=10000;
	for (int i = 0; i < 4; i++)
	{
		if (temp > num)
			temp = num;
		num = num / 10 + (num % 10) * 1000;
	}
	return temp;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int arr[4];
	input(arr);
	int Colcknum = Clock(arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3]);
	int cnt = 0;
	for (int i = 1111; i <= Colcknum; i++)
	{
		if (Clock(i) == i)cnt++;
	}
	cout << cnt;
}