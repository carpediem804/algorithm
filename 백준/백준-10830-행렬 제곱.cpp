#include <iostream>
#include <stdio.h>

using namespace std;
int map[6][6];
int ans_map[6][6];
int temp_map[6][6];
int n;
long long b;
void calc(long long _n) {

	//�������� 1 �̸�
	if (_n == 1) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				temp_map[i][j] = map[i][j] % 1000;
			}
		}
		return;
	}//
	if (_n % 2 == 0) {//¦���� �������� 
		
		calc(_n / 2); //��갪�� temp_map�� �ٲ������� 
		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				ans_map[i][j] = 0;
				for (int k = 1; k <= n; k++) {
					ans_map[i][j] += temp_map[i][k] * temp_map[k][j];
				}
				ans_map[i][j] %= 1000;
			}
		}
		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				temp_map[i][j] = ans_map[i][j];
			}
		}
		return;
	}
	else {//Ȧ���϶� 
		calc(_n - 1);
		//map�� �ѹ� ���ؾ��� 
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				ans_map[i][j] = 0;
				for (int k = 1; k <= n; k++) {
					ans_map[i][j] += temp_map[i][k] * map[k][j];
				}
				ans_map[i][j] %= 1000;
			}
		}
		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				temp_map[i][j] = ans_map[i][j];
			}
		}
		return;
	}

	
	//b^6 = (b^3)^2
	
}
int main(void) {

	
	scanf("%d %lld", &n, &b);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	calc(b);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", temp_map[i][j]);
		}printf("\n");
	}

	return 0;
}