#include <iostream>
#include <vector>
#include <string.h>
#include <limits.h>
using namespace std;
#define MAX_N 12
int n, map[MAX_N][MAX_N], dir[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} }, cnt, ret;
vector<pair<int, int> > v;
bool visited[MAX_N];
int goCnt, prevCnt;
int dfs(int cx, int cy, int d, bool draw) {
	int dx, dy, x = cx, y = cy;
	if (draw) {
		while (1) {
			dx = x + dir[d][0]; dy = y + dir[d][1];
			if (dx < 0 || dy < 0 || dx >= n || dy >= n)
				break;
			if (map[dx][dy])
				return -1;
			x = dx; y = dy;

		}
	}
	x = cx; y = cy;
	while (x > 0 && y > 0 && x < n - 1 && y < n - 1) {
		dx = x + dir[d][0]; dy = y + dir[d][1];
		if (draw)
			map[dx][dy] = ++cnt;
		else {
			map[dx][dy] = 0;
			cnt--;
		}
		x = dx; y = dy;
	}
	return 0;
}
void bruteforce(int depth) {

	if (depth == v.size()) {
		if (goCnt ==prevCnt) {
			ret = ret < cnt ? ret : cnt;	
		}
		else if (goCnt > prevCnt) {
			ret = cnt;
			prevCnt = goCnt;
		}
		return;
	}
	int temp = 0;
	for (int i = 0; i < 4; i++) {
		if (!dfs(v[depth].first, v[depth].second, i, true)) {
			goCnt++;
			bruteforce(depth + 1);
			dfs(v[depth].first, v[depth].second, i, false);
			goCnt--;
		}
		else {
			temp++;
			if (temp == 4)
				bruteforce(depth + 1);
		}
	}


}
int main()
{
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n;
		memset(map, 0, sizeof(map));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j] && i != 0 && j != 0 && i != n - 1 && j != n - 1)
					v.push_back(make_pair(i, j));
			}

		cnt = 0; ret = INT_MAX;
		goCnt = 0; prevCnt = 0;
		bruteforce(0);


		if (ret == INT_MAX)
			ret = 0;

		cout << "#" << t << ' ' << ret << '\n';
		v.clear();
	}
	return 0;
}

