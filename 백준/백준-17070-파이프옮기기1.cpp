#include <iostream>
#include <stdio.h>

using namespace std;
int map[18][18];
int n;
int ans;
void dfs(int x, int y, int dir) {
	if (x<1 || x>n || y<1 || y>n) {
		return;
	}
	if (x == n && y == n) {
		ans++;
	}
	if (dir == 1) { // 가로인경우 
		if (map[x][y+1] == 0) {
			dfs(x, y+1, 1);
		}
		if (map[x][y + 1] == 0 && map[x + 1][y + 1] == 0 && map[x + 1][y] == 0) {
			dfs(x + 1, y + 1, 3);
		}
	}
	else if (dir == 2) {//세로
		if (map[x + 1][y] == 0) {
			dfs(x + 1, y, 2);
		}
		if (map[x + 1][y] == 0 && map[x + 1][y + 1] == 0 && map[x][y + 1] == 0) {
			dfs(x + 1, y + 1, 3);
		}
	}
	else if (dir == 3) {//대각선
		if (map[x + 1][y] == 0) {
			dfs(x + 1, y, 2);
		}
		if (map[x][y + 1] == 0) {
			dfs(x, y + 1, 1);
		}
		if (map[x + 1][y] == 0 && map[x + 1][y + 1] == 0 && map[x][y + 1] == 0) {
			dfs(x + 1, y + 1, 3);
		}
	}
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %d", &map[i][j]);
		}
	}//map그리기

	dfs(1, 2, 1);
	printf("%d", ans);
	return 0;
}