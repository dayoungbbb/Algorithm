#include <iostream>
#include <string.h>
using namespace std;
#define MAX_N 500
int m, n, map[MAX_N][MAX_N], dir[4][2] = { { 0, 1 },{ 1, 0 },{ 0, -1 },{ -1 , 0 } };
long long dp[MAX_N][MAX_N];
void dfs(int x, int y) {
	if ((x == m - 1) && (y == n - 1)) {
		dp[x][y] = 1;
		return;
	}
	dp[x][y] = 0;
	for (int d = 0; d < 4; d++) {
		int nx = x + dir[d][0]; int ny = y + dir[d][1];
		if (map[nx][ny] < map[x][y] && nx >= 0 && ny >= 0 && nx < m && ny < n) {
			if (dp[nx][ny] == -1) {
				dfs(nx, ny);
			}
			dp[x][y] += dp[nx][ny];

		}
	}
	//return dp[x][y];
}
int main()
{
	cin >> m >> n;
	for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) cin >> map[i][j];
	memset(dp, -1, sizeof(dp)); // -1�� �ʱ�ȭ����� �� �湮 ���θ� ǥ�����ֱ� ���ؼ�

	dfs(0, 0);
	cout << dp[0][0];

	return 0;
}