#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
int m;
vector<pair<int, int> > house, chicken, temp;
int retDist;
void dfs(int depth, int before) {
	if (depth == m) {
		int ret = 0;
		for (int j = 0; j < house.size(); j++) {
			int minTemp = 999999999;
			for (int k = 0; k < temp.size(); k++) {
				int dist = abs(house[j].first - temp[k].first) + abs(house[j].second - temp[k].second);
				minTemp = minTemp < dist ? minTemp : dist;
			}
			ret += minTemp;
		}
		retDist = retDist < ret ? retDist : ret;
		return;
	}
	for (int i = before; i < chicken.size(); i++) {
		temp.push_back(make_pair(chicken[i].first, chicken[i].second));
		dfs(depth + 1, i+1);
		temp.pop_back();
	}
}
int main()
{
	int n, map[51][51];
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				house.push_back(make_pair(i, j));
			}
			else if (map[i][j] == 2) {
				chicken.push_back(make_pair(i, j));
			}
		}
	}
	retDist = 999999999;
	dfs(0, 0);
	cout << retDist << endl;
}