#include <iostream>
#include <string.h>
using namespace std;
#define MAX_N 100
int n, map[MAX_N][MAX_N], DIR[4][2] = { { -1,0 },{ 0,1 },{ 1,0 },{ 0,-1 } }; // 0 1 2 3
int info[6][4] = { { 0,0,0,0 },{ 2,3,1,0 },{ 1, 3, 0, 2 },{ 3, 2, 0, 1 },{ 2, 0, 3, 1 },{ 2, 3, 0, 1 } };
struct HOLE {int x, y;}; HOLE hole[11][2];
int main()
{
	int tc; cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n;
		memset(hole, -1, sizeof(hole));
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] > 5) {
				if (hole[map[i][j]][0].x >= 0 || hole[map[i][j]][0].y >= 0) {
					hole[map[i][j]][1].x = i; hole[map[i][j]][1].y = j;
				}
				else {
					hole[map[i][j]][0].x = i; hole[map[i][j]][0].y = j;
				}
			}
		}
		int ret = -1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (!map[i][j]) {
					for (int d = 0; d < 4; d++) {
						int cnt = 0; int ox, oy;	int x = ox = i; int y = oy = j; int dir = d;
						while (1) {
							int dx = x + DIR[dir][0]; int dy = y + DIR[dir][1];
							if (dx < 0 || dy < 0 || dx >= n || dy >= n) { //칸을 벗어났을 때
								cnt++; //벽에 부딪혔기 때문에 카운트 증가
								dir = (dir + 2) % 4; // 값은 그대로 방향을 바꾼다
								dx = x; dy = y;
							}
							if (dx >= 0 && dy >= 0 && dx < n && dy < n) { // 칸 안에 있을 때
								if (map[dx][dy] == 0) {
									x = dx; y = dy; //그대로
								}
								else if (map[dx][dy] > 0 && map[dx][dy] < 6) { // 1~5
									cnt++; // 카운트 증가
									x = dx; y = dy; dir = info[map[dx][dy]][dir];
								}
								else if (map[dx][dy] > 5 && map[dx][dy] < 11) { //6~10
									if ((hole[map[dx][dy]][0].x == dx) && (hole[map[dx][dy]][0].y == dy)) {
										x = hole[map[dx][dy]][1].x; y = hole[map[dx][dy]][1].y;
									}
									else {
										x = hole[map[dx][dy]][0].x; y = hole[map[dx][dy]][0].y;
									}
								}
								else if (map[dx][dy] == -1)
									break;
							}
							if (x == ox && y == oy) break;
						}
						ret = ret > cnt ? ret : cnt;
					}
				}
		cout << '#' << t << ' ' << ret << '\n';
	}
}