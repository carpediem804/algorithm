#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
int n, m;
int map[1003][1003];
int visit[1003][1003];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
struct aa {
	int x;
	int y;
	int cnt;
	int cango;
	aa(int n1, int n2, int n3, int n4) :x(n1), y(n2), cnt(n3), cango(n4) {

	}
};
int ans;
queue<aa> q;
void bfs() {
	while (q.size() != 0) {
		int _x = q.front().x;
		int _y = q.front().y;

		int _cnt = q.front().cnt;
		int _cango = q.front().cango;
		if (_x == n && _y == m) { ans = _cnt; return; }
		q.pop();
		//printf("_x : %d _y :%d size :  %d cnago :%d \n", _x, _y,q.size(),_cango);
		for (int i = 0; i < 4; i++) {
			int dx = _x + dir[i][0];
			int dy = _y + dir[i][1];
			if (dx >= 1 && dx <= n && dy >= 1 && dy <= m) {
				//	printf("dx : %d dy : %d\n", dx, dy);
				if (_cango == 1 && visit[dx][dy] != 3) {//¸ñ¼ûÀÖ´Â°æ¿ì
					if (map[dx][dy] == 0) {
						if (dx == n && dy == m) { ans = _cnt + 1; return; }
						visit[dx][dy] = 3;
						q.push(aa(dx, dy, _cnt + 1, 1));
					}
					else if (map[dx][dy] == 1) {
						//	printf("test 2 qpush : %d %d\n", dx, dy);
						if (dx == n && dy == m) { ans = _cnt + 1; return; }
						visit[dx][dy] = 1;
						q.push(aa(dx, dy, _cnt + 1, 0));
					}
				}
				else if (_cango == 0 && visit[dx][dy] == 0) { //¸ñ¼ûÀÌ ¾ø´Â °æ¿ì´Â ¶Õ¸°°÷¸¸ °¡¾ßµÊ 
					if (map[dx][dy] == 0) {
						if (dx == n && dy == m) { ans = _cnt + 1; return; }
						visit[dx][dy] = 1;
						q.push(aa(dx, dy, _cnt + 1, 0));
					}
				}
				else {}
			}
		}


	}

	//q.pop();
	return;
}
int main() {
	//int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	q.push(aa(1, 1, 1, 1));
	visit[1][1] = 3;
	bfs();

	if (ans == 0) {
		printf("-1\n");
	}
	else {
		printf("%d\n", ans);
	}
	return 0;
}