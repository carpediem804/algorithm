#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int n;
long long cache[101];
long long calc(int num) {
	if (num <= 3) {
		return 1;
	}
	else if (num <= 5) {
		return 2;
	}
	long long& ret = cache[num];
	
	if (ret != 0) {
		return ret;
	}

	ret = calc(num - 1) + calc(num - 5);

	return ret;
}
int main(void) {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d", &n);
		
		memset(cache, 0, sizeof(cache));
		
		printf("%lld\n", calc(n));
		
	}
	return 0;
}