#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int cache[101][101];
int route_cache[101][101];
int map[101][101];

int max_sum(int x,int y) {

	if (x == n) {
		return map[x][y];
	}//기저사례
	int& ret = cache[x][y];
	if (ret != 0) {
		return ret;
	}
	ret = max(max_sum(x + 1, y), max_sum(x + 1, y + 1)) + map[x][y];
	return ret;	
}
int route_num(int x, int y) {
	if (x == n) {
		return 1;
	}
	int& ret = route_cache[x][y];
	if (ret != 0) {
		return ret;
	}

	//ret = 0;
	//다른 경로로 왔을 때 그게 크면 그값 ㄱㄱ 
	if (max_sum(x + 1, y + 1) >= max_sum(x + 1, y)) {
		ret += route_num(x + 1, y + 1);
	}
	if (max_sum(x + 1, y + 1) <= max_sum(x + 1, y)) {
		ret += route_num(x + 1, y);
	}
	return ret;

}
int main(void) {
	int C;
	scanf("%d", &C);
	for (int t = 1; t <= C; t++) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		memset(cache, 0, sizeof(cache));
		memset(route_cache, 0, sizeof(route_cache));
		//max_sum(1, 1);
		printf("%d\n", route_num(1, 1));
	}

	return 0;
}