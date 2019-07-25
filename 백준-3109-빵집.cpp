#include <stdio.h>
#include <iostream>

using namespace std;
int map[10001][501];
int check[10001][501];
int r, c;
int realans = 0;
int temp;
void dfs(int x, int y) { //오른쪽 위 , 오른쪽 , 오른쪽 아래 순으로 찾는 것 -> 그전에 먼저 찾으면 어차피 다음점은 거기 갈수 없다 
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
		dfs(i, 1);//맨 왼쪽 열 모든점 다 dfs돌린다 
	}
	printf("%d", realans);
	return 0;
}