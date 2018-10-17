#include <iostream>
using namespace std;
#define MAX_N 4002
int n;
int atom[1000][4];
int visited[MAX_N][MAX_N]; // 한 좌표에 몇개의 원자가 왔는지 횟수
bool collide[MAX_N][MAX_N]; // 위에는 계속 줄었다가 늘었다가 해야함으로 충돌했는지 확인하는 변수가 필요
//memset을 써서 visited를 매번 초기화 했더니 속도가 너무 느렸다.
int main()
{
	int tc; cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> atom[i][0] >> atom[i][1] >> atom[i][2] >> atom[i][3];
			atom[i][0] = 2*(atom[i][0] + 1000);	atom[i][1] = 2*(atom[i][1] + 1000);
		}
		int sizeofAtom = n; int ret = 0;
		for (int l = 0; l < MAX_N; l++) {
			//memset(visited, 0, sizeof(visited));
			for (int i = 0; i < sizeofAtom; ++i) {
				int&x = atom[i][0]; int &y = atom[i][1]; int dir = atom[i][2];
				if (dir == 0) y++;
				else if (dir == 1) y--;
				else if (dir == 2) x--;
				else if (dir == 3) x++;
				if (atom[i][0] < 0 || atom[i][1] < 0 || atom[i][0] > 4000|| atom[i][1] >4000) {
					for(int j = 0; j<4; j++)						 //delete
						atom[i][j] = atom[sizeofAtom - 1][j];
					sizeofAtom--; i--;
				}
				else {
					visited[x][y]++;
					if (visited[x][y] >= 2) collide[x][y] = true;	// 2개 이상이 방문하면 충돌
				}
			}
			for (int i = 0; i < sizeofAtom; ++i) {
				int x = atom[i][0]; int y = atom[i][1];
				if (collide[x][y]) {								//충돌한 적이 있는 것만
					if (visited[x][y] == 1) 
						collide[x][y] = false;
					ret += atom[i][3];								
					for (int j = 0; j < 4; j++)						//delete
						atom[i][j] = atom[sizeofAtom - 1][j];
					sizeofAtom--; i--;
				}
				visited[x][y]--;									// 충돌 했든 안 했든 모두 visited를 줄여야
			}

			if (!sizeofAtom) break;
		}
		cout << '#' << t << ' ' << ret << '\n';
	}
	return 0;
}