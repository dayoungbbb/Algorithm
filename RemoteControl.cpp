#include <iostream>
#include <math.h>
#include <string.h>
#include <limits.h>
using namespace std;
bool arr[10];
int len;
bool check(int key) {
	len = 0; bool temp = true;
	if (key == 0) {
		len++;
		if (!arr[key]) temp = false;
	}
	while (key > 0) {
		len++;
		int num = key % 10;
		if (!arr[num]) {
			temp = false;
		}
		key /= 10;
	}

	return temp;
}
int main()
{
	int input, n, temp; cin >> input; cin >> n;
	memset(arr, true, sizeof(arr));
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr[temp] = false;
	}
	int num1, num2 = input < INT_MAX ? INT_MAX : input;
	num1 = abs(input - 100);
	for (int i = 0; i < 1000001; i++) {
		if (check(i)) num2 = num2 < (abs(i - input)+ len)? num2 : (abs(i - input)+len);
	}
	int result = num1 < num2 ? num1 : num2;
	cout << result;
	return 0;
}