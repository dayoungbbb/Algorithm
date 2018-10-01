#include <iostream>
#include <queue>
using namespace std;
#define MAX_N 101
int n, map[MAX_N][MAX_N];
bool visited[MAX_N];
int cnt;
void bfs(int x)
{
	visited[x] = true;
	queue<int> q;
	q.push(x);
	while (!q.empty() ){
		int dx = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (map[dx][i] && !visited[i]) {
				q.push(i);
				visited[i] = true;
				cnt++;
			}
		}
	}
	
}
int main()
{
	int m, x, y;
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		map[x][y] = map[y][x]= 1;
	}
	bfs(1);
	cout << cnt;
	return 0;
}