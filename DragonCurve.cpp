#include <iostream>
#include <vector>
using namespace std;
int map[101][101];
vector<int> v;
int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++) { // 3 3 0 1  4 2 1 3  4 2 2 1
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		v.push_back(d);
		map[x][y] = 1;
		if (d == 0)x++; 
		else if (d == 1) y--; 
		else if (d == 2) x--;
		else if (d == 3) y++; 
		map[x][y] = 1;
		for (int j = 1; j <= g; j++) {
			int size = (int)v.size();
			for (int k = size - 1; k >= 0; k--) {
				if (v[k] == 0) { y--; v.push_back(1); }
				else if(v[k] == 1) { x--; v.push_back(2); }
				else if (v[k] == 2) { y++; v.push_back(3); }
				else if (v[k] == 3) { x++; v.push_back(0); }
				if (x >= 0 && y >= 0 && x <= 100 && y <= 100)
					map[x][y] = 1;
				//else break;
			}
		}
		v.clear();
	}
	int ret = 0;
	for (int i = 0; i <= 100; i++)
		for (int j = 0; j <= 100; j++)
			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1])
				ret++;
	cout << ret;
	return 0;
}