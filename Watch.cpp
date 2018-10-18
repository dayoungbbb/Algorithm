#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
int n, m, map[8][8], cctv_size, visited[8][8], ret;
struct cctv { int x, y, dir, num; };
vector<cctv> v;
bool com(const cctv &a, const cctv &b) {
	return a.num > b.num;
}
void spread(int x, int y, int dir) {
	switch (dir) {
	case 0:
		for (y++; y < m; y++) {
			if (visited[x][y] == 6) break;
			if (visited[x][y] > 0 && visited[x][y] < 6) continue;
			visited[x][y] = -1;
		}
		break;
	case 1:
		for (x++; x < n; x++) {
			if (visited[x][y] == 6) break;
			if (visited[x][y] > 0 && visited[x][y] < 6) continue;
			visited[x][y] = -1;
		}
		break;
	case 2:
		for (y--; y >=0; y--) {
			if (visited[x][y] == 6) break;
			if (visited[x][y] > 0 && visited[x][y] < 6) continue;
			visited[x][y] = -1;
		}
		break;
	case 3:
		for (x--; x >=0; x--) {
			if (visited[x][y] == 6) break;
			if (visited[x][y] > 0 && visited[x][y] < 6) continue;
			visited[x][y] = -1;
		}
		break;
	}
}
bool bruteforce(int depth) {
	if (depth == cctv_size) {
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) visited[i][j] = map[i][j];
		for (int i = 0; i < cctv_size; i++) {
			switch (v[i].num) {
			case 1:
				if (v[i].dir == 0) spread(v[i].x, v[i].y, 0);
				else if (v[i].dir == 1) spread(v[i].x, v[i].y, 1);
				else if (v[i].dir == 2) spread(v[i].x, v[i].y, 2);
				else if (v[i].dir == 3) spread(v[i].x, v[i].y, 3);
				break;
			case 2:
				if (v[i].dir == 0 || v[i].dir == 2) {
					spread(v[i].x, v[i].y, 0);
					spread(v[i].x, v[i].y, 2);
				}
				else if (v[i].dir == 1 || v[i].dir == 3) {
					spread(v[i].x, v[i].y, 1);
					spread(v[i].x, v[i].y, 3);
				}
				break;
			case 3:
				if (v[i].dir == 0) {
					spread(v[i].x, v[i].y, 0);
					spread(v[i].x, v[i].y, 1);
				}
				else if (v[i].dir == 1) {
					spread(v[i].x, v[i].y, 1);
					spread(v[i].x, v[i].y, 2);
				}
				else if (v[i].dir == 2) {
					spread(v[i].x, v[i].y, 2);
					spread(v[i].x, v[i].y, 3);
				}
				else if (v[i].dir == 3) {
					spread(v[i].x, v[i].y, 3);
					spread(v[i].x, v[i].y, 0);
				}
				break;
			case 4:
				if (v[i].dir == 0) {
					spread(v[i].x, v[i].y, 1);
					spread(v[i].x, v[i].y, 2);
					spread(v[i].x, v[i].y, 3);
				}
				else if (v[i].dir == 1) {
					spread(v[i].x, v[i].y, 0);
					spread(v[i].x, v[i].y, 2);
					spread(v[i].x, v[i].y, 3);
				}
				else if (v[i].dir == 2) {
					spread(v[i].x, v[i].y, 0);
					spread(v[i].x, v[i].y, 1);
					spread(v[i].x, v[i].y, 3);
				}
				else if (v[i].dir == 3) {
					spread(v[i].x, v[i].y, 0);
					spread(v[i].x, v[i].y, 1);
					spread(v[i].x, v[i].y, 2);
				}
				break;
			case 5:spread(v[i].x, v[i].y, 0);
				   spread(v[i].x, v[i].y, 1);
				   spread(v[i].x, v[i].y, 2);
				   spread(v[i].x, v[i].y, 3);
				   break;
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (!visited[i][j])
					cnt++;
		ret = ret < cnt ? ret : cnt;
		if (ret) return false;
		else return true;
	}
	for (int i = 0; i < 4; i++) {
		v[depth].dir = i;
		if(bruteforce(depth + 1)) return true;
	}
	return false;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0 && map[i][j] != 6)
				v.push_back({ i, j, 0, map[i][j] });
		}
	cctv_size = (int)v.size();
	ret = INT_MAX;
	sort(v.begin(), v.end(), com);
	bruteforce(0);
	cout << ret;
	return 0;
}