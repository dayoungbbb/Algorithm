#include <iostream>
using namespace std;
#define MAX_NM 20
int map[MAX_NM][MAX_NM], d[5][2] = { {0,0},{0, 1}, {0, -1}, {-1, 0}, {1, 0} }, dice[7], ndice[7]; // ����, �ֻ���
int dir; //�Է¹޴� ���� 1 �� 2 �� 3 �� 4 ��
void changeDice() { 
	// 6�� ��, 1�� �� ���� 5�� �������� ��
	if (dir == 1) {			// ��
		ndice[1] = dice[4];
		ndice[3] = dice[1];
		ndice[4] = dice[6];
		ndice[6] = dice[3];
	}
	else if (dir == 2) {	// ��
		ndice[1] = dice[3];
		ndice[3] = dice[6];
		ndice[4] = dice[1];
		ndice[6] = dice[4];
	}
	else if (dir == 3) {	// ��
		ndice[1] = dice[5];
		ndice[2] = dice[1];
		ndice[5] = dice[6];
		ndice[6] = dice[2];
	}
	else {					// ��
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
			changeDice();						// �ֻ��� �̵�
			if (!map[dx][dy]) {					// ���� ���� 0�̸�
				map[dx][dy] = ndice[6];			// �ֻ����� ������ ���� �ٴڸ��� ����
			}
			else {								// �ʿ� ���� �ֵ���
				ndice[6] = map[dx][dy];
				map[dx][dy] = 0;
			}
			cout << ndice[1] << '\n';			// �ֻ��� ���� ���
			for (int i = 1; i < 7; i++) dice[i] = ndice[i];
			x = dx; y = dy;
		}
	}
	return 0;
}