#include<cstdio>
#include<algorithm>
using namespace std;

char m[22][22];
int check[255];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int ans;
void dfs(int cnt, int x, int y)
{
    check[m[y][x]] = 1;
    ans = max(ans, cnt);
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!check[m[ny][nx]])
            dfs(cnt + 1, nx, ny);
    }
    check[m[y][x]] = 0;
}

int main()
{
    int r, c;
    scanf("%d %d", &r, &c);
    for (int i = 1; i <= r; i++)
        scanf("%s", &m[i][1]);
    check[0] = 1;
    dfs(1, 1, 1);
    printf("%d", ans);
}