#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;
char map[51][51];
int visit[51][51];
//int cnt_map[51][51];
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
int N, M;
bool dfs(int x, int y, int go_cnt) {
	char color = map[x][y];
	//printf("x : %d y :%d cnt : %d\n ", x, y,go_cnt);
	for (int i = 0; i < 4; i++) {
		int dx = x + dir[i][0];
		int dy = y + dir[i][1];
		if (dx >= 1 && dx <= N && dy >= 1 && dy <= M) {
			if (map[dx][dy] == color) {
				if (visit[dx][dy] == 0) {
					visit[dx][dy] = go_cnt;
					bool check= dfs(dx, dy, go_cnt + 1);
					if (check == true) { return true; }
				}
				else if (abs(go_cnt - visit[dx][dy]) >= 3) {
					return true;
				}
			}
		}
	}
	return false;

}
int main(void) {
	scanf("%d %d", &N, &M);
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= M; y++) {
			scanf(" %c", &map[x][y]);
		}
	}
	//int visit_cnt = 1;
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= M; y++) {
			if (visit[x][y] == 0) {
				visit[x][y] = 1;
				bool temp_ans = dfs(x, y,1);
				if (temp_ans == true) {
					printf("Yes\n");
					return 0 ;
				}
			}
		}
	}
	
	printf("No\n");


	return 0;
}