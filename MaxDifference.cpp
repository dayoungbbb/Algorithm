#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define MAX_N 8
int n, arr[MAX_N], visited[MAX_N], ret;
vector<int> v;
void bruteforce(int depth) {
	if (depth == n) {
		int sum = 0;
		for (int i = 0; i < n - 1; i++) {
			sum += abs(v[i] - v[i + 1]);
		}
		ret = ret > sum ? ret : sum;
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			v.push_back(arr[i]);
			bruteforce(depth+1);
			visited[i] = false;
			v.pop_back();
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	ret = 0;
	bruteforce(0);
	cout << ret;
}