#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;
int map[31][31][31];
int visit[31][31][31];
int L, R, C;
int exitz, exitx, exity;
struct aa {
	int x, y, z;
	aa(int n1,int n2,int n3):z(n1),x(n2),y(n3){
	}
};
int ans;
queue <aa> q;
int dir[6][3] = { {1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1} };
void bfs() {
	int time = 0;
	while (q.size() != 0) {
		int qsize = q.size();
		for (int t = 0; t < qsize; t++) {
			int x = q.front().x;
			int y = q.front().y;
			int z = q.front().z;
			q.pop();
			if (x == exitx && y == exity && z == exitz) {
				ans = time;
				return;
			}
			for (int i = 0; i < 6; i++) {
				int dx = x + dir[i][0];
				int dy = y + dir[i][1];
				int dz = z + dir[i][2];
				if (dz >= 1 && dz <= L&&dx >= 1 && dx <= R && dy >= 1 && dy <= C ) {
					if (visit[dz][dx][dy] == 0 && map[dz][dx][dy] == 0) {
						visit[dz][dx][dy] = 1;
						q.push(aa(dz, dx, dy));
					}
				}
			}
		}
		time++;
	}
}
void clear() {
	for (int i = 1; i <= L; i++) {
		for (int x = 1; x <= R; x++) {
			for (int y = 1; y <= C; y++) {
				map[i][x][y] = 0;
				visit[i][x][y] = 0;
			}
		}
	}
	ans = 0;
	while (q.size() != 0) { q.pop(); }
}
int main(void) {
	while (true) {
		scanf("%d %d %d", &L, &R, &C);
		if (L == 0 && R == 0 && C == 0) { return 0; }
		char temp;
		for (int i = 1; i <= L; i++) {
			for (int x = 1; x <= R; x++) {
				for (int y = 1; y <= C; y++) {
					scanf(" %1c", &temp);
					if (temp == 'S') {
						q.push(aa(i, x, y));
					}
					else if (temp == '#') {
						map[i][x][y] = 1;
					}
					else if (temp == 'E') {
						exitz = i;
						exitx = x;
						exity = y;
					}
					
				}
			}
		}//map¿¡ ´Ù±×·Ç´ç ~ 
		bfs();
		if (ans == 0) {
			printf("Trapped!\n");
		}
		else {
			printf("Escaped in %d minute(s).\n", ans);
		}
		clear();
	}
	return 0;
}