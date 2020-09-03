#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;
int n;
int map[16][16];
int visit[16][16];
int endx, endy;
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
struct aa {
	int x,  y,  time;
	aa(int n1, int n2, int n3) :x(n1), y(n2), time(n3) {

	}
};
queue <aa> q;
int ans=-1;
void bfs() {
	while (q.size() != 0) {
		int qsize = q.size();
		for (int i = 0; i < qsize; i++) {
			int x = q.front().x;
			int y = q.front().y;
			int time = q.front().time;
			q.pop();
			if (x == endx && y == endy) {
				ans = time;
				return;
			}
				for (int i = 0; i < 4; i++) {
					int dx = x + dir[i][0];
					int dy = y + dir[i][1];
					if (dx >= 0 && dx < n && dy >= 0 && dy < n) {
						if (map[dx][dy] == 0 && visit[dx][dy]==0) { //갈수있고 한번도 방문 안했으면 고고~
							visit[dx][dy] = 1;
							q.push(aa(dx, dy, time + 1));
						}
						else if (map[dx][dy] == 2 && visit[dx][dy]==0) { //가는곳이 토네이도이고 한번도 방문 안했으면 ~~ 
							if ((time % 3) != 2) {
								q.push(aa(x, y, time + 1)); //그자리를 그냥 넣는다
							}//토네이도 땜에 갈수 없을때잉
							else { //갈수 있을 때
								visit[dx][dy] = 1; //방문했다고 표시하고 
								q.push(aa(dx, dy, time + 1)); 
							}
						}
					}

				}
			

		}
	}
}
void clear() {
	while (q.size() != 0) {
		q.pop();
	}
	ans = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = 0;
			visit[i][j] = 0;
		}
	}
}
int main(void) {
	int T;
	scanf("%d ", &T);
	for (int t = 1; t <= T; t++) {
		scanf(" %d", &n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf(" %d", &map[i][j]);
			}
		}//map그리기
		
		int stx, sty;
		scanf("%d %d", &stx, &sty);
		q.push(aa(stx, sty, 0));
		scanf("%d %d", &endx, &endy);
		bfs();
		
		printf("#%d %d\n", t, ans);
		clear();
	}
	return 0;
}