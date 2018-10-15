#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <functional>
using namespace std;
int n, k;
bool visited[LONG_MAX];
int main()
{
	int tc; cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n >> k;
		string input; cin >> input;
		int cut = n / 4;
		vector<string> v;
		for (int i = 0; i < cut; i++) {
			for (int k = 0; k < 4; k++) {
				string numStr; int num =0;
				for (int j = 0; j < cut; j++) {
					numStr += input[k*cut + j];
					if (input[k*cut+j] >= 'A') num = num*16 + (input[k*cut+j] - 'A' + 10);
					else num = num*16 + (input[k*cut+j] - '0');
				}
				if (!visited[num]) {
					visited[num] = true;
					v.push_back(numStr);
				}
			}
			input = input[n - 1] + input.substr(0, n-1);
		}
		sort(v.begin(), v.end(), greater<string>());
		long long num = 0;
		for (int i = 0; i < cut; i++)
			if (v[k-1][i] >= 'A') num = num * 16 + (v[k-1][i] - 'A' + 10);
			else num = num * 16 + (v[k-1][i] - '0');
		cout << '#' << t << ' ' << num << '\n';
	}
	return 0;
}