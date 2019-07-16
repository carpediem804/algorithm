#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
long long k, n;
long long maximuns; //�������ִ� ���������� �ִ밪 
long long has[10001]; //�������ִ� ������ ���̵�
long long standard;

void dfs(long long min, long long max) {
	if (min > max) {
		standard = max;
		return;
	}
	long long mid = (min + max+1) / 2;
	//mid�� ���� 
	long long nsum=0;
	for (int i = 1; i <= k ; i++) {
		nsum += (has[i] / mid);
	}
	if (nsum >=n) {
		dfs(mid + 1, max);
	}
	else {
		dfs(min, mid - 1);
	}
}
int main(void) {
	scanf("%lld %lld", &k, &n);
	for (int i = 1; i <= k; i++) {
		long long temp;
		scanf(" %lld", &temp);
		has[i] = temp;
		if(maximuns < temp){
			maximuns = temp;
		}
	}
	dfs(0, maximuns);

	printf("%lld", standard);
	return 0;
}