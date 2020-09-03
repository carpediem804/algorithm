#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int n, m;
int map[501][501];
int cache[501][501];
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
int calc(int x, int y) { //x,y에서 마지막 까지 갈수 있는 경로의수
	
	if (x == n && y == m) {
		return 1;
	}
	int& ret = cache[x][y];
	if (ret != -1) {
		return ret;
	}
	ret = 0;
	for (int i = 0; i < 4; i++) {
		int dx = x + dir[i][0];
		int dy = y + dir[i][1];
		if (dx>=1 && dx<=n && dy>=1 && dy<=m) {
			if (map[x][y] > map[dx][dy]) {
				ret += calc(dx, dy);
			}
		}
	}
	return ret;
}
int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	memset(cache, -1, sizeof(cache));
	printf("%d\n", calc(1, 1));
	
	return 0;
}