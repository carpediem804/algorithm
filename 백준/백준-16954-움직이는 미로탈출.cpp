#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

char map[9][9];
int visit[9][9];
queue<pair<int, int> > q;
int ans = 0;
int dir[9][2] = { {-1,0},{1,0},{0,-1},{0,1},{-1,-1},{1,1},{-1,1},{1,-1},{0,0} };
void down() {
	for (int y = 1; y <= 8; y++) {
		for (int x = 8; x >= 1; x--) {
			if (map[x][y] == '#') {
				if (x == 8) {
					map[x][y] = '.';
				}
				else {
					map[x + 1][y] = '#';
					map[x][y] = '.';
				}
			}
		}
	}
}
void bfs() {
	int time = 0;
	while (q.size() != 0) {
		time++;
		int qsize = q.size();
		for (int k = 0; k < qsize; k++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (map[x][y] != '#') {
				for (int i = 0; i < 9; i++) {
					int dx = x + dir[i][0];
					int dy = y + dir[i][1];
					if (dx >= 1 && dx <= 8 && dy >= 1 && dy <= 8) {
						if (map[dx][dy] == '.' && visit[dx][dy] != time) {
							if (dx == 1 && dy == 8) {
								ans = 1;
								return;
							}
							visit[dx][dy] = time;
							q.push(make_pair(dx, dy));
						}
					}
				}
			}
		}
		down();
	}
}
int main(void) {

	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			scanf(" %1c", &map[i][j]);
		}
	}
	q.push(make_pair(8, 1));
	bfs();
	printf("%d\n", ans);
	return 0;
}