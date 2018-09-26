#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int map[101][101], retMap[101][101];
bool v[101][101];
int n, d[4][2] = { { -1, 0 }, {0, 1}, {1, 0}, {0, -1} };
void bfs(int x, int y) 
{
	queue<pair<int, int>> q;
	v[x][y] = true;
	q.push(make_pair(x, y));
	retMap[x][y] = map[x][y];
	while (!q.empty()) {
		x = q.front().first; y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = x + d[i][0]; int ty = y + d[i][1];
			if (tx < 0 || ty < 0 || tx >= n || ty >= n)
				continue;
			if (v[tx][ty]) {//방문한 적이 있을 때 적은 값이라면 이동
				if (retMap[tx][ty] > retMap[x][y] + map[tx][ty]) {
					retMap[tx][ty] = retMap[x][y] + map[tx][ty];
					q.push(make_pair(tx, ty));
				}
			}
			else { //방문한 적이 없을 때
				retMap[tx][ty] = map[tx][ty]+retMap[x][y];
				v[tx][ty] = true;
				q.push(make_pair(tx, ty));
			}
		}
	}
}
int main()
{
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				scanf("%1d", &map[i][j]);			
			}
		memset(v, false, sizeof(v));
		memset(retMap, 0, sizeof(retMap));
		bfs(0, 0);

		printf("#%d %d\n", t, retMap[n-1][n-1]);
	}
	return 0;
}