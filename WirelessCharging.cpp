#include <iostream>
#include <vector>
using namespace std;
int ret;
int m, a;
int user[2][101]; // 유저 정보
int ap[9][4];
int map[11][11];
int d[4][2] = { {-1, 1}, {-1, -1}, {1, -1}, {1, 1} }; // 우상, 좌상, 좌하, 우하
int dir[5][2] = { {0,0}, {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
void makeMap(int bc) {
	bool visited[11][11] = { false, };
	int x = ap[bc][0], y = ap[bc][1], depth = ap[bc][2];
	visited[x][y] = true;
	map[x][y] = map[x][y]*10 + bc;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j <= depth; j++) {
			for (int k = 0; k <= depth; k++) {
				if (j + k > depth)
					continue;
				int tempx = x + d[i][0] * j;
				int tempy = y + d[i][1] * k;
				
				if (tempx < 0 || tempy < 0 || tempx >= 10 || tempy >= 10 || visited[tempx][tempy])
					continue;
				visited[tempx][tempy] = true;
				map[tempx][tempy] = map[tempx][tempy] * 10 + bc;
			}
		}
	}
}
void inputIndex(int alp, int x, int y) {
	user[alp][0] = map[x][y];
	for (int i = 1; i <= m; i++) {
		x += dir[user[alp][i]][0];
		y += dir[user[alp][i]][1];
		user[alp][i] = map[x][y];
	}
}

void calc() {
	int sum = 0;
	for (int i = 0; i <= m; i++) {
		if (user[0][i] == user[1][i] && user[0][i] > 0 && user[0][i] < 10) { // 0이 아니고 각 1개씩이고 값이 같을 시에
			sum += ap[user[0][i]][3];
		}
		else if (user[0][i] > 10 || user[1][i] > 10) {
			int tempMax = 0;

			int ra = user[0][i] >= user[1][i] ? user[0][i] : user[1][i];
			while (ra > 0) {
				
				int ta = ra%10;
				int rb = user[1][i] <= user[0][i] ? user[1][i] : user[0][i];
				int tempSum = ap[ta][3];
				while (rb > 0) {
					int tb = rb%10;
					if (ta != tb)
						tempSum += ap[tb][3];
					rb /= 10;
				}
				tempMax = tempMax > tempSum ? tempMax : tempSum;
				ra /= 10;
			}
			sum += tempMax;
		}
		else { // 그냥 더해
			sum += (ap[user[0][i]][3] + ap[user[1][i]][3]);
		}
	}
	ret = ret > sum ? ret : sum;
}
int main()
{
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> m >> a;
		for (int i = 0; i < 2; i++)
			for (int j = 1; j <= m; j++)
				cin >> user[i][j];
		memset(ap, 0, sizeof(ap));
		memset(map, 0, sizeof(map));
		for (int i = 1; i <= a; i++) {
			cin >> ap[i][1] >> ap[i][0] >> ap[i][2]>> ap[i][3];
			ap[i][0]--; ap[i][1]--;
			makeMap(i);
		}
		
		inputIndex(0, 0, 0);
		inputIndex(1, 9, 9);
		ret = 0;
		calc();
		printf("#%d %d\n", t, ret);
	}
}