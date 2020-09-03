#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int R, C;
int map[21][21];
int visit[21][21];
int check_[60];
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
int ans;
void dfs(int x, int y, int cnt) {
	
	check_[map[x][y] - 'A'] = 1;
	cnt++;
	//printf("x : %d y : %d cnt : %d\n", x, y, cnt);
	ans = max(cnt, ans);
	for (int i = 0; i < 4; i++) {
		int dx = x + dir[i][0];
		int dy = y + dir[i][1];
		if (dx >= 1 && dx <= R && dy >= 1 && dy <= C &&visit[dx][dy]==0 && check_[map[dx][dy] - 'A'] ==0) {
			visit[dx][dy] = 1;
			check_[map[dx][dy] - 'A'] = 1;
			dfs(dx, dy, cnt);
			visit[dx][dy] = 0;
			check_[map[dx][dy] - 'A'] = 0;
		}
	}
}
int main(void) {
	scanf("%d %d ", &R, &C);
	for (int x = 1; x <= R; x++) {
		for (int y = 1; y <= C; y++) {
			scanf(" %1c", &map[x][y]);
		}
	}
	visit[1][1] = 1;
	check_[map[1][1] - 'A'] = 1;
	dfs(1, 1, 0);
	printf("%d\n",ans);

	return 0;
}