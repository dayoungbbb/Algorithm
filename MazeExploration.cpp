#include <iostream>
#include <queue>
using namespace std;
#define MAX_N 100
#define INF 987654321
int map[MAX_N][MAX_N], visited[MAX_N][MAX_N];
int n, m;
int d[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
void bfs()
{
	//(0, 0)에서 (n-1, m-1)까지
	int sum = map[0][0];
	int x = 0, y = 0;
	queue<pair<int, int> > q;
	visited[x][y] = 1;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = x + d[i][0];
			int ty = y + d[i][1];
			if (!map[tx][ty] || visited[tx][ty] || tx < 0 || ty < 0 || tx >= n || ty >= m)
				continue;
			visited[tx][ty] = visited[x][y]+1;
			q.push(make_pair(tx, ty));
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d", &map[i][j]);

	bfs();
	cout << visited[n - 1][m - 1];
}