#include <iostream>
#include <stdio.h>

using namespace std;
int N;
long long ans;
void dfs(int cnt,long long endiszero,long long endisone) {
	if (cnt == N) {
		ans = endiszero + endisone;
		return;
	}
	long long onesize = endiszero * 1;
	long long zerosize = endisone + endiszero;
	dfs(cnt + 1, zerosize, onesize);
}
int main(void) {
	scanf("%d", &N);
	dfs(1,0,1);
	printf("%lld\n", ans);
	return 0;
}