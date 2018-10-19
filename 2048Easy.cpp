#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int n;
int map[6][20][20];
bool visited[5][20][20];
struct info { int x, y, num; };
void bruteforce(int depth) {
	if (depth == 5) {
		return;
	}

	for (int k = 0; k < 4; k++) {
		memset(map[depth + 1], 0, sizeof(map[depth + 1]));
		switch (k) {
		case 0:
			for (int i = 0; i < n; i++) {
				queue<info> q;
				for (int j = n - 1; i >= 0; j--) {
					if (map[depth][i][j])
						q.push({ i, j, map[depth][i][j]});
				}
				int start = n - 1;
				while (!q.empty()) {
					int x = q.front().x; int y = q.front().y; int num = q.front.num;
					q.pop();
					if(!q.empty()){
						int dx = q.front().x; int dy = q.front().y; int dnum = q.front.num;
						if(num == dnum)
							
							map[depth + 1][i][start--] = num;
						
					}
					else {
						map[depth + 1][i][start--] = num;
					}
				}
			}
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> map[0][i][j];
	bruteforce(0);
	return 0;
}