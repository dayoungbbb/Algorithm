#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;
#define MAX_N 1000
int n, m, map[MAX_N][MAX_N], ret, visited[2][MAX_N][MAX_N];
int dir[4][2] = { {0,1}, {1, 0}, {0, -1}, {-1, 0} };
struct info {
	int check, x, y;
};
void bfs()
{
	queue<info> q;
	info temp = { 1, 0, 0 };
	q.push(temp);
	visited[1][0][0] = visited[0][0][0] = 1;
	while (!q.empty()) {
		int x = q.front().x; int y = q.front().y; int check = q.front().check;
		q.pop();
		if (x == n - 1 && y == m - 1) {
			ret = visited[check][x][y];
			return;
		}
		for (int i = 0; i < 4; i++) {
			int dx = x + dir[i][0]; int dy = y + dir[i][1];
			if (dx >= 0 && dy >= 0 && dx < n && dy < m) {
				if (!map[dx][dy] && !visited[check][dx][dy]) {
					visited[check][dx][dy] = visited[check][x][y] + 1;
					temp = { check, dx, dy };
					q.push(temp);
				}
				else if (map[dx][dy] == 1 && check && !visited[0][dx][dy]) {
					visited[0][dx][dy] = visited[check][x][y] + 1;
					temp = { 0, dx, dy };
					q.push(temp);
				}
				// 한번 벽을 부수고 왔을 때는 처리 안해주기 때문에 각자 if문
			}
		}
	}
}
int main()
{	
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%1d", &map[i][j]);
	ret = INT_MAX;
	bfs();
	if (ret == INT_MAX)
		ret = -1;
	cout << ret;
	
	return 0;
}