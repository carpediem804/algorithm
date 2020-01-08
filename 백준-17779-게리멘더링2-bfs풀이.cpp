#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
int n;
int map[21][21];
int color[21][21];
int one_sum, two_sum, three_sum, forth_sum, five_sum;
int ans = 999999999;
queue<pair<int, int>> q;
int dir[1][2] = { {1,0} };
void bfs() {
	while (q.size() != 0) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 1; i++) {
			int dx = x + dir[i][0];
			int dy = y + dir[i][1];
		
			if (dx >= 1 && dx <= n && dy >= 1 && dy <= n && color[dx][dy] == 0) {
				color[dx][dy] = 1;
				five_sum += map[dx][dy];
				q.push(make_pair(dx, dy));
			}
		}
	}
}
void divide(int x, int y, int d1, int d2) {
	//printf("x: %d y :%d d1: %d  d2 :%d\n", x, y, d1, d2);
	int d1_ = d1;
	int d2_ = d2;
	int dx = x;
	int dy = y;
	five_sum = 0;
	//q.push(make_pair(x, y));
	while (d1_ > 0) {
		color[dx + 1][dy - 1] = 1;
		five_sum += map[dx + 1][dy - 1];
		dx++;
		dy--;
		d1_--;
		if (d1_ != 0) {
			q.push(make_pair(dx, dy));
		}
	} //왼쪽 아래로 퍼지는곳 1로 바꿈 

	d2_ = d2;
	while (d2_ > 0) {
		color[dx + 1][dy + 1] = 1;
		five_sum += map[dx + 1][dy + 1];
		dx++;
		dy++;
		d2_--;
	}

	d1_ = d1;
	while (d1_ > 0) {
		color[dx - 1][dy + 1] = 1;
		five_sum += map[dx - 1][dy + 1];
		dx--;
		dy++;
		d1_--;
	}

	d2_ = d2;
	while (d2_ > 0) {
		color[dx - 1][dy - 1] = 1;
		five_sum += map[dx - 1][dy - 1];
		dx--;
		dy--;
		d2_--;
		q.push(make_pair(dx, dy));
	}

	bfs();
	one_sum = 0, two_sum = 0, three_sum = 0, forth_sum = 0;
	for (int check_x = 1; check_x <= n; check_x++) {
		for (int check_y = 1; check_y <= n; check_y++) {
			if (1 <= check_x && check_x < x + d1 && 1 <= check_y && check_y <= y && color[check_x][check_y] != 1) {
				one_sum += map[check_x][check_y];
				color[check_x][check_y] = 2;
			}
			else if (1 <= check_x && check_x <= x + d2 && y < check_y &&check_y <= n && color[check_x][check_y] != 1) {
				two_sum += map[check_x][check_y];
				color[check_x][check_y] = 3;
			}
			else if (x + d1 <= check_x && check_x <= n + d2 && 1 <= check_y && check_y < y - d1 + d2 && color[check_x][check_y] != 1) {
				three_sum += map[check_x][check_y];
				color[check_x][check_y] = 4;
			}
			else if (x + d2 < check_x && check_x <= n && y - d1 + d2 <= check_y && check_y <= n && color[check_x][check_y] != 1) {
				forth_sum += map[check_x][check_y];
				color[check_x][check_y] = 5;
			}

			color[check_x][check_y] = 0;
		}
	}

	
	int max_num = max(max(max(max(one_sum, two_sum), three_sum), forth_sum), five_sum);
	int min_num = min(min(min(min(one_sum, two_sum), three_sum), forth_sum), five_sum);
	
	if (ans > max_num - min_num) {
		ans = max_num - min_num;
	}
}
int main(void) {
	scanf("%d", &n);
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			scanf("%d", &map[x][y]);
		}
	}// map 그렷다 
	//이제 선거구 나눠야 된다 
	for (int x = 1; x < n - 1; x++) {
		for (int y = 2; y < n; y++) {
			//r,c == x,y 부터 시작 
			//d1,d2 -> 
			for (int d1 = 1; d1 < n; d1++) {
				for (int d2 = 1; d2 < n; d2++) {
					if (x + d1 + d2 <= n && y - d1 >= 1 && y + d2 <= n) {
						divide(x, y, d1, d2);
					}
				}
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}