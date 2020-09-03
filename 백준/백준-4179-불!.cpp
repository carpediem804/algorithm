#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;
int r, c;
struct aa {
	int x, y;
	aa(int n1, int n2) :x(n1), y(n2) {

	}
};
int map[1002][1002]; //벽은 -1 !
int visit[1002][1002]; //불 visit
int visit2[1002][1002]; //지훈 visit
queue <aa> fire, jihoon;
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
int ans;
void bfs() {
	int time = 1;
	while ( jihoon.size() != 0) {
		int firesize = fire.size();
		for (int f = 0; f < firesize; f++) {
			int x = fire.front().x;
			int y = fire.front().y;
			fire.pop();
			for (int i = 0; i < 4; i++) {
				int dx = x + dir[i][0];
				int dy = y + dir[i][1];
				if (dx >= 1 && dx <= r && dy >= 1 && dy <= c) {
					if (visit[dx][dy] == 0 && map[dx][dy]!=-1) {
						visit[dx][dy] = 1;
						map[dx][dy] = 1;
						fire.push(aa(dx, dy));
					}
				}
			}
		} // 1초마다 불이 퍼져나감 
		int jhsize = jihoon.size();
		for (int j = 0; j < jhsize; j++) {
			int x = jihoon.front().x;
			int y = jihoon.front().y;
			//printf("x : %d y : %d\n", x, y);
			jihoon.pop();
			for (int i = 0; i < 4; i++) {
				int dx = x + dir[i][0];
				int dy = y + dir[i][1];
				if (dx == 0 || dx == r + 1 || dy == 0 || dy == c + 1) {
					ans = time;
					return;
				}
				if (map[dx][dy] == 0 &&visit[dx][dy]==0) {
					visit[dx][dy] = 1;
					jihoon.push(aa(dx, dy));
				}//불이거나 벽이 아닐때
			}
		}
		time++;
	}
}
int main(void) {
	scanf("%d %d", &r, &c);
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			char c;
			scanf(" %1c", &c);
			if (c == 'F') { fire.push(aa(i, j)); 
			visit[i][j] = 1;
			map[i][j] = 1;
			}
			if (c == 'J') { 
				jihoon.push(aa(i, j)); }
			if (c == '#') {
				map[i][j] = -1;
			}
		}
	}
	bfs();
	if (ans == 0) {
		printf("IMPOSSIBLE\n");
	}
	else {
		printf("%d\n", ans);
	}
	return 0;
}