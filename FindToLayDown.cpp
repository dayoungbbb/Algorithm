#include <iostream>
using namespace std;
#define MAX_N 100
int map[MAX_N][MAX_N], n, ret;
int main()
{
	char temp;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> temp;
			if (temp == 'X') map[i][j] = 1;
		}
	ret = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (!map[i][j]) {
				cnt++;
				if (cnt == 2) {
					ret++;
				}
			}
			else {
				cnt = 0;
			}
		}
	}
	cout << ret << ' ';
	ret = 0;
	for (int j = 0; j < n; j++) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (!map[i][j]) {
				cnt++;
				if (cnt == 2) {
					ret++;
				}
			}
			else {
				cnt = 0;
			}
		}
	}
	cout << ret;
	return 0;
}