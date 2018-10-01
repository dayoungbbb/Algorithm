#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 100
int m, n, k, map[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
int amountCnt;
int d[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
void dfs(int x, int y) {
	map[x][y] = ++amountCnt;
	
	for (int i = 0; i < 4; i++) {
		int dx = x + d[i][0]; int dy = y + d[i][1];
		if (dx < 0 || dy < 0 || dx >= m || dy >= n ||map[dx][dy])
			continue;
		dfs(dx, dy);
		
	}
}
int main()
{
	cin >> m >> n >> k;
	int firy, firx, lasty, lastx;
	for (int l = 0; l < k; l++) {
		cin >> firy >> firx >> lasty >> lastx;
		for (int i = firx; i < lastx; i++)
			for (int j = firy; j < lasty; j++)
				map[i][j] = -1;
	}
	int cnt = 0;
	vector<int> v;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (!map[i][j]) {
				cnt++;
				amountCnt = 0;
				dfs(i, j);
				v.push_back(amountCnt);
			}
	sort(v.begin(), v.end());
	cout << cnt << '\n';
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';
	return 0;
}