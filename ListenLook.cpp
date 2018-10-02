#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX_N 100
vector<string> v, pq;
int main()
{
	int n, m;
	cin >> n >> m;
	string temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.begin() + n);

	for (int i = 0; i < m; i++) {
		cin >> temp;
		if (binary_search(v.begin(), v.end(), temp))
			pq.push_back(temp);
	}

	int size = pq.size();
	cout << size << '\n';
	sort(pq.begin(), pq.end());
	for (int i = 0; i < size; i++) {
		cout << pq[i] << '\n';
	}

}