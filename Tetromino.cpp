#include<iostream>
#include <string.h>
using namespace std;
int n, m, map[500][500], d[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }, ans, sum;
bool visited[500][500];
void dfs(int depth, int x, int y) {
	if (depth == 3) {
		ans = ans > sum ? ans : sum;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int dx = x + d[i][0]; int dy = y + d[i][1];
		if (dx >= 0 && dy >= 0 && dx < n && dy < m && !visited[dx][dy]) {
			visited[dx][dy] = true;
			sum += map[dx][dy];
			dfs(depth + 1, dx, dy);
			sum -= map[dx][dy];
			visited[dx][dy] = false;
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> map[i][j];
	ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			sum = map[i][j];
			visited[i][j] = true;
			dfs(0, i, j);
			visited[i][j] = false;
			int cnt = 0; int temp = 0; int mini = 1000;
			for (int k = 0; k < 4; k++) {
				int dx = i + d[k][0]; int dy = j + d[k][1];
				if (dx < 0 || dy < 0 || dx >= n || dy >= m) {
					cnt++; 
					if (cnt > 1) break;
					continue;
				}
				else {
					temp+=map[dx][dy];
					mini = mini < map[dx][dy] ? mini : map[dx][dy];
				}
			}
			if (cnt == 1) {
				ans = ans > (sum + temp) ? ans : (sum + temp);
			}
			else if (cnt == 0) {
				ans = ans > (sum + temp - mini) ? ans : (sum + temp - mini);
			}//elseµµ ¿÷¿Ω
		}
	cout << ans;
	return 0;
}