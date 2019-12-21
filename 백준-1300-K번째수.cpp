#include <stdio.h>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	int k;
	scanf("%d %d", &n, &k);
	int start = 1;
	int end = k;
	int ans = 0;
	while (start <= end) {
		int mid = (start + end) / 2;
		long long num = 0;
		//mid 보다 작은 숫자 개수 구하기 
		for (int i = 1; i <= n; i++) {
			num += min(mid / i, n);
		}
		if (num < k) {
			start = mid + 1;
		}
		else {
			ans = mid;
			end = mid - 1;
		}
	}
	printf("%d", ans);
//	printf("start : %d end : %d\n", start,end);
	return 0;
}