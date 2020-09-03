#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
int r, c;
char map[251][251];
bool visit[251][251];
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
queue<pair<int, int>> q;
int sheep, wolf;
int ans_sheep, ans_wolf;
void bfs() {
	
	while (q.size() != 0) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int dx = x + dir[i][0];
			int dy = y + dir[i][1];
			if (dx >= 1 && dx <= r && dy >= 1 && dy <= c) {
				if (visit[dx][dy] == false) {
					visit[dx][dy] = true;
				//	printf("dx : %d dy ; %d map[dx][dy] :%c\n", dx, dy, map[dx][dy]);
					if (map[dx][dy] == 'o') { sheep += 1; }
					if (map[dx][dy] == 'v') { wolf += 1; }
					q.push(make_pair(dx, dy));
				}
			}
		}
	}
}
int main(void) {
	scanf("%d %d", &r, &c);
	for (int x = 1; x <= r; x++) {
		for (int y = 1; y <= c; y++) {
			scanf(" %1c", &map[x][y]);
			if (map[x][y] == '#') {
				visit[x][y] = true;
			}
		}
	}
	for (int x = 1; x <= r; x++) {
		for (int y = 1; y <= c; y++) {
			if (visit[x][y] == false) {
				sheep = 0;
				wolf = 0;
				q.push(make_pair(x, y ));
				visit[x][y] = true;
				if (map[x][y] == 'o') { sheep += 1; }
				if (map[x][y] == 'v') { wolf += 1; }
				bfs();
				if (sheep > wolf) {
					ans_sheep += sheep;
				}
				else { ans_wolf += wolf; }
			}
		}
	}
	printf("%d %d\n", ans_sheep, ans_wolf);
	return 0;
}