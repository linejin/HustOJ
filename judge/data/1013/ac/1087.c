#include <iostream>
using namespace std;
int N, M, H, L, light[101], heavy[101];
bool marble[101][101], marble2[101][101], visited[101];
void HDFS(int parentNode, int startNode)
{
	visited[startNode] = true;
	for (int i = 1; i <= N; i++)
		if (marble[startNode][i] && !visited[i]) heavy[parentNode]++, HDFS(parentNode, i);
}
void LDFS(int parentNode, int startNode)
{
	visited[startNode] = true;
	for (int i = 1; i <= N; i++)
		if (marble2[startNode][i] && !visited[i]) light[parentNode]++, LDFS(parentNode, i);
}
void Initialize() { for (int i = 1; i <= 100; i++) visited[i] = false; }
int main()
{
	int ans{};
	cin >> N >> M;
	while (M--)
	{
		cin >> H >> L;
		marble[L][H] = marble2[H][L] = true;
	}
	int mid = (N + 1) / 2;
	for (int i = 1; i <= N; i++) HDFS(i, i), Initialize(), LDFS(i, i), Initialize();
	for (int i = 1; i <= N; i++) ans += light[i] >= mid ? 1 : 0, ans += heavy[i] >= mid ? 1 : 0;
	cout << ans;
	return 0;
}