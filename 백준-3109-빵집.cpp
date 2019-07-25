#include <stdio.h>
#include <iostream>

using namespace std;
int map[10001][501];
int check[10001][501];
int r, c;
int realans = 0;
int temp;
void dfs(int x, int y) { //������ �� , ������ , ������ �Ʒ� ������ ã�� �� -> ������ ���� ã���� ������ �������� �ű� ���� ���� 
	check[x][y] = 1;
	if (x<1 || x>r || y<1 || y>c) {
		return;
	}
	if (y == c) {
		//printf("x : %d y : %d\n", x, y);
		realans++;
		temp = 1;
		return;
	}
	if (map[x-1][y+1] == 0) {
		if(check[x-1][y+1]==0){
			dfs(x-1, y + 1);
			if (temp == 1) {
				return;
			}
		}
	}
	if (map[x][y + 1] == 0) {
		if (check[x][y + 1] == 0) {
			dfs(x, y + 1);
			if (temp == 1) {
				return;
			}
		}
	}
	if (map[x + 1][y + 1] == 0) {
		if (check[x + 1][y + 1] == 0) {
			dfs(x + 1, y + 1);
			if (temp == 1) {
				return;
			}
		}
	}
}
int main(void) {
	scanf("%d %d", &r, &c);
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			char temp;
			scanf(" %1c", &temp);
			if (temp == '.') {
				map[i][j] = 0;
			}
			else {
				map[i][j] = 1;
			}
		}
	}
	
	for (int i = 1; i <= r; i++) {
		temp = 0;
		dfs(i, 1);//�� ���� �� ����� �� dfs������ 
	}
	printf("%d", realans);
	return 0;
}