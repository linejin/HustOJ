#include <cstdio>
#include <algorithm>
using namespace std;

int d[4][50001];
int input[50001];

int main()
{
    int n, m;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &input[i]);
    }
    scanf("%d", &m);

    for (int i = 1; i <= 3; i++)
        for (int j = i * m; j <= n; j++)
        {
            int sum = 0;
            for (int k = j - m + 1; k <= j; k++)
            {
                sum += input[k];
            }
            d[i][j] = max(d[i][j - 1], d[i - 1][j - m] + sum);
        }

    printf("%d", d[3][n]);
    return 0;
}