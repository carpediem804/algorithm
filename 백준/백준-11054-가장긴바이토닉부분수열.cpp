#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int n;

int map[1001];
int cache[1002][2];

int lis_bitonic(int index,int dir) {
	//기저사례
	if (index > n || index <= 0) {
		return 0;
	}
	int& ret = cache[index][dir];
	if (ret != 0) {
		return ret;
	}
	ret = 1;
	if (dir == 0) {
		for (int next = index - 1; next >= 1; next--) {
			if (map[index] > map[next]) {
				ret = max(ret, lis_bitonic(next, 0) + 1);
			}
		}
	}//왼쪽 방향 이면 
	else {//오른쪽 방향이면
		for (int next = index + 1; next <= n; next++) {
			if (map[index] > map[next]) {
				ret = max(ret, lis_bitonic(next, 1) + 1);
			}
		}
	}
	return ret;
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &map[i]);
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, lis_bitonic(i,0)+lis_bitonic(i,1));
	}
	//for (int i = 0; i <= 1; i++) {
	//	for (int j = 1; j <= n; j++) {
	//		printf("%d ", cache[j][i]);
	//	}printf("\n");
	//}
	printf("%d\n", ans-1);

	return 0;
}