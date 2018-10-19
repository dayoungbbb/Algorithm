#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX_N 100
int n, map[MAX_N][MAX_N], D[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
bool visited[MAX_N][MAX_N];
vector<pair<int, char> >v;
int main()
{
	cin >> n;
	int k; cin >> k;
	while (k--) { int x, y; cin >> x >> y; map[x - 1][y - 1] = 1; }
	int l; cin >> l;
	while (l--) { int inpT; char inpC; cin >> inpT >> inpC; v.push_back(make_pair(inpT, inpC)); }
	int ans = 0;
	int x = 0, y = 0, tx = 0, ty = 0, dir = 0;
	queue<pair<int, int> > q;
	visited[x][y] = true; q.push(make_pair(x, y));

	int cnt = 0; int v_size = (int)v.size();
	while (++ans) {
		int dx = x + D[dir][0]; int dy = y + D[dir][1];
		if (dx < 0 || dy < 0 || dx >= n || dy >= n || visited[dx][dy]) {
			break;
		}
		visited[dx][dy] = true; // 사과가 있든 없든 머리는 움직인다
		q.push(make_pair(dx, dy));
		if (!map[dx][dy]) { // 사과가 없다면
			tx = q.front().first; ty = q.front().second;
			visited[tx][ty] = false;
			q.pop();
		}
		else if (map[dx][dy]) { // 사과가 있다면
			map[dx][dy] = 0;
		}
		x = dx; y = dy;
		if (cnt != v_size) {
			if (ans == v[cnt].first) {
				if (v[cnt].second == 'D') { // 오른쪽
					dir++;
					if (dir == 4)
						dir = 0;
				}
				else if (v[cnt].second == 'L') { // 왼쪽
					dir--;
					if (dir == -1)
						dir = 3;
				}
				cnt++;
			}
		}
	}

	cout << ans;
	return 0;
}