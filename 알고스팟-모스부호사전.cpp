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
	} // minus개수가 0개면 나머지는 다 0으로 채워야댐
	if (skip <= bino[minus + zero - 1][minus - 1]) {
		return "-" + calc(minus - 1, zero, skip);
	} //-로 맨첫글짜 채운 경우의 수보다 skip이 더 작으면 첫글짜는 -이다
	else { //skip이 더 크면 첫글자는 0 이다
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
	} //이항 계수 채우기 
	
	for (int t = 1; t <= C; t++) {
		scanf("%d %d %d", &n, &m, &k);
		
		cout << calc(n, m, k) << "\n";
	
	}



	return 0;
}