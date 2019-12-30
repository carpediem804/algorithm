#include <iostream>
#include <stdio.h>

using namespace std;

/*
�丣�� ������ 
p�� �Ҽ��̰� a�� p�� ����� �ƴϸ�, a�� p-1�� ��1(mod p) �̴�.
��, a�� p-1���� p�� ���� �������� 1�̴�.
*/
long long factorial[4000001]; //���丮�� ���尪
long long inv[4000001]; // x!�� inverse
long long p = 1000000007;
long long power(long long x, long long y) { // ���������� �̿��Ͽ� x^y�� ���ϱ�
	long long temp = 1;
	while (y > 0) {
		if (y % 2 == 1) { //Ȧ���� ��� 
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
	//inverse(fac(i))=inverse(fac(i+1))*(i+1)�̶�� ������ �̿��Ͽ� ��ó��
	long long ans = (factorial[n] * inv[n - k]) % p;
	ans = (ans*inv[k]) % p;
	printf("%lld\n", ans);

	return 0;
}