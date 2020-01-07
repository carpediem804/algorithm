#include <iostream>
#include <stdio.h>

using namespace std;

int main(void) {

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		long long x, y;
		scanf("%lld %lld", &x, &y);
		long long d = y - x;
		long long n = 1;
		while (n*n <= d) {
			n++;
		}//n*n <=d  ÀÎ nÃ£±â 
		n -= 1; 
		long long remain = d - n * n;

		long long next = (n + 1)*(n + 1);

		//printf("n : %lld remain : %lld next : %lld\n", n, remain, next);
		if (remain == 0) {
			printf("%lld\n", (2 * n) - 1);
		}
		else if (next - d > remain) {
			printf("%lld\n", 2*n);
		}
		else {
			printf("%lld\n", (2 * n) + 1);
		}

	}
	return 0;
}