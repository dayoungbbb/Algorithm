#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int map[100][100], n, visited[100][100], cnt;
int DIR[4][2] = { { 0, 1 },{ 1, 0 },{ 0, -1 },{ -1, 0 } };
void bfs(int x, int y, int cnt, int depth) {
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	visited[x][y] = cnt;
	while (!q.empty()) {
		x = q.front().first; y = q.front().second;
		q.pop();
		for (int d = 0; d<4; d++) {
			int dx = x + DIR[d][0]; int dy = y + DIR[d][1];
			if (dx >= 0 && dy >= 0 && dx <n && dy < n && !visited[dx][dy] && map[dx][dy]>depth) {
				visited[dx][dy] = cnt;
				q.push(make_pair(dx, dy));
			}
		}
	}
}
int main() {
	cin >> n;
	int MAX = 0;
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			cin >> map[i][j];
			MAX = MAX > map[i][j] ? MAX : map[i][j];
		}
	}
	int cntMAX = 0;
	for (int k = 0; k<MAX; k++) {
		memset(visited, 0, sizeof(visited));
		cnt = 0;
		for (int i = 0; i<n; i++)
			for (int j = 0; j<n; j++)
				if (map[i][j]>k && !visited[i][j])
					bfs(i, j, ++cnt, k);
		cntMAX = cntMAX > cnt ? cntMAX : cnt;
	}
	cout << cntMAX;
	return 0;
}