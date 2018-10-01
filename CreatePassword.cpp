#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_N 15
int l, c;
char arr[MAX_N];
vector<char> v;
void com(int depth, int before) {
	if (depth == l) {
		int cnta= 0, cntb = 0;
		for (int i = 0; i < l; i++) {
			if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u')
				cnta++;
			else cntb++;
		}
		if (cnta >= 1 && cntb >= 2) {
			for (int j = 0; j < l; j++) cout << v[j];
			cout << '\n';
		}
		return;
	}
	for (int i = before + 1; i < c; i++) {
		v.push_back(arr[i]);
		com(depth + 1, i);
		v.pop_back();
	}
}
int main()
{
	cin >> l >> c;
	for (int i = 0; i < c; i++) cin >> arr[i];
	sort(arr, arr + c);
	com(0, -1);
	return 0;
}