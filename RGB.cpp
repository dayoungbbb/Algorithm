#include <iostream>
#include <string.h>
using namespace std;
#define MAX_N 100
int n;
char map[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int d[4][2] = { { 0, 1 },{ 1, 0 },{ 0, -1 },{ -1, 0 } };
void dfs(int x, int y, bool check) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int tx = x + d[i][0];
		int ty = y + d[i][1];

		if (tx < 0 || ty < 0 || tx >= n || ty >= n || visited[tx][ty])
			continue;
		if (!check) { // 따로 구분
			if (map[x][y] != map[tx][ty])
				continue;
		}
		else {
			if (map[x][y] != 'B' && map[tx][ty] == 'B')
				continue;
			if (map[x][y] == 'B' && map[x][y] != map[tx][ty])
				continue;
		}
		dfs(tx, ty, check);
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	int cnt = 0, bCnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (!visited[i][j]) {
				dfs(i, j, false);
				cnt++;
			}
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (!visited[i][j]) {
				dfs(i, j, true);
				bCnt++;
			}
	cout << cnt << " " << bCnt;
}