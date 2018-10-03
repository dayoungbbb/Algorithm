#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 1000
int n, k;
struct md {
	int gold, silver, bronze, nation, rank;
};
md arr[MAX_N];
bool comp(const md &a, const md & b) {
	if (a.gold != b.gold)
		return a.gold > b.gold;
	else if (a.silver != b.silver)
		return a.silver > b.silver;
	else if (a.bronze != b.bronze)
		return a.bronze > b.bronze;
	return false;
}
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i].nation >> arr[i].gold >> arr[i].silver >> arr[i].bronze;
	sort(arr, arr + n, comp);
	int cnt = 1; arr[0].rank = cnt;
	if (arr[0].nation == k) {
		cout << arr[0].rank; return 0;
	}
	for (int i = 1; i < n; i++) {
		cnt++;
		if ((arr[i].gold == arr[i - 1].gold) && (arr[i].silver == arr[i - 1].silver) && (arr[i].bronze == arr[i - 1].bronze)) {
			arr[i].rank = arr[i - 1].rank;
		}
		else
			arr[i].rank = cnt;
		if (arr[i].nation == k) {
			cout << arr[i].rank; return 0;
		}
	}
	return 0;
}