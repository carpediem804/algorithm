#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int R, C;
char map[1501][1501];
int visit[1501][1501];

queue<pair<int, int> > water, water2, findbird,findbird_second; //������ , ����
int time;
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
int startx, starty;
int endx, endy;
int fb;
void waterbfs() { //��� ��ã�� bfs
	int watersize = water.size();
	for (int k = 0; k < watersize; k++) { //���� q�����ŭ�� ���� ! !! -> queue�� �߰��Ǵ� ���� �ȵȴ�
	//while(water.size()!=0){
		int x = water.front().first;
		int y = water.front().second;
		water.pop();
		for (int i = 0; i < 4; i++) {
			int dx = x + dir[i][0];
			int dy = y + dir[i][1];
			if (dx >= 1 && dx <= R && dy >= 1 && dy <= C) {
				if (map[dx][dy] == 'X' ) {
					map[dx][dy] = '.';
					water.push(make_pair(dx, dy)); //������� queue�� �߰�
				}
			}
		}
	}
}
void findbfs() {
	while (findbird.size() != 0 && fb == 0) {
		int x = findbird.front().first;
		int y = findbird.front().second;
		findbird.pop();
		for (int i = 0; i < 4; i++) {
			int dx = x + dir[i][0];
			int dy = y + dir[i][1];
			if ( dx >= 1 && dx <= R && dy >= 1 && dy <= C) {
				if (visit[dx][dy] == 0) {
					if (map[dx][dy] == '.') {
						visit[dx][dy] = 1;
						findbird.push(make_pair(dx, dy));
					} // ���� �� ���°Ŵ�
					else if (map[dx][dy] == 'X') {
						visit[dx][dy] = 1;
						findbird_second.push(make_pair(dx, dy));
					}
					else if (map[dx][dy] == 'L') {
						visit[dx][dy] = 1;
						fb = 1;
					}
				}
			}
		}
	}
}
int main(void) {
	scanf("%d %d ", &R, &C);
	int ck = 0;
	for (int x = 1; x <= R; x++) {
		for (int y = 1; y <= C; y++) {
			char temp;
			scanf(" %1c", &temp);
			if (temp == 'L') { 
				if (ck == 0) {
					startx = x;
					starty = y;
					ck = 1;
				}
				else {
					endx = x;
					endy = y;
				}
			}
			if (temp == 'X') { 
				map[x][y] = 'X'; //x�� ���� -1�� ���� 
			}
			else { 
				water.push(make_pair(x, y)); // ��� ���� water�� �ִ´�
				map[x][y] = temp; 
			}
		}
	}//map �׷Ǵ� 
	findbird.push(make_pair(startx, starty));
	visit[startx][starty] = 1;
	time = 1;
	while (fb == 0 ) {
		waterbfs();
		findbfs(); //���� ����Ǵ��� ã�°� 
		if (fb == 0) {
			time++;
			findbird = findbird_second;
			while (findbird_second.size() != 0) { findbird_second.pop(); }
			//findbird = findbird_second;
		}
		
		
	}
	printf("%d ", time);
	return 0;
}