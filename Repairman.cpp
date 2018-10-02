#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 1000
int n, l;
int arr[MAX_N];
bool visited[MAX_N];
int main()
{
	cin >> n >> l;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (!visited[arr[i]]) {
			cnt++;
			for (int j = arr[i]; j < arr[i] + l; j++)
				visited[j] = true;
		}
	}
	cout << cnt;
}