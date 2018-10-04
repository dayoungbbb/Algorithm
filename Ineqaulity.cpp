#include <iostream>
#include <limits.h>
#include <string>
using namespace std;
int k, arr[10];     // 저장하는 숫자들
char ine[9];        // 부등호
bool visited[10];
string maxRet, minRet;
void bruteforce(int depth) {
	if (depth == k+1) {
		string temp;
		for (int i = 0; i <= k; i++) {
			temp = temp + to_string(arr[i]);
		}
		maxRet = maxRet.compare(temp)>0 ? maxRet : temp; // temp가 사전순으로 앞선가요?
		minRet = minRet.compare(temp)<0 ? minRet : temp; // minRet가 사전순으로 앞선가요?
		return;
	}
	for (int i = 0; i < 10; i++) {
		if (!visited[i]) {
			if (depth >= 1) {
				if (ine[depth-1] == '>') {
					if (arr[depth - 1] < i)
						continue;
				}
				else {
					if (arr[depth - 1] > i)
						continue;
				}
			}
			arr[depth] = i;
			visited[i] = true;
			bruteforce(depth + 1);
			visited[i] = false;
		}
	}
}
int main()
{
	cin >> k;
 	for (int i = 0; i < k; i++)
		cin >> ine[i];
	minRet = "9999999999";
	bruteforce(0);
	
	cout << maxRet << '\n' << minRet;
	return 0;
}