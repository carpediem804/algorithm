#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int k;
int map[501];
int cache[501][501];
int sum[501];

int calc(int start_index, int end_index) { //start_index와 end_index 까지의 합 
		
	if (start_index == end_index) {
		return 0;
	}
	if (start_index + 1 == end_index) {
		return  map[start_index] + map[end_index];
	}
	int& ret = cache[start_index][end_index];
	if (ret != -1) {
		return ret;
	}
	ret = 987654321;
	for (int i = start_index; i < end_index; i++) {
			ret = min(ret, calc(start_index, i) + calc(i + 1, end_index));		
	}
	ret += sum[end_index] - sum[start_index - 1];
	return ret ;
}
int main(void) {
	
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d", &k);
		for (int i = 1; i <= k; i++) {
			int temp;
			scanf("%d", &temp);
			map[i] = temp;
			sum[i] += sum[i - 1] + map[i];
		}
		memset(cache, -1, sizeof(cache));
		printf("%d\n",calc(1, k));

		memset(sum, 0, sizeof(sum));
	}
	return 0;
}