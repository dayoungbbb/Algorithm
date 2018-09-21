#include <iostream>
using namespace std;
int arr[4][8];
bool visited[4];
int ret;

void swap(int n, int dir) {
	int temp;
	if (dir == 1) { // 시계
		temp = arr[n][7];
		for (int i = 7; i > 0; i--) {
			arr[n][i] = arr[n][i - 1];
		}
		arr[n][0] = temp;
	}
	else { //반시계
		temp = arr[n][0];
		for (int i = 0; i < 7; i++) {
			arr[n][i] = arr[n][i + 1];
		}
		arr[n][7] = temp;
	}
}
void dfs(int n, int dir) {
	visited[n] = true;
	if (n - 1 >= 0 && !visited[n - 1]) {
		if (arr[n][6] != arr[n - 1][2]) {
			dfs(n - 1, dir*(-1));
		}
	}
	if (n + 1 <= 4 && !visited[n + 1]) {
		if (arr[n][2] != arr[n + 1][6]) {
			dfs(n + 1, dir*(-1));
		}
	}
	swap(n, dir);
}
int main()
{
	int tc, k, n, dir;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> k;
		
		
		for (int i = 0; i < 4; i++) 
			for (int j = 0; j < 8; j++) 
				cin >> arr[i][j];
			
		for (int i = 0; i < k; i++) {
			cin >> n >> dir;
			memset(visited, false, sizeof(visited));
			dfs(n-1, dir);
		}
		ret = 0;
		for (int i = 0; i < 4; i++) {
			if (arr[i][0]) {
				ret = ret + (1 << i);
			}
		}
		
		cout << "#" << t << " " << ret << endl;
	}
	return 0;
}