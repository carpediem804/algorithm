#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
char map[6][10]; //5*9
int pin[10][2]; //max 8개
int max_pin_num;
int ans_pin=10;
int ans_go_num[10];
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
void dfs(int rest_pin, int go_num) {

	int flag = 0;
	for (int i = 1; i <= max_pin_num; i++) { //모든 핀 다 검사 ~ 
		int x = pin[i][0];
		int y = pin[i][1];
		
		if (map[x][y] == '.') {
			continue;
		}
		for (int j = 0; j < 4; j++) {
			int dx = x + dir[j][0];
			int dy = y + dir[j][1];
			if (dx >= 1 && dx <= 5 && dy >= 1 && dy <= 9) {
				if (map[dx][dy] == 'o') { //o면 이동할 수 있다  //원래 o핀이 있던 자리를 .으로 바꾸고 
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
					if (go_dx >= 1 && go_dx <= 5 && go_dy >= 1 && go_dy <= 9 ) { //내가 이동하는 곳의 범위 
						if (map[go_dx][go_dy] == '.') {
							map[dx][dy] = '.'; //삭제되는 핀 위치 맵이 
							map[go_dx][go_dy] = 'o'; //내가 이동한 위치의 값이 
							map[x][y] = '.'; //원래 내 핀위치도 .으로 
							pin[i][0] = go_dx; //이동했으니까 내 좌표도 
							pin[i][1] = go_dy;
							dfs(rest_pin - 1, go_num + 1);
							map[go_dx][go_dy] = '.'; //핀이 이동했떤 곳 .으로 바꾸고
							map[dx][dy] = 'o'; //삭제됬던 핀 다시 탄생
							map[x][y] = 'o'; //원래 내 핀도 다시 탄생 
							pin[i][0] = x; //좌표도 그대로 ~ 
							pin[i][1] = y; //그대로 그대로 ~ 
							flag = 1;
						}
					}
				}
			}//map안에 dx dy가 있고 
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
		}//map그렷다잉 
		dfs(max_pin_num, 0);
		printf("%d %d\n", ans_pin, ans_go_num[ans_pin]);

	}
	return 0;
}