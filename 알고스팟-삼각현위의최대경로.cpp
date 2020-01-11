#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
int map[101][101];
int max_map[101][101];
int n;
int do_max(int x, int y) {
	//기저
	if (x == n) {
		return map[x][y]; //마지막 일 때 
	}
	int& ret = max_map[x][y];
	if (ret != -1) {
		return ret;
	}
	ret = max(do_max(x + 1, y), do_max(x + 1, y + 1)) + map[x][y];

	return ret;

}
int main(void) {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			for (int y = 1; y <= i; y++) {
				scanf("%d", &map[i][y]);
			}
		}
		
		memset(max_map, -1, sizeof(max_map));
		
		printf("%d\n",do_max(1, 1));
		
	}

	return 0;
}