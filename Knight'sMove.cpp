#include <iostream>
#include <queue>
#include <string.h>
#define MAX_N 300
using namespace std;
int l, targetx, targety, visited[MAX_N][MAX_N];
int d[8][2] = { {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2} };
void bfs(int x, int y) {
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	//visited[x][y] = 1;
	while (!q.empty()) {
		x = q.front().first; y = q.front().second;
		q.pop();
		if (x == targetx && y == targety)
			return;
		for (int i = 0; i < 8; i++) {
			int dx = x + d[i][0]; int dy = y + d[i][1];
			if (visited[dx][dy] || dx < 0 || dy < 0 || dx >= l || dy >= l)
				continue;
			visited[dx][dy] = visited[x][y] +1;
			q.push(make_pair(dx, dy));
		}
	}
}
int main()
{
	int tc, startx, starty;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		cin >> l;
		cin >> startx >> starty;
		cin >> targetx >> targety;
		memset(visited, 0, sizeof(visited));
		bfs(startx, starty);
		cout << visited[targetx][targety] << '\n';
	}
	return 0;
}