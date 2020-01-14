#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;
int n;
int cache[101];
int tile(int num) {

	if (num == 1) {
		return 1;
	}
	if (num == 2) {
		return 2;
	}
	int& ret = cache[num];
	if (ret != 0) {
		return ret % 1000000007;
	}
	ret = tile(num - 1) + tile(num - 2);
	return ret % 1000000007;
}
int main(void) {
	int C;
	scanf("%d", &C);
	for (int t = 1; t <= C; t++) {
		scanf("%d", &n);
		memset(cache, 0, sizeof(cache));
		printf("%d\n", tile(n));
	}

	return 0;
}