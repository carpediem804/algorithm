#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

int cache[41][2]; //0이 호출된 개수와 1이 호출 된 개수 저장 

int calc(int num,int which_is) {
	if (num == 0) {
		if (which_is == 0) {
			return 1;
		}
		return 0;
		
	}
	else if (num == 1) {
		if (which_is == 0) {
			return 0;
		}
		return 1;
	}
	
	if (which_is == 0) {
		int& zero_ret = cache[num][which_is];
		if (zero_ret != 0) {
			return zero_ret;
		}
		zero_ret = calc(num - 1, 0) + calc(num - 2, 0);
		return zero_ret;
	}
	else if (which_is == 1) {
		int& one_ret = cache[num][which_is];
		if (one_ret != 0) {
			return one_ret;
		}
		one_ret = calc(num - 1, 1) + calc(num - 2, 1);
		return one_ret;
	}
	
}
int main(void) {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int n;
		scanf("%d", &n);
		memset(cache, 0, sizeof(cache));
		calc(n, 0);
		calc(n, 1);
		printf("%d %d\n", calc(n, 0), calc(n, 1));
	}
}