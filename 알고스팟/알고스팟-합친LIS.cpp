#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;
int n, m;
int map1[101];
int map2[101];
int cache[102][102];
int lis(int map1_index, int map2_index) {

	int& ret = cache[map1_index + 1][map2_index + 1];
	//printf("map1_index : %d map2_index :%d ret : %d\n", map1_index, map2_index, cache[map1_index][map2_index]);
	if (ret != 0) {
		return ret;
	}
	ret = 2;
	//map1[map1_index],map2[map2_index]가 존재함으로 최소 2개다

	long long map1_num = (map1_index == 0 ? LLONG_MIN : map1[map1_index]);
	long long map2_num = (map2_index == 0 ? LLONG_MIN : map2[map2_index]);
	long long max_num = max(map1_num, map2_num);

	for (int i = map1_index + 1; i <= n; i++) {
		if (max_num < map1[i]) {
			ret = max(ret, lis(i, map2_index) + 1);
		}
	}
	for (int i = map2_index + 1; i <= m; i++) {
		if (max_num < map2[i]) {
			ret = max(ret, lis(map1_index, i) + 1);
		}
	}
	return ret;

}
int main(void) {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d %d", &n, &m);

		for (int i = 1; i <= n; i++) {
			scanf("%d", &map1[i]);
		}
		for (int i = 1; i <= m; i++) {
			scanf("%d", &map2[i]);
		}
		memset(cache, 0, sizeof(cache));
		printf("%d\n", lis(0, 0) - 2);
	}

	return 0;
}