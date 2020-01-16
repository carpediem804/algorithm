#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int n, m;
int k;
int bino[201][201];

string calc(int minus, int zero,int skip) {
	//printf("minus : %d zero : %d skip : %d dino[minus+zero-1][minus-1] : %d \n", minus, zero, skip, bino[minus + zero - 1][minus - 1]);
	if (minus == 0) {
		return string(zero, 'o');
	} // minus������ 0���� �������� �� 0���� ä���ߴ�
	if (skip <= bino[minus + zero - 1][minus - 1]) {
		return "-" + calc(minus - 1, zero, skip);
	} //-�� ��ù��¥ ä�� ����� ������ skip�� �� ������ ù��¥�� -�̴�
	else { //skip�� �� ũ�� ù���ڴ� 0 �̴�
		return "o" + calc(minus, zero-1, skip - bino[minus + zero - 1][minus - 1]);
	}
}
int main(void) {
	int C;
	scanf("%d", &C);
	for (int i = 0; i <= 200; i++) {
		bino[i][i] = 1;
		bino[i][0] = 1;
		for (int j = 1; j < i; j++) {
			bino[i][j] = min(bino[i - 1][j] + bino[i - 1][j - 1],1000000100);
		}
	} //���� ��� ä��� 
	
	for (int t = 1; t <= C; t++) {
		scanf("%d %d %d", &n, &m, &k);
		
		cout << calc(n, m, k) << "\n";
	
	}



	return 0;
}