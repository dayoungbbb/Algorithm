#include <iostream>
using namespace std;
#define MAX_N 4002
int n;
int atom[1000][4];
int visited[MAX_N][MAX_N]; // �� ��ǥ�� ��� ���ڰ� �Դ��� Ƚ��
bool collide[MAX_N][MAX_N]; // ������ ��� �پ��ٰ� �þ��ٰ� �ؾ������� �浹�ߴ��� Ȯ���ϴ� ������ �ʿ�
//memset�� �Ἥ visited�� �Ź� �ʱ�ȭ �ߴ��� �ӵ��� �ʹ� ���ȴ�.
int main()
{
	int tc; cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> atom[i][0] >> atom[i][1] >> atom[i][2] >> atom[i][3];
			atom[i][0] = 2*(atom[i][0] + 1000);	atom[i][1] = 2*(atom[i][1] + 1000);
		}
		int sizeofAtom = n; int ret = 0;
		for (int l = 0; l < MAX_N; l++) {
			//memset(visited, 0, sizeof(visited));
			for (int i = 0; i < sizeofAtom; ++i) {
				int&x = atom[i][0]; int &y = atom[i][1]; int dir = atom[i][2];
				if (dir == 0) y++;
				else if (dir == 1) y--;
				else if (dir == 2) x--;
				else if (dir == 3) x++;
				if (atom[i][0] < 0 || atom[i][1] < 0 || atom[i][0] > 4000|| atom[i][1] >4000) {
					for(int j = 0; j<4; j++)						 //delete
						atom[i][j] = atom[sizeofAtom - 1][j];
					sizeofAtom--; i--;
				}
				else {
					visited[x][y]++;
					if (visited[x][y] >= 2) collide[x][y] = true;	// 2�� �̻��� �湮�ϸ� �浹
				}
			}
			for (int i = 0; i < sizeofAtom; ++i) {
				int x = atom[i][0]; int y = atom[i][1];
				if (collide[x][y]) {								//�浹�� ���� �ִ� �͸�
					if (visited[x][y] == 1) 
						collide[x][y] = false;
					ret += atom[i][3];								
					for (int j = 0; j < 4; j++)						//delete
						atom[i][j] = atom[sizeofAtom - 1][j];
					sizeofAtom--; i--;
				}
				visited[x][y]--;									// �浹 �ߵ� �� �ߵ� ��� visited�� �ٿ���
			}

			if (!sizeofAtom) break;
		}
		cout << '#' << t << ' ' << ret << '\n';
	}
	return 0;
}