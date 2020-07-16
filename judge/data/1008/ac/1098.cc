#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;

int n;
long long cnt[10001];

long long avg(long long num)
{
	long long ret = 0;
	for (int i = 0; i <= 10000; i++)
	{
		ret += abs((i - num) * cnt[i]);
	}
	return ret;
}

long long mse(long long num)
{
	long long ret = 0;
	for (int i = 0; i <= 10000; i++)
	{
		ret += (i - num) * (i - num) * cnt[i];
	}
	return ret;
}

int main()
{
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		scanf("%d", &temp);
		cnt[temp]++;
	}
	long long min_ave = 123456789123456789, min_mse = 123456789123456789;
	int ans_ave = 0, ans_mse = 0;
	for (int i = 1; i <= 10000; i++)
	{
		long long avg_ret = avg(i);
		long long mse_ret = mse(i);
		if (min_ave > avg_ret)
		{
			min_ave = avg_ret;
			ans_ave = i;
		}
		if (min_mse > mse_ret)
		{
			min_mse = mse_ret;
			ans_mse = i;
		}
	}
	printf("%d %d", ans_ave, ans_mse);
}