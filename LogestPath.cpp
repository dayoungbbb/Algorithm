#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
bool visited[11];
int n, m, ret;
vector<pair<int, int> > v;
void bruteforce(int depth, int before) {
	if (depth == n) {
		return;
	}
	visited[before] = true;
	for (int j = 0; j < m; j++) {
		if (v[j].first == before && !visited[v[j].second]){
			bruteforce(depth + 1, v[j].second);
		}
		else if (v[j].second == before && !visited[v[j].first]) {
			bruteforce(depth + 1, v[j].first);
		}
	}
	ret = ret > depth+1 ? ret : depth+1;
	visited[before] = false;
}

int main()
{
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n >> m;
		int x, y;
		v.clear();
		ret = 1;
		for (int i = 0; i < m; i++) {
			cin >> x >> y;
			v.push_back(make_pair(x, y));
		}
		if (n != 1) {
			for (int i = 1; i <= n; i++) {
				memset(visited, false, sizeof(visited));
				bruteforce(0, i);
			}
		}
		printf("#%d %d\n", t, ret);
	}
	return 0;
}
