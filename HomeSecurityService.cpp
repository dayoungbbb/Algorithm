#include <iostream>
#include <string.h>
using namespace std;
#define MAX_N 22

int main()
{
	int tc; cin >> tc;
	int n, m, map[MAX_N][MAX_N], dir[4][2] = { { -1, 1 },{ 1, 1 },{ 1, -1 },{ -1, -1 } };
	bool vt[MAX_N][MAX_N];

	for (int t = 1; t <= tc; t++) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cin >> map[i][j];

		int maxCnt = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				memset(vt, false, sizeof(vt));
				int cntHome = 0;
				for (int k = 1; k <= n + 1; k++) {
					for (int q = 0; q < 4; q++) {
						for (int p = 0; p < k; p++) {
							int nx = i + dir[q][0] * (k-1 - p); int ny = j + dir[q][1] * p;
							if (!vt[nx][ny] && nx >= 1 && ny >= 1 && nx <= n && ny <= n) {
								vt[nx][ny] = true;
								if (map[nx][ny]) cntHome++;
							}
						}
					}
					if ((m*cntHome - (k*k + ((k - 1)*(k - 1)))) >= 0) {
						if (cntHome > maxCnt)
							maxCnt = cntHome;
					}
				}
			}
	
		cout << "#" << t << ' ' << maxCnt << '\n';
	}
	return 0;
}