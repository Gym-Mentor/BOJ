#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

int main()
{
	int arr[4], ans = 10000, inputClock;
	for (int i = 0; i < 4; i++)
	{
		cin >> arr[i];
	}
	inputClock = arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3];
	for (int i = 0; i < 4; i++)
	{
		if (ans > inputClock)
		{
			ans = inputClock;
		}
		inputClock = (inputClock % 10)*1000 + inputClock / 10;
	}
	vector<int> clock;
	for (int i = 1111; i < 10000; i++)
	{
		if (i / 100 % 10 == 0)continue;
		if (i / 10 % 10 == 0)continue;
		if (i % 10 == 0)continue;

		int min=10000;
		int now = i;

		for (int j = 0; j < 4; j++)
		{
			if (min > now)
			{
				min = now;
			}
			int temp = now % 10;
			now /= 10;
			now=temp * 1000 + now;
		}
		clock.push_back(min);
	}
	sort(clock.begin(), clock.end());
	clock.erase(unique(clock.begin(), clock.end()));
	int result = 0;

	for (int i = 0; i < clock.size(); i++)
	{
		result++;
		if (clock[i] == ans)
			break;
	}
	cout << result;
}