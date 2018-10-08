#include <iostream>
#include <math.h>
using namespace std;
#define MAX_N 15
int n, arr[MAX_N], cnt;
bool promising(int depth, int col)
{
	for (int i = 0; i < depth; i++) {
		if (arr[i] == col || abs(i-depth) == abs(arr[i] - col)) return false;
	}
	return true;
}
void bruteforce(int depth) {
	if (depth == n) {
		cnt++;
		return;
	}
	for (int j = 0; j < n; j++) {
		if (promising(depth, j)) {
			arr[depth] = j;
			bruteforce(depth + 1);
		}
	}
}
int main()
{
	cin >> n;
	bruteforce(0);
	cout << cnt;
}