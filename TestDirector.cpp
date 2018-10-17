#include <iostream>
using namespace std;
long long n, a[1000001], b, c, ret;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> b >> c;
	ret = n;
	for (int i = 0; i < n; i++) {
		a[i] = a[i] - b;
		if (a[i]>0) {
			if ((a[i] % c)>0) {
				if (a[i] < c) { ret = ret + 1; }
				else { ret = ret + ((a[i] / c) + 1); }
			}
			else ret = ret + (a[i] / c);
		}
	}
	cout << ret;
	return 0;
}