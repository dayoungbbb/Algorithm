#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 100
vector<string> input, ret;
bool binary(string& key) {
	int start = 0;
	int end = (int)input.size()-1;
	int mid;
	while (end - start >= 0) {
		mid = (start + end) / 2;
		if (input[mid] == key)
			return true;
		else if (key < input[mid])
			end = mid - 1;
		else
			start = mid + 1;
	}
	return false;
}
int main()
{
	int n, m;
	cin >> n >> m;
	string temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		input.push_back(temp);
	}
	sort(input.begin(), input.begin()+n);

	for (int i = 0; i < m; i++) {
		cin >> temp;
		if (binary(temp))
			ret.push_back(temp);
	}
		
	int size = (int)ret.size();
	cout << size << '\n';
	sort(ret.begin(), ret.end());
	for (int i = 0; i < size; i++) {
		cout << ret[i] << '\n';
	}
	
}