#include <iostream>
using namespace std;
int n, x, map[21][21], ret, arr[21]; 
enum DIRECTION { FORWARD, UP, DOWN };
typedef struct {
	int num; // 숫자
	int cnt; // 개수
	DIRECTION dir;
}STAIR;

void solv() {
	STAIR now;
	now.cnt = 1; now.num = arr[0]; now.dir = FORWARD;
	for (int i = 1; i < n; i++) {
		if (arr[i] == now.num) { // 값이 같을 때
			now.cnt++;
			if (now.dir == DOWN && i == n - 1 && now.cnt < x)
				return;
		}
		else if (arr[i] == (now.num+1)) { //1칸 위로 올라갈 때
			if (now.cnt < x)
				return;
			if (now.dir == DOWN && now.cnt - x < x)
				return;

			now.dir = UP; now.num++; now.cnt = 1;
		}
		else if (arr[i] == (now.num-1)) { //1칸 내려갈 때
			if (now.dir == DOWN && now.cnt < x)
				return;
			if (i == n - 1)
				return;


			now.dir = DOWN; now.cnt = 1; now.num--;
		}
		else {
			return;
		}
	}
	ret++;
}

int main()
{
	int tc;

	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n >> x;
		
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) 
				cin >> map[i][j];
		ret = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				arr[j] = map[i][j];
			}
			solv();
			for (int j = 0; j < n; j++) {
				arr[j] = map[j][i];
			}
			solv();
		}

		cout << "#" << t << " " << ret << endl;
		printf("\n");
	}
}
