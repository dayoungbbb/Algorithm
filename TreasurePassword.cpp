#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
int main()
{
	int tc, n, k; cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n >> k;
		string input; cin >> input;
		int cut = n / 4;
		vector<string> v;
		for (int i = 0; i < cut; i++) {
			for (int k = 0; k < 4; k++) {
				string numStr; int num = 0;
				for (int j = 0; j < cut; j++) 
					numStr += input[k*cut + j];
				bool chk = true;
				for (int j = 0; j < (int)v.size(); j++) {
					if (v[j] == numStr)
						chk = false;
				}
				if (chk)
					v.push_back(numStr);
			}
			input = input[n - 1] + input.substr(0, n - 1);
		}
		sort(v.begin(), v.end(), greater<string>());
		long long num = 0;
		for (int i = 0; i < cut; i++)
			if (v[k - 1][i] >= 'A') num = num * 16 + (v[k - 1][i] - 'A' + 10);
			else num = num * 16 + (v[k - 1][i] - '0');
		cout << '#' << t << ' ' << num << '\n';
	}
	return 0;
}