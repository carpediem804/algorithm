/*
��Ŭ���� ȣ����
ax + by =c ���� 
gcd(a,b) a,b�� �ִ����� ==d�϶� 
d = ax+by���·� ǥ���� �� �ִ� ���� ���� �ڿ����̴�.

*/
#include <iostream>
#include <stdio.h>

using namespace std;

long long p = 1000000007;;
long long factorial[4000000];
long long x_after, x_before, temp, q;

void euclidean(long long a, long long b) {
	if (a%b > 0) {
		euclidean(b, a%b);
		temp = x_after;
		x_after = x_before - (a/b)*x_after;
		x_before = temp;
	}
	else {
		x_after = 1;
		x_before = 0;
	}
}
int main(void) {
	int n, k;
	scanf("%d %d", &n, &k);
	if (n == k || k == 0) {
		printf("1\n");
		return 0 ;
	}
	factorial[0] = factorial[1] = 1;
	for (int i = 2; i <= n; i++)
		factorial[i] = (factorial[i - 1] * i) % p;
	long long B = (factorial[k] * factorial[n - k]) % p;

	euclidean(p, B); //k! * n-k! mod p�� ���� p�� euclidian
	long long ans = ((factorial[n] % p)*(x_after%p)) % p;
	if (ans < 0) { ans += p; }
	printf("%lld\n", ans);

	return 0;
}