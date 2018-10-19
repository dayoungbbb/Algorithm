#include <iostream>
using namespace std;
#define MAX_NM 20
int map[MAX_NM][MAX_NM], d[5][2] = { {0,0},{0, 1}, {0, -1}, {-1, 0}, {1, 0} }, dice[7], ndice[7]; // 방향, 주사위
int dir; //입력받는 방향 1 동 2 서 3 북 4 남
void changeDice() { 
	// 6이 밑, 1이 위 앞이 5로 가정했을 때
	if (dir == 1) {			// 동
		ndice[1] = dice[4];
		ndice[3] = dice[1];
		ndice[4] = dice[6];
		ndice[6] = dice[3];
	}
	else if (dir == 2) {	// 서
		ndice[1] = dice[3];
		ndice[3] = dice[6];
		ndice[4] = dice[1];
		ndice[6] = dice[4];
	}
	else if (dir == 3) {	// 북
		ndice[1] = dice[5];
		ndice[2] = dice[1];
		ndice[5] = dice[6];
		ndice[6] = dice[2];
	}
	else {					// 남
		ndice[1] = dice[2];
		ndice[2] = dice[6];
		ndice[5] = dice[1];
		ndice[6] = dice[5];
	}
}
int main()
{
	int n, m, x, y, k; cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> map[i][j];
	while (k--) {
		cin >> dir;
		int dx = x + d[dir][0]; int dy = y + d[dir][1];
		if (dx >= 0 && dy >= 0 && dx < n && dy < m) {
			changeDice();						// 주사위 이동
			if (!map[dx][dy]) {					// 맵의 값이 0이면
				map[dx][dy] = ndice[6];			// 주사위를 굴렸을 때의 바닥면을 복사
			}
			else {								// 맵에 값이 있따면
				ndice[6] = map[dx][dy];
				map[dx][dy] = 0;
			}
			cout << ndice[1] << '\n';			// 주사위 윗면 출력
			for (int i = 1; i < 7; i++) dice[i] = ndice[i];
			x = dx; y = dy;
		}
	}
	return 0;
}