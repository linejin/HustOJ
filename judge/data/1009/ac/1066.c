#include<cstdio>

int main()
{
	int n;
	int card[1000][5];
	int ans = 0;
	int max_score = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = 0; j < 5; j++)
		{
			scanf("%d", &card[i][j]);
			sum += card[i][j];
		}
		for (int j = 0; j < 5; j++)
			for (int l = j + 1; l < 5; l++)
			{
			    for(int k = l + 1; k < 5; k++) 
			    {
			        int score = (card[i][j] + card[i][l] + card[i][k]) % 10;
				if (max_score <= score)
				{
					max_score = score;
					ans = i + 1;
				}
			    }
			}
	}
	printf("%d", ans);
}