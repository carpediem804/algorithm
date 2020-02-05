#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
char map[6][10]; //5*9
int pin[10][2]; //max 8��
int max_pin_num;
int ans_pin=10;
int ans_go_num[10];
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
void dfs(int rest_pin, int go_num) {

	int flag = 0;
	for (int i = 1; i <= max_pin_num; i++) { //��� �� �� �˻� ~ 
		int x = pin[i][0];
		int y = pin[i][1];
		
		if (map[x][y] == '.') {
			continue;
		}
		for (int j = 0; j < 4; j++) {
			int dx = x + dir[j][0];
			int dy = y + dir[j][1];
			if (dx >= 1 && dx <= 5 && dy >= 1 && dy <= 9) {
				if (map[dx][dy] == 'o') { //o�� �̵��� �� �ִ�  //���� o���� �ִ� �ڸ��� .���� �ٲٰ� 
					int go_dx = dx;
					int go_dy = dy;
					if (j == 0) {
						go_dx -= 1;
					}
					else if (j == 1) {
						go_dx += 1;
					}
					else if (j == 2) {
						go_dy += 1;
					}
					else if (j == 3) {
						go_dy -= 1;
					}
					if (go_dx >= 1 && go_dx <= 5 && go_dy >= 1 && go_dy <= 9 ) { //���� �̵��ϴ� ���� ���� 
						if (map[go_dx][go_dy] == '.') {
							map[dx][dy] = '.'; //�����Ǵ� �� ��ġ ���� 
							map[go_dx][go_dy] = 'o'; //���� �̵��� ��ġ�� ���� 
							map[x][y] = '.'; //���� �� ����ġ�� .���� 
							pin[i][0] = go_dx; //�̵������ϱ� �� ��ǥ�� 
							pin[i][1] = go_dy;
							dfs(rest_pin - 1, go_num + 1);
							map[go_dx][go_dy] = '.'; //���� �̵��߶� �� .���� �ٲٰ�
							map[dx][dy] = 'o'; //������� �� �ٽ� ź��
							map[x][y] = 'o'; //���� �� �ɵ� �ٽ� ź�� 
							pin[i][0] = x; //��ǥ�� �״�� ~ 
							pin[i][1] = y; //�״�� �״�� ~ 
							flag = 1;
						}
					}
				}
			}//map�ȿ� dx dy�� �ְ� 
		}
	}
	if (flag == 0) {
		ans_pin = min(ans_pin, rest_pin);
		if (ans_pin == rest_pin) {
			ans_go_num[ans_pin] = min(ans_go_num[ans_pin], go_num);
		}
		return;
	}
	

}
int main(void) {
	int n;
	scanf("%d", &n);
	for (int t = 1; t <= n; t++) {
		ans_pin = 9 ;
		max_pin_num = 0;
		for (int i = 1; i <= 9; i++) {
			ans_go_num[i] = 987654321;
		}
		for (int x = 1; x <= 5; x++) {
			for (int y = 1; y <= 9; y++) {
				char temp;
				scanf(" %1c", &temp);
				//printf("%c", temp);
				if (temp == 'o') {
					max_pin_num++;
					pin[max_pin_num][0] = x;
					pin[max_pin_num][1] = y;
				}
				map[x][y] = temp;
			}
		}//map�׷Ǵ��� 
		dfs(max_pin_num, 0);
		printf("%d %d\n", ans_pin, ans_go_num[ans_pin]);

	}
	return 0;
}