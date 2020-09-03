#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
int R, C,M;
struct aa {
	int x, y;
	int speed;
	int dir;
	int _size;
	
};
struct aa shark[10001];
int visit[101][101];
int map[101][101];
int ans;
void del(int row) {
	for (int i = 1; i <= R; i++) {
		if (map[i][row] != 0) {
			ans += shark[map[i][row]]._size;
			map[i][row] = 0;
			return;
		}
	}
	return;
}

void go() {
	int time = 0;
	while (time <= C) {
		time++;
		del(time); //먹고 저장햇다 
		for (int i = 1; i <= M; i++) {
			int x = shark[i].x;
			int y = shark[i].y;
			int speed = shark[i].speed;
			int size = shark[i]._size;
			int dir = shark[i].dir;

			if (map[x][y] == i) { //먹히지 않았을 때 
				int temp = speed;
				while (temp > 0) {
					temp--;
					if (dir == 1) { //위 방향 
						x -= 1;
						if (x == 0) {
							x = 2;
							dir = 2;
						}
					}
					else if (dir == 2) { //아래
						x += 1;
						if (x == R + 1) {
							x = R - 1;
							dir = 1;
						}
					}
					else if (dir == 3) {//오른쪽
						y += 1;
						if (y == C + 1) {
							y = C - 1;
							dir = 4;
						}
					}
					else if (dir == 4) {//왼쪽
						y -= 1;
						if (y == 0) {
							y = 2;
							dir = 3;
						}
					}
				} //이게 쭉 이동한거다잉 
				shark[i].x = x;
				shark[i].y = y;
				shark[i].dir = dir;
				if (visit[x][y] == 0) {
					visit[x][y] = i;
				}
				else if (shark[visit[x][y]]._size < size) {
					visit[x][y] = i;
				}//이미 저장되어있는 거보다 내 크기가 더 크면 
			}
		}
		//이제 clear해야댐 
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				
				map[i][j] = 0;
				map[i][j] = visit[i][j];
				visit[i][j] = 0;
			}
		}

	}
}
int main(void) {
	scanf(" %d %d %d", &R, &C, &M);
	for (int i = 1; i <= M; i++) {
		int r, c, s, d, z;
		scanf(" %d %d %d %d %d", &r, &c, &s, &d, &z);
		shark[i].x = r;
		shark[i].y = c;
		shark[i].speed = s;
		shark[i].dir = d;
		shark[i]._size = z;
		map[r][c] = i;
	}
	
	go();
	printf("%d\n", ans);
	return 0;
}