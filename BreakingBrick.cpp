#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
using namespace std;
int map[5][16][13], ret, n, w, h, dir[4][2] = { {0,1}, {1, 0}, {0, -1}, {-1, 0}, };
bool visited[16][13];
void breaking(int depth, int col) {
	memset(visited, false, sizeof(visited));
	queue < pair<int, int> > q;
	for (int j = 0; j < w; j++) {
		for (int i = 0; i < h; i++) {
			if (col==j && map[depth][i][j] && q.empty()) {
				q.push(make_pair(i, col));
				visited[i][col] = true;
			}
			map[depth + 1][i][j] = map[depth][i][j];
		}
	}

	while (!q.empty()) {
		int x = q.front().first; int y = q.front().second;
		q.pop();
		for(int i = 1; i<map[depth+1][x][y]; i++)
			for (int j = 0; j < 4; j++) {
				int dx = x + i * dir[j][0]; int dy = y + i * dir[j][1];
				if (dx >= 0 && dy >= 0 && dx < h && dy < w && !visited[dx][dy] && map[depth+1][dx][dy] > 0) {
					visited[dx][dy] = true;
					if (map[depth+1][dx][dy] > 1) {
						q.push(make_pair(dx, dy));
					}
					else {
						map[depth + 1][dx][dy] = 0;
					}
				}
			}
		map[depth + 1][x][y] = 0;
	}
	
	for (int j = 0; j < w; j++) {
		int k = h - 1;
		for (int i = h-1; i >= 0; i--) {
			if (map[depth + 1][i][j]){
				if (k != i) {
					map[depth + 1][k][j] = map[depth + 1][i][j];
					map[depth + 1][i][j] = 0;
				}
				k--;
			}
		}
	}
}
void dfs(int depth) 
{
	if (depth == n) {
		int sum = 0;
		for (int j = 0; j < w; j++) 
			for (int i = h - 1; i >= 0; i--) {
				if (map[depth][i][j])
					sum++;
				else break;
			}
		ret = ret < sum ? ret : sum;
		return;
	}
	for (int i = 0; i < w; i++) {
		// 0에서 1로 맵을 수정하겠지
		breaking(depth, i);
		// 어차피 맵을 다시 쓰니깐 0은 변하지 않아
		dfs(depth + 1);
	}
}
int main()
{
	int tc; cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n >> w >> h;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> map[0][i][j];
		ret = INT_MAX;
		dfs(0);

		cout << '#' << t << ' ' << ret << '\n';
	}
	return 0;
}