#include <iostream>
#include <stdio.h>

using namespace std;

/*
페르마 소정리 
p가 소수이고 a가 p의 배수가 아니면, a의 p-1승 ≡1(mod p) 이다.
즉, a의 p-1승을 p로 나눈 나머지는 1이다.
*/
long long factorial[4000001]; //팩토리얼 저장값
long long inv[4000001]; // x!의 inverse
long long p = 1000000007;
long long power(long long x, long long y) { // 분할정복을 이용하여 x^y승 구하기
	long long temp = 1;
	while (y > 0) {
		if (y % 2 == 1) { //홀수인 경우 
			temp *= x;
			temp %= p;
		}
		
		x *= x;
		x %= p;
		y /= 2;
	}
	return temp;
}
int main(void) {
	int n, k;
	scanf("%d %d", &n, &k);
	if (n == k || k == 0) {
		printf("1\n");
		return 0;
	}
	factorial[1] = 1;
	for (int i = 2; i <= 4000000; i++) {
		factorial[i] = (factorial[i - 1] * i) % p;
	}
	inv[4000000] = power(factorial[4000000], p-2);
	for (int i = 4000000 - 1; i > 0; i--)
		inv[i] = (inv[i + 1] * (i + 1)) % p;    
	//inverse(fac(i))=inverse(fac(i+1))*(i+1)이라는 수식을 이용하여 전처리
	long long ans = (factorial[n] * inv[n - k]) % p;
	ans = (ans*inv[k]) % p;
	printf("%lld\n", ans);

	return 0;
}