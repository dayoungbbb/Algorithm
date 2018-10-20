#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int n, map[6][20][20], limit, ans;
vector<int> seq;
void left(int now) {
	int next = now + 1;
	for (int i = 0; i < n; i++) {
		vector<int> v;
		for (int j = 0; j < n; j++) {
			if (map[now][i][j])
				v.push_back(map[now][i][j]);
		}
		if (!v.empty()) {
			int num = v[0];
			for (int k = 1; k < (int)v.size(); k++) {
				if (num == v[k]) {
					v[k - 1] *= 2;
					v[k] = 0;
				}
				num = v[k];
			}
			int index = 0;
			for (int k = 0; k < (int)v.size(); k++)
				if(v[k])
					map[next][i][index++] = v[k];
		}
	}
}
void up(int now) {
	int next = now + 1;
	for (int i = 0; i < n; i++) {
		vector<int> v;
		for (int j = 0; j < n; j++) {
			if (map[now][j][i])
				v.push_back(map[now][j][i]);
		}
		if (!v.empty()) {
			int num = v[0];
			for (int k = 1; k < (int)v.size(); k++) {
				if (num == v[k]) {
					v[k - 1] *= 2;
					v[k] = 0;
				}
				num = v[k];
			}
			int index = 0;
			for (int k = 0; k < (int)v.size(); k++)
				if (v[k])
					map[next][index++][i] = v[k];
		}
	}
}
void right(int now) {
	int next = now + 1;
	for (int i = 0; i < n; i++) {
		vector<int> v;
		for (int j = n-1; j >= 0; j--) {
			if (map[now][i][j])
				v.push_back(map[now][i][j]);
		}
		if (!v.empty()) {
			int num = v[0];
			for (int k = 1; k < (int)v.size(); k++) {
				if (num == v[k]) {
					v[k - 1] *= 2;
					v[k] = 0;
				}
				num = v[k];
			}
			int index = n-1;
			for (int k = 0; k < (int)v.size(); k++)
				if (v[k])
					map[next][i][index--] = v[k];
		}
	}
}
void down(int now) {
	int next = now + 1;
	for (int i = 0; i < n; i++) {
		vector<int> v;
		for (int j = n - 1; j >= 0; j--) {
			if (map[now][j][i])
				v.push_back(map[now][j][i]);
		}
		if (!v.empty()) {
			int num = v[0];
			for (int k = 1; k < (int)v.size(); k++) {
				if (num == v[k]) {
					v[k - 1] *= 2;
					v[k] = 0;
				}
				num = v[k];
			}
			int index = n-1;
			for (int k = 0; k < (int)v.size(); k++)
				if (v[k])
					map[next][index--][i] = v[k];
		}
	}
}
bool bruteforce(int depth) {
	if (depth == limit) {
		int cnt = 0, Max= 0;
		for (int i = 0; i < (int)seq.size(); i++) {
			memset(map[i + 1], 0, sizeof(map[i + 1]));
			switch (seq[i]) {
			case 0:
				left(i);
				break;
			case 1:
				up(i);
				break;
			case 2:
				right(i);
				break;
			case 3:
				down(i);
				break;
			}
		}
		for(int i = 0; i<n; i++) 
			for(int j = 0; j<n; j++)
				if (map[limit][i][j]) {
					cnt++;
					Max = Max > map[limit][i][j] ? Max : map[limit][i][j];
				}
		ans = ans > Max ? ans : Max;
		if(cnt == 1) return true;
		else return false;
	}
	for (int i = 0; i < 4; i++) {
		seq.push_back(i);
		if(bruteforce(depth + 1)) return true;
		seq.pop_back();
	}
	return false;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> map[0][i][j];
	ans = 0;
	for (int i = 1; i < 6; i++) {
		limit = i;
		if (bruteforce(0)) break;
	}
	cout << ans;
	return 0;
}