#include <iostream>
#include <stdio.h>

using namespace std;
int n;
int dp[1000001];
int calc(int n) {
	if (n == 1) {
		return 1;
	}
	else if (n == 2) {
		return 2;
	}
	else if (n == 3) {
		return 3;
	}
	//���� ���
	int& ret = dp[n];
	if (ret != 0) {
		return ret;
	}//�̹� ����� �߾������ 
	 
	ret = calc(n - 1) + calc(n - 2);
	ret %= 15746;
	return ret;
}
int main(void) {
	scanf("%d", &n);
	//����� �ִ� ��� Ÿ�� ������ 
	printf("%d\n", calc(n));
	return 0;
}