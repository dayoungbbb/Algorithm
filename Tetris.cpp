#include <iostream>
using namespace std;
#define MAX_N 100
#define MIN -4000001
#define MAX 4000001
int n, d[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }, num;
int info[4][3] = { {0, 1, 2}, {0, 0, 0}, {0, 1, 0}, {0, 0, 1} };
long long map[MAX_N][MAX_N], ans, sum;
void dfs(int depth, int x, int y) {
	if (depth == 3) {
		ans = ans > sum ? ans : sum;
		return;
	}
	int dx = x + d[info[num][depth]][0]; int dy = y + d[info[num][depth]][1];
	if (dx >= 0 && dy >= 0 && dx < n && dy < n) {
		sum += map[dx][dy];
		dfs(depth + 1, dx, dy);
	}
}
int main()
{
	int tc = 1;
	while ((cin >> n) && n != 0) {
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> map[i][j];
		ans = MIN;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < 5; k++) {
					switch (k) {
					case 0: 
						num = 0;
						sum = map[i][j];
						dfs(0, i, j);
						break;
					case 1:
						num = 1;
						sum = map[i][j];
						dfs(0, i, j);
						for (int l = 0; l < 3; l++) info[1][l]++;
						sum = map[i][j];
						dfs(0, i, j);
						for (int l = 0; l < 3; l++) info[1][l] = 0;
						break;
					case 2:
						num = 2;
						sum = map[i][j];
						dfs(0, i, j);
						for (int l = 0; l < 3; l++) info[2][l]++;
						sum = map[i][j];
						dfs(0, i, j);
						info[2][0] = 0; info[2][1] = 1; info[2][2] = 0;
						break;
					case 3:
						num = 3;
						sum = map[i][j];
						dfs(0, i, j);
						for (int l = 0; l < 3; l++) info[3][l]++;
						sum = map[i][j];
						dfs(0, i, j);
						for (int l = 0; l < 3; l++) info[3][l]++;
						sum = map[i][j];
						dfs(0, i, j);
						for (int l = 0; l < 3; l++) info[3][l] = (info[3][l]+1)%4;
						sum = map[i][j];
						dfs(0, i, j);
						info[3][0] = 0; info[3][1] = 0; info[3][2] = 1;
						break;
					case 4:
						sum = map[i][j];
						int cnt = 4;
						long long tempSum = 0, Min = MAX;
						for (int l = 0; l < 4; l++) {
							int dx = i + d[l][0]; int dy = j + d[l][1];
							if (dx < 0 || dy < 0 || dx >= n || dy >= n) {
								cnt--;
								if (cnt <= 2) break;
							}
							else {
								tempSum += map[dx][dy];
								Min = Min < map[dx][dy] ? Min : map[dx][dy];
							}
						}
						if (cnt == 3) {
							ans = ans > (sum + tempSum )? ans : (sum + tempSum);
						}
						else if (cnt == 4) {
							ans = ans > (sum + tempSum - Min )? ans : (sum + tempSum - Min);
						}
						break;
					}
				}
			}
		}
		cout << tc++ << ". " << ans << '\n';
	}
	
	return 0;
}