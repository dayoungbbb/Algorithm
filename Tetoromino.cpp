#include <iostream>
using namespace std;
#define MAX_N 500
#define SWAP(x,y,type) {type t = x; y = x; x=(-1)*t;}
int n, m, map[MAX_N][MAX_N];
int tet[5][4][3][2] = {	  {{{0, 1}, {1, 0}, {1, 1}}, {{0, 0}, {0, 0}, {0, 0}},  {{0, 0},{ 0, 0 },{ 0, 0 }},{{ 0, 0 },{ 0, 0 },{ 0, 0 } }} // 1
						, {{{0, 1}, {0, 2}, {0, 3}}, {{1, 0}, {2, 0}, {3, 0}},  {{0, 0},{ 0, 0 },{ 0, 0 }},{{ 0, 0 },{ 0, 0 },{ 0, 0 } }} // 2
						, {{{1, 0}, {1, 1}, {2, 1}}, {{0, -1},{1, -1},{1, -2}}, {{1, 0},{1, -1}, {2, -1}}, {{0, 1}, {1, 1}, {1, 2} } }    //4
						,{ { { 0, 1 },{ 0, 2 },{ 1, 1 } },{ { 1, 0 },{ 2, 0 },{ 1, -1 } },{ { 0, -1 },{ 0, -2 },{ -1, -1 } },{ { -1, 0 },{ -2, 0 },{ -1, 1 } } }//ㅜ ㅓ ㅗ ㅏ
						, {{{1, 0}, {2, 0}, {2, 1}}, {{0, -1},{0, -2},{1, -2}}, {{-1,0},{-2, 0},{-2,-1} }, { {0, 1},{0, 2},{-1, 2} } } }; //대칭 더 필요
int chk[3][2];
int check(int x, int y, int tt[3][2]) {
	int sum = map[x][y];

	for (int q = 0; q < 3; q++) {
		int dx = x + tt[q][0]; int dy = y + tt[q][1];
		if (dx < 0 && dy < 0 && dx >= n && dy >= m) return 0; // 하나라도 안되면 가차없이 break
		sum += map[dx][dy];
	}
	return sum;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> map[i][j];
	int sumMax = -1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 5; k++) { // 5개 확인
				int t = k; if (t >= 3) t = 2;
				for (int q = 0; q < (1 << t); q++) { //1, 2, 4, 4, 4
					int x = i, int y = j; int sum = map[x][y];
					for (int t = 0; t < 3; t++) {
						int dx = x + tet[k][q][t][0]; int dy = y + tet[k][q][t][1];
						if (dx < 0 && dy < 0 && dx >= n && dy >= m) { sum = 0; break; }
						sum += map[dx][dy];
					}
					sumMax = sumMax > sum ? sumMax : sum;
					if (k >= 4) {
						int x = i, int y = j; int sum = map[x][y];
						for (int t = 0; t < 3; t++) {
							int dx, dy;
							if (q == 0 || q == 2) { dx = x + tet[k][q][t][0];  dy = y + (-1)*tet[k][q][t][1]; }
							else { dx = x + (-1)*tet[k][q][t][0];  dy = y + tet[k][q][t][1]; }
							if (dx < 0 && dy < 0 && dx >= n && dy >= m) { sum = 0; break; }
							sum += map[dx][dy];
						}
						sumMax = sumMax > sum ? sumMax : sum;
					}
				}
			}
		}
	cout << sumMax;
	return 0;
}