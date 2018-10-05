#include <iostream>
using namespace std;
#define MAX_N 50
int n, m, map[MAX_N][MAX_N], cnt, visited[MAX_N][MAX_N]; // 좌표(r,c), 바라보는 방향 d 0북1동2남3서
int dir[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };// 서북동남

void dfs(int r, int c, int d)
{
	map[r][c] = 2;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int j = (4 + d) % 4;
		int nx = r + dir[j][0]; int ny = c + dir[j][1];
		if (nx >= 0 && ny >= 0 && nx < n && ny < m && !map[nx][ny]) {
			dfs(nx, ny, (d + 3) % 4);
			break;
		}
		d = (d + 3) % 4;
		if (i == 3) {
			nx = r + dir[(d + 3) % 4][0]; ny = c + dir[(d + 3) % 4][1];
			if (map[nx][ny] == 1)
				break;
			if ((map[nx][ny]!=1) && nx >= 0 && ny >= 0 && nx < n && ny < m) {
				r = nx; c = ny;
				i = -1;
				continue;
			}
		}
	}
}
int main()
{
	int r, c, d;
	cin >> n >> m >> r >> c >> d;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	dfs(r, c, d);
	cout << cnt<<'\n';
	return 0;
}