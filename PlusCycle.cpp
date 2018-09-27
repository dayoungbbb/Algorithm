#include <iostream>
using namespace std;

int main()
{
	int input, cnt = 0;
	cin >> input;
	int left, right;
	int ret = input;
	do{
		cnt++;
		right = ret % 10;
		left = ret / 10;
		ret = (left + right)%10+(right*10);
	} while (ret != input);
	cout << cnt;
	return 0;
}