#include <iostream>
#include <queue>
using namespace std;
#define MAX_N 1001
int n, m, arr[MAX_N][MAX_N];
bool visited[MAX_N];
void bfs(int x) {
	queue<int> q;
	visited[x] = true;
	q.push(x);
	while (!q.empty()) {
		x = q.front();
		q.pop();
		for (int i = 1; i <= n; i++)
			if (arr[x][i] && !visited[i]) {
				visited[i] = true;
				q.push(i);
			}
	}
}
int main()
{
	cin >> n >> m;
	int start, end;
	for (int i = 0; i < m; i++) {
		cin >> start >> end;
		arr[start][end] = arr[end][start]=1;
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			bfs(i);
			cnt++;
		}
	}
	cout << cnt;
}