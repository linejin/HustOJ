#include<cstdio>

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int M[2001][2001];

int main()
{
	int d1, d2;
	int ans = 0;
	scanf("%d %d", &d1, &d2);
	for (int i = d1; i <= d2; i++)
		for (int j = 0; j < i; j++)
		{
			int g = gcd(i, j);
			if (!M[i / g][j / g])
			{
				ans++;
				M[i / g][j / g]++;
			}
		}
	printf("%d",ans);
}