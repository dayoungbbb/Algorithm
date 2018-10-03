#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
vector<pair<int, int> > v;
int main()
{
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;
		int x, y, lx = INT_MAX, ly = INT_MAX, rx = INT_MAX, ry = INT_MAX, cnt = 0;
		v.clear();
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			v.push_back(make_pair(x, y));
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < (int)v.size(); i++) {
			x = v[i].first; y = v[i].second;
			if ((x > lx && y > ly) || (x > rx && y > ry))
				continue;
			cnt++;
			if (x < lx) {
				lx = x; ly = y;
			}
			if (y < ry) {
				rx = x; ry = y;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}