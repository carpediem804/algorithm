#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int map[1001];
int cache[1002];
int lis(int index) {
	int& ret = cache[index + 1];
	if (ret != 0) {
		return ret;
	}
	ret = 1;
	for (int i = index + 1; i <= n; i++) {
		if (i == 0 || map[index] < map[i]) {
			ret = max(ret, lis(i) + 1);
		}
	}
	return ret;
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &map[i]);
	}
//	cache[1] = -1;
	printf("%d\n",lis(0)-1);

	return 0;
}