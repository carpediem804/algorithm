#include <iostream>
#include <stdio.h>

using namespace std;
int map1[101][101];
int map2[101][101];
int ans_map[101][101];
int n, m, k;
int calc(int x, int y) {
	int temp = 0;
	for (int i = 1; i <= m; i++) {
		temp += (map1[x][i] * map2[i][y]);
	}
	return temp;
}
int main(void) {
	
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map1[i][j]);
		}
	}
	scanf("%d %d", &m, &k);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= k; j++) {
			scanf("%d", &map2[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			ans_map[i][j] = calc(i, j);
			printf("%d ", ans_map[i][j]);
		}
		printf("\n");
	}

	return 0;
}