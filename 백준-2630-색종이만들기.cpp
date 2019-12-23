#include <iostream>
#include <stdio.h>
using namespace std;
int map[129][129];
int blue, white;
void check(int x, int y, int n) {
	//printf("x : %d y : %d n : %d white : %d blue : %d\n", x, y, n, white, blue);
	int color = map[x][y];
	int temp = 0;
	for (int i = x; i <= x + n - 1; i++) {
		for (int j = y; j <= y + n - 1; j++) {
			if (map[i][j] != color ||temp==1) {
				temp = 1;
				break;
			}
		}
	}
	if (temp == 0) {
		if (color == 1) { blue++; }
		else {
			white++;
		}
	}
	if (temp == 1) {
		
		check(x, y, n / 2);
		
		check(x, y + n / 2, n / 2);
		
		check(x + n / 2, y, n / 2);
		
		check(x + n / 2, y + n / 2, n / 2);
	}
	
}

int main(void) {
	int n;
	scanf("%d", &n);
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			int temp;
			scanf("%d", &temp);
			map[x][y] = temp;
		}
	}
	
	check(1, 1, n);
	printf("%d\n%d\n", white, blue);
	return 0;
}