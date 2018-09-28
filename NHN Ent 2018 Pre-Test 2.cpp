#include <iostream>
#include <queue>
#include <functional>
using namespace std;
#define MAX_N 10
int n, map[MAX_N][MAX_N], cntRet;
priority_queue<int, vector<int>, greater<int> > pq;
//bool visited[MAX_N][MAX_N];
int d[4][2] = { { 0, 1 },{ 1, 0 },{ 0, -1 },{ -1, 0 } };
void bfs(int x, int y) {
	cntRet++;
	int cnt = 1;
	queue<pair<int, int> > q;
	map[x][y] = 0;//visited[x][y] = true;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i<4; i++) {
			int tx = x + d[i][0];
			int ty = y + d[i][1];
			if (!map[tx][ty] || tx < 0 || ty < 0 || tx >= n || ty >= n) //visited[tx][ty] ||
				continue;
			map[tx][ty] = 0; //visited[tx][ty] = true;
			q.push(make_pair(tx, ty));
			cnt++;
		}
	}
	pq.push(cnt);
}
int main() {

	cin >> n;
	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
			cin >> map[i][j];
	cntRet = 0;

	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
			if (map[i][j]) {
				//memset(visited, false, sizeof(visited));
				bfs(i, j);
			}

	cout << cntRet << endl;
	for (int i = 0; !pq.empty(); i++) {
		cout << pq.top() << " ";
		pq.pop();
	}
	return 0;
}