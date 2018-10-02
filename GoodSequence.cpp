#include <iostream>
#include <vector>
using namespace std;
int arr[3] = { 1, 2, 3 }, n;
vector<int> v;
int bruteforce(int depth, int before) {

	for (int i = 2; i <= (v.size() / 2); i++) {
		for (int j = v.size() - i; j >= i; j--) {
			int cnt = 0;
			for (int k = 0; k < i; k++) {
				if (v[j + k] == v[j + k - i])
					cnt++;
			}
			if (cnt == i)
				return -1;
		}
	}


	if (depth == n) {
		for (int k = 0; k < v.size(); k++)
			cout << v[k];
		return 0;
	}


	int ret;
	for (int i = 0; i < 3; i++)
		if (i != before) {
			v.push_back(arr[i]);
			if (ret = bruteforce(depth + 1, i))
				v.pop_back();
			else
				return 0;
		}
	if (ret)
		return -1;
	else
		return 0;
}
int main()
{
	cin >> n;
	bruteforce(0, -1);
}