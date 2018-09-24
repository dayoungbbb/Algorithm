#include <iostream>
#include <string.h>
using namespace std;

int cnt, length, maxNum;
bool digit[1000000][20];
int swap(int num, int i, int j) {
	int arr[6], temp = num, ret = 0;
	for (int i = 1; i <= length; i++) {
		arr[length - i] = temp % 10;
		temp /= 10;
	}

	if (arr[i] == arr[j])
		return num;

	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;

	for (int i = 0; i < length; i++) {
		ret = ret * 10 + arr[i];
	}
	return ret;
}

void bruteforce(int num, int depth) {
	if (digit[num][depth])
		return;
	digit[num][depth] = true;
	if (cnt == depth) {
		maxNum = num > maxNum ? num: maxNum;
		return;
	}

	for (int i = 0; i < length-1; i++) {
		for (int j = i+1; j < length; j++) {
			bruteforce(swap(num, i, j), depth + 1);
		}
	}

}
int main()
{
	int tc, input, temp;
	
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> input >> cnt;
		for (int i = 0; i < 1000000; i++)
			for (int j = 0; j < 20; j++)
				digit[i][j] = false;
		temp = input;
		length = 0;
		
		while (temp != 0) {
			temp = temp / 10;
			length++;
		}

		maxNum = 0;
		
		bruteforce(input, 0); // bruteforce긴 하지만 중복이 많기 때문에..depth체크도 해주는 듯
		
		printf("#%d %d\n", t, maxNum);
	}

	return 0;
}
