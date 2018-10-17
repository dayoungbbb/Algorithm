#include <iostream>
#include <string.h>
using namespace std;
int map[32][12], n, m, h, limit;
bool com(int depth, int before) {
	if (depth == limit) { //제대로 가는지 확인
		for (int j = 1; j <= n; j++) {
			int y = j; bool visited[32][12] = { false, };
			for (int i = 1; i <= h + 1; i++) {
				visited[i][y] = true;
				if (map[i][y] == y + 1 && !visited[i][y + 1]) {
					y++; visited[i][y + 1] = true;
				}
				else if (map[i][y] == y - 1 && !visited[i][y - 1]) {
					y--; visited[i][y - 1] = true;
				}
			}
			if (y != j)
				return false;
		}
		return true;
	}
	for (int j = before; j < n; j++) {
		for (int i = 1; i <= h; i++) {
			if (map[i][j] == -1 && map[i][j + 1] == -1 && map[i][j - 1] != j) {
				map[i][j] = j + 1; map[i][j + 1] = j;
				if (com(depth + 1, j)) {
					return true; break;
				}
				map[i][j] = -1; map[i][j + 1] = -1;
			}
		}
	}
	return false;
}
int main()
{
	cin >> n >> m >> h;
	int tx, ty;
	memset(map, -1, sizeof(map));
	for (int i = 0; i < m; i++) {
		cin >> tx >> ty;
		map[tx][ty] = ty + 1;  map[tx][ty + 1] = ty;
	}
	int ret = 4;
	for (int l = 0; l <= 3; l++) {

		limit = l;
		if (com(0, 1)) {
			ret = l; break;
		}
	}
	if (ret == 4)
		ret = -1;
	cout << ret;
	return 0;
}