#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;

int floyd[100][100];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		floyd[a][b] = 1;
	}
	for (int b = 1; b <= n; b++)
		for (int a = 1; a <= n; a++)
			for (int c = 1; c <= n; c++)
				if (floyd[a][b] && floyd[b][c])
					floyd[a][c] = 1;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int cnt_col = 0;
		int cnt_row = 0;
		for (int j = 1; j <= n; j++)
		{
			if (i != j)
			{
				if (floyd[i][j]) cnt_col++;
				if (floyd[j][i]) cnt_row++;
			}
		}
		if (cnt_col > n / 2 || cnt_row > n / 2)
			ans++;
	}
	printf("%d", ans);
}