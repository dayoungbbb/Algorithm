#include <iostream>
#include <queue>
using namespace std;
#define MAX_N 1000
int n, m, map[MAX_N][MAX_N];
queue <pair<int, int> > q;
int d[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
void bfs()
{
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = x + d[i][0];
			int ty = y + d[i][1];
			if ((map[tx][ty] != 0) || tx < 0 || ty < 0 || tx >= n || ty >= m)
				continue;
			map[tx][ty] = map[x][y] + 1;
			q.push(make_pair(tx, ty));
		}
	}

}
int main()
{
	cin >> m >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j]>0)
				q.push(make_pair(i, j));
		}
	bfs();
	int ret = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				cout << "-1";
				return 0;
			}
			if (map[i][j] > 1)
				ret = ret > map[i][j] ? ret : map[i][j];
		}
	if (ret == 1)
		ret = 0;
	else
		ret--;
	cout << ret;
}