#include <iostream>
#include <string.h>
#include <queue>
#include <string>
#define MAX_N 10000
using namespace std;
int input, target;
string HASH[MAX_N];
bool visited[MAX_N];
char dir[4] = { 'D', 'S', 'L', 'R' };
int D(int n) {
	if (n == 0) return 0;
	n = n * 2;
	if (n > 9999) n = n % 10000;
	return n;
}
int S(int n) {
	if (n == 0) return n = 9999;
	else return n = n - 1;
}
int L(int n) {
	if (n == 0) return 0;
	int d1 = n / 1000; int rest = n % 1000;
	return n = rest * 10 + d1;
}
int R(int n) {
	if (n == 0) return 0;
	int d4 = n % 10; int rest = n / 10;
	return n = d4 * 1000 + rest;
}
int bfs() {
	queue<int> q; q.push(input); 
	visited[input] = true;
	int temp[4];
	while (!q.empty()) {
		int num = q.front(); q.pop();
		if (num == target)
			return num;
		temp[0] = D(num);
		temp[1] = S(num);
		temp[2] = L(num);
		temp[3] = R(num);
		for (int i = 0; i < 4; i++) {
			if (!visited[temp[i]]) {
				visited[temp[i]] = true;
				q.push(temp[i]);
				HASH[temp[i]] = HASH[num]  + dir[i];
			}
		}
	}
}
int main()
{
	int tc; cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> input >> target;
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < MAX_N; i++)
			HASH[i] = "";
		cout << HASH[bfs()]<<'\n';
	}
	return 0;
}