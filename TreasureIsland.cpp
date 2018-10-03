#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define MAX_N 50
int m, n, cnt, d[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
char map[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
void bfs(int x, int y) {
	visited[x][y] = 0;
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		x = q.front().first; y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int dx = x + d[i][0]; int dy = y + d[i][1];
			if ((visited[dx][dy]==-1) && map[dx][dy] == 'L' && dx >= 0 && dy >= 0 && dx < m && dy < n) {
				q.push(make_pair(dx, dy));
				visited[dx][dy] = visited[x][y] + 1;
				cnt = cnt > visited[dx][dy] ? cnt : visited[dx][dy];
			}
		}
	}
}
int main()
{
	cin >> m >> n;
	for (int i = 0; i < m; i++) cin >> map[i];
	cnt = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (map[i][j] == 'L') {
				memset(visited, -1, sizeof(visited));
				bfs(i, j);
			}
	cout << cnt;
	return 0;
}