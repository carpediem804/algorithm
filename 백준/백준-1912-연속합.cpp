#include<iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
int map[100001];
int cache[100001];//index까지 최대 부분 합 
int check = 0;

int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &map[i]);
	}
	
	memset(cache, -1, sizeof(cache));
	int ans = map[1];
	cache[1] = map[1];

		for (int j = 2; j <= n; j++) {
			cache[j] = max(map[j], cache[j - 1] + map[j]);
			ans = max(ans, cache[j]);
		}
		//for (int j = 1; j <= n; j++) {
		//	printf("%d ", cache[j]);
		//}printf("\n");
	printf("%d\n", ans);
	return 0;
}