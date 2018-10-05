#include <iostream>
#include <queue>
using namespace std;
#define MAX_N 50
int n, m, map[MAX_N][MAX_N], visited[MAX_N][MAX_N], dir[4][2] = { { 0, -1 },{ -1, 0 },{ 0, 1 },{ 1, 0 } };
int square[MAX_N*MAX_N], cntRoom; // square:각 방의 넓이를 저장하는 변수
void bfs(int x, int y) {
	square[cntRoom] = 1;
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	visited[x][y] = cntRoom;
	while (!q.empty()) {
		x = q.front().first; y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (map[x][y] & (1 << i)) // 벽이 있다면 통과
				continue;
			int nx = x + dir[i][0]; int ny = y + dir[i][1];
			if (!visited[nx][ny] && nx >= 0 && ny >= 0 && nx < m && ny < n) {
				visited[nx][ny] = cntRoom;
				square[cntRoom]++;
				q.push(make_pair(nx, ny));
			}
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	int maxRoom = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (!visited[i][j]) {
				cntRoom++;
				bfs(i, j);
				maxRoom = maxRoom > square[cntRoom] ? maxRoom : square[cntRoom];
				// 제일 큰 방의 넓이를 구한다
			}
	int ridMax = 0; // 벽을 제거 했을 때 가장 큰 방의 넓이
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			int room = visited[i][j];
			int nr = visited[i][j];
			for (int k = 2; k < 4; k++) { // 오른쪽, 아래로 탐색
				int nx = i + dir[k][0]; int ny = j + dir[k][1];
				if ( nx >= m || ny >= n)
					continue;
				nr = visited[nx][ny];
			}
			if (room != nr) { // 방의 번호가 다르다면 벽을 허물고 합칠 수 있으니
				ridMax = ridMax >(square[room] + square[nr]) ? ridMax : (square[room] + square[nr]);
			}
		}

	cout << cntRoom << '\n' << maxRoom << '\n' << ridMax << '\n';
	return 0;
}

