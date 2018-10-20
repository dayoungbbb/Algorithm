#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int ans, n, h, w, map[5][15][12], DIR[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
struct info{ int x, y, num; };
void bfs(int now, int col) {
	int next = now + 1;
	queue<info> q;
	bool check = true;
	bool COL[12] = { false, };
	for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) {map[next][i][j] = map[now][i][j];
			if (check && map[now][i][col]) {
				q.push({ i, col, map[now][i][col] });
				check = false;
			}
		}
	while (!q.empty()) {
		int x = q.front().x; int y = q.front().y; int num = q.front().num;
		map[next][x][y] = 0;
		COL[y] = true;
		q.pop();
		for (int i = 1; i < num; i++) {
			for (int d = 0; d < 4; d++) {
				int dx = x + i * DIR[d][0]; int dy = y+ i * DIR[d][1];
				if (dx >= 0 && dy >= 0 && dx < h && dy < w && map[next][dx][dy]) {
					if (map[next][dx][dy] >= 2) {
						q.push({ dx, dy, map[next][dx][dy] });
					}
					else {
						map[next][dx][dy] = 0;
						COL[dy] = true;
					}
				}
			}
		}
	}
	for (int j = 0; j < w; j++) {
		if (COL[j]) {
			vector<int> temp;
			for (int i = h - 1; i >= 0; i--) if (map[next][i][j]) { temp.push_back(map[next][i][j]); map[next][i][j] = 0; }
			int index = h - 1;
			for (int k = 0; k < (int)temp.size(); k++) map[next][index--][j] = temp[k];
		}
	}
}
bool bruteforce(int depth) {
	if (depth == n) {
		int cnt = 0;
		for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) if (map[depth][i][j]) cnt++;
		ans = ans < cnt ? ans : cnt;
		if(!ans) return true;
		else return false;
	}
	for (int i = 0; i < w; i++) {
		bfs(depth, i);
		if(bruteforce(depth + 1)) return true;
	}
	return false;
}
int main()
{
	int tc; cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n >> w >> h;
		for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) cin >> map[0][i][j];
		ans = h * w;
		bruteforce(0);
		cout << '#' << t << ' ' << ans<<'\n';
	}
	return 0;
}