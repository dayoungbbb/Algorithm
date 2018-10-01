#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 1000
int n, p[MAX_N];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i];
	sort(p, p + n);
	int sum = 0, ret = 0;
	for (int j = 0; j < n; j++) {
		sum += p[j];
		ret += sum;
	}
	cout << ret;
	return 0;
}