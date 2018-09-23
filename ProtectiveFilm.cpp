#include <iostream>
using namespace std;
#define INF 999999999
int D, W, K, map[14][21], ret;
int find()
{
	for (int j = 0; j < W; j++) {
		int cnt = 1, tempNum = map[0][j];
		for (int i = 1; i < D; i++) {
			if (cnt >= K)
				break;
			if (map[i][j] == tempNum) {
				cnt++;
			}
			else {
				tempNum = map[i][j];
				cnt = 1;
			}
		}
		if (cnt < K) {
			return 1;
		}
	}
	return 0;
}
void dfs(int depth, int before) {
	int arr[21];
	if (depth == D) {
		ret = ret < depth? ret : depth;
		return;
	}
	for (int i = before+1; i < D; i++) {
		for (int m = 0; m < W; m++) {
			arr[m] = map[i][m];
		}
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < W; k++) {
				map[i][k] = j;
			}
			if (find()) { // 아직도 약품 처리를 해야 한다
				dfs(depth + 1, i);
			}
			else { // 성공
				ret = ret < depth + 1 ? ret : depth + 1;
			}
		}
		for (int l = 0; l < W; l++) {
			map[i][l] = arr[l];
		}
	}

}
int main()
{
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> D >> W >> K;
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				cin >> map[i][j];
			}
		}
		ret = INF;
		if (find()) { //약품 처리해야 한다
			dfs(0, -1);
		}
		if (ret == INF) {
			ret = 0;
		}
		printf("#%d %d\n", t, ret);
	}
	return 0;
}