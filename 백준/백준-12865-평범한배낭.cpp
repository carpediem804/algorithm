#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;
int map[101][2]; //weight, value
int cache[101][100001]; // index,rest_k;
int n, k;
int napsak(int index, int rest_k) {

	if (index > n) {
		return 0;
	}
	
	int& ret = cache[index][rest_k];

	if (ret != 0) {
		return ret;
	}
	ret = napsak(index + 1, rest_k);
	if (rest_k - map[index][0] >= 0) {
		ret = max(ret, napsak(index + 1, rest_k - map[index][0]) + map[index][1]);
	}

	return ret;
}
int main(void) {

	scanf("%d %d", &n,&k);
	for (int i = 1; i <= n; i++) {
		int weight, value;
		scanf("%d %d", &weight, &value);
		map[i][0] = weight;
		map[i][1] = value;
	}
	int ans = napsak(1,k);
	
	printf("%d\n", ans);
	return 0;
}