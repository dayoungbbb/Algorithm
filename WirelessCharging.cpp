#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
#define apNum 8+1 
#define MAX_N 10+1
#define M_MOVE 100+1
int ret, m, a, moveInfo[2][M_MOVE], map[MAX_N][MAX_N], dir[4][2] = { { -1,1 },{ 1,1 },{ -1,-1 },{ 1,-1 } }, dr[5][2] = { { 0, 0 },{ -1, 0 },{ 0, 1 },{ 1, 0 },{ 0, -1 } };
bool visited[MAX_N][MAX_N];
struct AP {
	int x, y, c, p;
};
AP ap[apNum];
struct info {
	int x, y;
};
int main()
{
	int tc; cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> m >> a;
		for (int j = 0; j < 2; j++) for (int i = 1; i <= m; i++) cin >> moveInfo[j][i];
		memset(map, 0, sizeof(map));
		for (int i = 1; i <= a; i++) {
			cin >> ap[i].y >> ap[i].x >> ap[i].c >> ap[i].p; // 여기까지 입력

			memset(visited, false, sizeof(visited));
			for (int j = 0; j <= ap[i].c; j++)
				for (int d = 0; d<4; d++)
					for (int k = 0; k <= j; k++) {
						int dx = ap[i].x + dir[d][0] * (k); int dy = ap[i].y + dir[d][1] * (j - k);
						if (!visited[dx][dy] && dx >= 1 && dy >= 1 && dx <= 10 && dy <= 10) {
							visited[dx][dy] = true;
							map[dx][dy] = map[dx][dy] * 10 + i;
						}
					}
		}
		int ret = 0;
		info user[2] = { { 1, 1 },{ 10, 10 } };
		vector<int> v[2];
		for (int tm = 0; tm <= m; tm++) {
			for (int i = 0; i < 2; i++) {
				user[i].x += dr[moveInfo[i][tm]][0];
				user[i].y += dr[moveInfo[i][tm]][1];

				int temp = map[user[i].x][user[i].y]; // map의 값이 0이 되는 것도 넣어야
				do {
					v[i].push_back(temp % 10);
					if (temp != 0) temp /= 10;
				} while (temp);
			}
			int MAX = 0;
			for (int i = 0; i<(int)v[0].size(); i++)
				for (int j = 0; j < (int)v[1].size(); j++) {
					if (v[0][i] == v[1][j])
						MAX = MAX > ap[v[0][i]].p ? MAX : ap[v[0][i]].p;
					else
						MAX = MAX > ap[v[0][i]].p + ap[v[1][j]].p ? MAX : ap[v[0][i]].p + ap[v[1][j]].p;
				}
			v[0].clear(); v[1].clear();
			
			ret += MAX;
		}

		cout << "#" << t << ' ' << ret << '\n';
	}
	return 0;
}