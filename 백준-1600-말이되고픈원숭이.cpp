#include <iostream>
#include<stdio.h>
#include <queue>

using namespace std;
int map[201][201];
int visit[201][201];
int k, w, h;
struct aa {
	int x, y, k;
	aa(int n1, int n2, int n3) :x(n1), y(n2), k(n3) {

	}
};
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} }; //상하좌우
int horse_dir[8][2] = { {-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2} }; //말처럼 움직이는 것 
queue <aa> q;
int ans=-1;
void bfs() {
	int time = 0;
	while (q.size() != 0) {
		int qsize = q.size();
		for (int i = 0; i < qsize; i++) {
			int x = q.front().x;
			int y = q.front().y;
			int _k = q.front().k;
			q.pop();
			visit[x][y] = _k;
			if (x == h && y == w) {
				ans = time;
				return;
			}
			for (int j = 0; j < 4; j++) {
				int dx = x + dir[j][0];
				int dy = y + dir[j][1];
				if (dx >= 1 && dx <= h && dy >= 1 && dy <= w) {
					if ((visit[dx][dy]<_k)&&map[dx][dy]==0) {
						visit[dx][dy] = _k;
						q.push(aa(dx, dy, _k));
					}
				}
			}//위아래 좌우 방향 갈수 있으면 넣기 
			if (_k > 0) { //말로 이동할 수 있으면 
				for (int jj = 0; jj < 8; jj++) {
					int dx = x + horse_dir[jj][0];
					int dy = y + horse_dir[jj][1];
					if (dx >= 1 && dx <= h && dy >= 1 && dy <= w) {
						if ((visit[dx][dy] < _k-1)&&map[dx][dy]==0) {
							visit[dx][dy] = _k-1;
							q.push(aa(dx, dy, _k - 1));
						}
					}
				}
			}
		}
		time++;
	}
}
int main(void) {
	scanf(" %d", &k);
	scanf(" %d %d", &w, &h);
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			scanf(" %d", &map[i][j]);
			visit[i][j] = -1;
		}
	}

	q.push(aa(1, 1, k));
	bfs();
	printf("%d", ans);
	return 0;
}