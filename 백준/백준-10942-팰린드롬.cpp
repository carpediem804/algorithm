#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int map[2001];
int cache[2001][2001];
int n,m;
int calc(int start_index, int end_index) {
	if (start_index >= end_index) {
		return 1;
	}
	if (map[start_index] != map[end_index]) {
		return 0;
	}
	////±âÀú»ç·Ê

	int & ret = cache[start_index][end_index];
	if (ret != -1) {
		return ret;
	}
	ret = 0;
	
//	int next = calc(start_index + 1, end_index - 1);
	ret = calc(start_index +1, end_index - 1);


	return ret;
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &map[i]);
	}
	scanf("%d", &m);
	memset(cache, -1, sizeof(cache));
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", calc(a, b));
	}
	return 0;
}