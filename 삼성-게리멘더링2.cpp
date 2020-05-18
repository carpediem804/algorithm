#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int N;
int map[21][21];
int visit[21][21];
int first, second, third, fourth, fifth;
int realans = 987654321;
void draw(int x, int y, int d1, int d2) {
	int dx = x;
	int dy = y;
	visit[dx][dy] = 1;
	for (int i = 1; i <= d1; i++) {
		dx += 1;
		dy -= 1;
		visit[dx][dy] = 1;
	}
	for (int i = 1; i <= d2; i++) {
		dx += 1;
		dy += 1;
		visit[dx][dy] = 1;
	}
	for (int i = 1; i <= d1; i++) {
		dx -= 1;
		dy += 1;
		visit[dx][dy] = 1;
	}
	for (int i = 1; i <= d2; i++) {
		dx -= 1;
		dy -= 1;
		visit[dx][dy] = 1;
	}
}
void clear(int x, int y, int d1, int d2) {
	int dx = x;
	int dy = y;
	visit[dx][dy] = 0;
	for (int i = 1; i <= d1; i++) {
		dx += 1;
		dy -= 1;
		visit[dx][dy] = 0;
	}
	for (int i = 1; i <= d2; i++) {
		dx += 1;
		dy += 1;
		visit[dx][dy] = 0;
	}
	for (int i = 1; i <= d1; i++) {
		dx -= 1;
		dy += 1;
		visit[dx][dy] = 0;
	}
	for (int i = 1; i <= d2; i++) {
		dx -= 1;
		dy -= 1;
		visit[dx][dy] = 0;
	}
}
void calc(int x, int y, int d1,int d2) {
	if (!(x + d1 + d2 <= N && y - d1 >= 1 && y + d2 <= N)) {
		return;
	}//�ȵǴ� �κ� ~
	draw(x, y, d1, d2); //1�� ��ä���~ 
	int flag = 0;
	for (int dx = 1; dx <= N; dx++) {
		flag = 0;
		for (int dy = 1; dy <= N; dy++) {
			if (visit[dx][dy] == 1 || flag ==1) {
				if ((dx == x || dx == x + d1 + d2) && visit[dx][dy] == 1) {
					fifth += map[dx][dy];
					continue;
				}
				if (flag == 0) { //ó�� visit �߰����� �� 
					flag ++; //1�� �ٲٰ� 
					fifth += map[dx][dy];
					continue;
				}
				if (flag == 1 && visit[dx][dy] == 1) { //�ι�° visit�� �߰����� �� 
					flag = 0;
					fifth += map[dx][dy];
					continue;
				}
				//flag ==1�� ��� 
				fifth += map[dx][dy];
			}
			else if (dx < x + d1 && dy <= y) {
				//visit[dx][dy] = 0;
				first += map[dx][dy];
			}
			else if (dx <= x + d2 && dy > y) {
				//visit[dx][dy] = 2;
				second += map[dx][dy];
			}
			else if (x + d1 <= dx && dy < y - d1 + d2) {
				//visit[dx][dy] = 3;
				third += map[dx][dy];
			}
			else if (x + d2 < dx && y - d1 + d2 <= dy) {
				//visit[dx][dy] = 4;
				fourth += map[dx][dy];
			}
		}
	} //for�� ��

	int max_temp = max(max(max(max(first, second), third), fourth), fifth);
	int min_temp = min(min(min(min(first, second), third), fourth), fifth);

	realans = min(realans, max_temp - min_temp);

	clear(x, y, d1, d2);//0���� �ٽ� �ٲٰ� ~ 
	first = 0;
	second = 0;
	third = 0;
	fourth = 0;
	fifth = 0;

}

int main(void) {
	scanf("%d", &N);
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			scanf("%d", &map[x][y]);
		}
	}
	for (int x = 2; x <= N - 1; x++) {
		for (int y = 2; y <= N - 1; y++) {
			for (int d1 = 1; d1 <= N / 2; d1++) {
				for (int d2 = 1; d2 <= N / 2; d2++) {
					calc(x, y, d1,d2);
				}
			}
		}
	}

	printf("%d\n", realans);
	return 0;
}