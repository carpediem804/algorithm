#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
int n;
int map[21][21];
int color[21][21];
int one_sum, two_sum, three_sum, forth_sum, five_sum;
int ans = 987654321;


void divide(int x, int y, int d1, int d2) {
	//printf("x : %d y : %d d1 : %d d2 : %d\n", x, y, d1, d2);
	//color[x][y] = 1;

	int d1_ = d1;
	int d2_ = d2;
	int dx = x;
	int dy = y;
	//five_sum = 0;

	while (d1_ > 0) {
		color[dx + 1][dy - 1] = 1;
		//five_sum += map[dx + 1][dy - 1];
		dx++;
		dy--;
		d1_--;

	} //왼쪽 아래로 퍼지는곳 1로 바꿈 

	d2_ = d2;
	while (d2_ > 0) {
		color[dx + 1][dy + 1] = 1;
		//five_sum += map[dx + 1][dy + 1];
		dx++;
		dy++;
		d2_--;
	}

	d1_ = d1;
	while (d1_ > 0) {
		color[dx - 1][dy + 1] = 1;
		//five_sum += map[dx - 1][dy + 1];
		dx--;
		dy++;
		d1_--;
	}

	d2_ = d2;
	while (d2_ > 0) {
		color[dx - 1][dy - 1] = 1;
		//five_sum += map[dx - 1][dy - 1];
		dx--;
		dy--;
		d2_--;
	}


	one_sum = 0, two_sum = 0, three_sum = 0, forth_sum = 0, five_sum = 0;
	for (int check_x = 1; check_x <= n; check_x++) {
		for (int check_y = 1; check_y <= n; check_y++) {
			if (1 <= check_x && check_x < x + d1 && 1 <= check_y && check_y <= y && color[check_x][check_y] != 1) {
				one_sum += map[check_x][check_y];
				color[check_x][check_y] = 2;
			}
			else {
				break;
			}
		}
	}
	for (int check_x = 1; check_x <= n; check_x++) {
		for (int check_y = n; check_y >= 1; check_y--) {
			if (1 <= check_x && check_x <= x + d2 && y < check_y &&check_y <= n && color[check_x][check_y] != 1) {
				two_sum += map[check_x][check_y];
				color[check_x][check_y] = 3;
			}
			else {
				break;
			}
		}
	}
	for (int check_x = n; check_x >= 1; check_x--) {
		for (int check_y = 1; check_y <= n; check_y++) {
			if (x + d1 <= check_x && check_x <= n + d2 && 1 <= check_y && check_y < y - d1 + d2 && color[check_x][check_y] != 1) {
				three_sum += map[check_x][check_y];
				color[check_x][check_y] = 4;
			}
			else {
				break;
			}
		}
	}
	for (int check_x = n; check_x >= 1; check_x--) {
		for (int check_y = n; check_y >= 1; check_y--) {
			if (x + d2 < check_x && check_x <= n && y - d1 + d2 <= check_y && check_y <= n && color[check_x][check_y] != 1) {
				forth_sum += map[check_x][check_y];
				color[check_x][check_y] = 5;
			}
			else {
				break;
			}
		}
	}

	for (int check_x = 1; check_x <= n; check_x++) {
		for (int check_y = 1; check_y <= n; check_y++) {
			//			printf("%d ", color[check_x][check_y]);
			if (color[check_x][check_y] == 0 || color[check_x][check_y] == 1) {
				five_sum += map[check_x][check_y];
			}
			color[check_x][check_y] = 0;
		}//printf("\n");
	}

	//	printf("%d %d %d %d %d\n", one_sum, two_sum, three_sum, forth_sum, five_sum);
	int max_num = max(max(max(max(one_sum, two_sum), three_sum), forth_sum), five_sum);
	int min_num = min(min(min(min(one_sum, two_sum), three_sum), forth_sum), five_sum);
	//	printf("max_num : %d min_num : %d 차이 : %d\n", max_num, min_num,max_num-min_num);
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
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
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