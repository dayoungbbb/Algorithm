#include <iostream>
#include <limits.h>
#include <string>
using namespace std;
int k, arr[10];     // �����ϴ� ���ڵ�
char ine[9];        // �ε�ȣ
bool visited[10];
string maxRet, minRet;
void bruteforce(int depth) {
	if (depth == k+1) {
		string temp;
		for (int i = 0; i <= k; i++) {
			temp = temp + to_string(arr[i]);
		}
		maxRet = maxRet.compare(temp)>0 ? maxRet : temp; // temp�� ���������� �ռ�����?
		minRet = minRet.compare(temp)<0 ? minRet : temp; // minRet�� ���������� �ռ�����?
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