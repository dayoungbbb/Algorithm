#if 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
typedef struct t {
	int end, start;
}t;
vector<t> v;
bool cmp(const t &a, const t &b) {
	if (a.end == b.end)
		return a.start < b.start;
	else
		return a.end < b.end;
}

int main()
{
	cin >> n;
	int start, end;
	
	for (int i = 1; i <= n; i++) {
		cin >> start >> end;
		t time = { end, start };
		v.push_back(time);
	}
	sort(v.begin(), v.end(), cmp);
	int cnt = 0, before = 0; 
	for (int i = 0; i < v.size(); i++) {
		if (v[i].start >= before) {
			before = v[i].end;
			cnt++;
		}
	}

	cout << cnt;
	return 0;
}
#endif
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <limits.h>
using namespace std;
#define MAX_N 100000
int n;
typedef struct t {
	int end, start;
}t;
vector<pair<int, t> >v;

int cnt, ret;
bool cmp(const t &a, const t &b) {
	return a.end > b.end;
}
void bruteforce(int before, int start) {
	for (int i = before + 1; i < v.size(); i++) {
		if (v[i].second.end <= start) {
			cnt++;
			bruteforce(i, v[i].second.start);
		}
	}
	return;
}
int main()
{
	cin >> n;
	int start, end;

	for (int i = 1; i <= n; i++) {
		cin >> start >> end;
		t time = { end, start };
		v.push_back(make_pair(end-start, time));
	}
	sort(v.begin(), v.end());
	ret = 0;

	bruteforce(-1, INT_MAX);

	cout << ret;
	return 0;
}
#endif