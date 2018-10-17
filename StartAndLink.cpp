#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>
using namespace std;
int n, map[20][20], ret;
vector<int> v[2];
void com(int depth, int before) {
	if (depth == (n / 2)) {
		for (int i = 0; i < n; i++) {
			bool check = true;
			for (int j = 0; j < (int)v[0].size(); j++)
				if (v[0][j] == i) {
					check = false;
					break;
				}
			if (check)
				v[1].push_back(i);
		}
		int ans[2] = { 0, 0 };
		for (int k = 0; k < 2; k++)
			for (int i = 0; i < (int)v[k].size(); i++)
				for (int j = 0; j < (int)v[k].size(); j++)
					if (v[k][i] != v[k][j])
						ans[k] += map[v[k][i]][v[k][j]];
		ret = ret < abs(ans[0] - ans[1]) ? ret : abs(ans[0] - ans[1]);
		v[1].clear();
		return;
	}
	for (int i = before + 1; i < n; i++) {
		v[0].push_back(i);
		com(depth + 1, i);
		v[0].pop_back();
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> map[i][j];
	ret = INT_MAX;
	com(0, -1);
	cout << ret;
	return 0;
}