#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#define MAX_N 50
int main()
{
	int n;
	//vector<int> a, b;
	int a[MAX_N], b[MAX_N];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	sort(a, a + n);
	sort(b, b + n, greater<int>());
	//sort(a.begin(), a.end());
	//sort(b.begin(), b.end(), less<int>());
	int ret = 0;
	for (int i = 0; i < n; i++)
		ret += a[i] * b[i];
	cout << ret;
	return 0;
}