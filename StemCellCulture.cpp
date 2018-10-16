#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
#define MAX_N 350
int n, m, k, map[MAX_N][MAX_N], visited[MAX_N][MAX_N];
int d[4][2] = { { -1, 0 },{ 0, 1 },{ 1, 0 },{ 0, -1 } };
int main()
{
	int tc; cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n >> m >> k;
		for (int i = 0; i < MAX_N; i++) for (int j = 0; j < MAX_N; j++)  map[i][j] = visited[i][j] = -12;
		int temp;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
			cin >> temp;
			if (temp) visited[i + k/2][j + k/2] = map[i + k/2][j + k/2] = temp;
		}
		for (int l = 0; l < k; l++) {
			for (int i = 0; i < n+k; i++)
				for (int j = 0; j < m+k; j++) {
					if (!visited[i][j]) {
						for (int p = 0; p < 4; p++) {
							int dx = i + d[p][0]; int dy = j + d[p][1];
							if (visited[dx][dy] == -12)
								map[dx][dy] = map[dx][dy] > map[i][j] ? map[dx][dy] : map[i][j];
						}
					}
					if (visited[i][j] > -11) {
						visited[i][j]--;
						if (abs(visited[i][j]) == map[i][j])
							visited[i][j] = -11;
					}
				}
			for (int i = 0; i < n+k; i++)
				for (int j = 0; j < m+k; j++)
					if (map[i][j] > 0 && visited[i][j] == -12)
						visited[i][j] = map[i][j];
		}
		int ret = 0;
		for (int i = 0; i < n+k; i++)
			for (int j = 0; j < m+k; j++)
				if (visited[i][j] > -11)
					ret++;

		cout << '#' << t << ' ' << ret << '\n';
	}
	return 0;
}