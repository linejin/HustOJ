#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> light[100];
vector<int> heavy[100];
int check[100] = { 0, };
int dfs(vector<int> v[], int now)
{
	int count = 1;
	check[now] = 1;
	for (int i = 0; i < v[now].size(); i++)
	{
		int next = v[now][i];
		if(!check[next])
			count += dfs(v, next);
	}
	return count;
}

void init()
{
	for (int i = 0; i < 100; i++)
		check[i] = 0;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d" , &a, &b);
		light[a].push_back(b);
		heavy[b].push_back(a);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		init();
		int count_light = dfs(light, i) - 1;
		init();
		int count_heavy = dfs(heavy, i) - 1;
		if (count_light > n / 2 || count_heavy > n / 2)
			ans++;
	}
	printf("%d",ans);
}