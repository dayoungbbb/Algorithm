#include <iostream>
#include <vector>
#define MAX_N 100
using namespace std;
int main() {
	int ret = 0;
	vector<int> bag, trash;
	int arr[MAX_N], cnt = 0;
	while (scanf("%d ", &arr[cnt])!=EOF) {
		if (bag.size() == 3) { // ������ full�̶��
			bool check = true;
			for (int i = 0; i < 3; i++) {
				if (arr[cnt] == bag[i]) { //��ȸ�ϸ鼭 ���� �ִ��� Ȯ��
					check = false;
					break;
				}
			}
			if (check) { // ���� ���� ������ ����
				trash.push_back(bag.front());
			}
			for (int i = 0; i < 2; i++)
				bag[i] = bag[i + 1];
			bag.pop_back();
			
		}
		bag.push_back(arr[cnt]);
		cnt++;
	}
	if (!trash.size())
		cout << "0" << endl;
	else {
		for (int i = 0; i < trash.size(); i++)
			cout << trash[i] << endl;
	}
	return 0;
}