#include <iostream>
#include <stdio.h>

using namespace std;
int N,X;
int map[21][21]; 
int visit[21][21]; //���� ���� �� üũ
int ans;
void calc() {
	int standard; //������
	int check = 1;
	for (int i = 1; i <= N; i++) {
		check = 1;
		for (int j = 1; j <= N; j++) {
			if (j == 1) {
				standard = map[i][j]; //������ ����
				continue;
			}
			if (standard+1 == map[i][j]) {
				//ū ���� �ö� 
				if (j - X < 1) {
					check = -1;
					break;
				} //���� �ٱ��̸� �ȵ� 
				for (int k = 1; k <= X; k++) {
					if (map[i][j] - 1 != map[i][j - k] || visit[i][j-k]==1) {
						check = -1;
						break;
					} // ���ΰ� �� ������ �ְų� ���� ���̰� �ƴϸ� 
				}
				for (int k = 1; k <= X; k++) {
					visit[i][j - k] = 1;
				} //���� ��ġ ~ 
				standard = map[i][j]; //������ �ٲٱ� ~ 
			}
			else if (standard-1 == map[i][j]) {
				//���� ���� �ö� 
				if (j + X -1 > N) {
					check = -1;
					break;
				} //���ΰ� ���� �ȿ� �������� �ִ� ��Ȯ�� 
				for (int k = 0; k < X; k++) {
					if (standard - 1 != map[i][j + k] || visit[i][j+k]==1) {
						check = -1;
						break;
					}
				} // ���ΰ� ��ġ�Ǿ� �ְų� ���̰� ������ Ȯ�� 
				for (int k = 0; k < X; k++) {
					visit[i][j + k] = 1;
				} // ���� ���� 
				standard = map[i][j]; //������ �ٲٱ� 
			}
			else if (standard == map[i][j]) {
				continue;
			}
			else {
				check = -1;
				break;
			}
		}
		if (check == 1) {
			ans++;
		}
	}
 // ���� ���� ���� ���� ��ġ�� ������ visit = 1�� �Ͽ��� 
//	���� ���� ���� ���� ��ġ�� ������ visit =2 �� �Ͽ��� ~ 
	for (int j = 1; j <= N; j++) {
		check = 1;
		for (int i = 1; i <= N; i++) {
			if (i == 1) {
				standard = map[i][j];
				continue;
			}
			if (standard + 1 == map[i][j]) {
				//ū ���� �ö� 
				if (i - X < 1) {
					check = -1;
					break;
				}
				for (int k = 1; k <= X; k++) {
					if (map[i][j] - 1 != map[i-k][j] || visit[i-k][j]==2) {
						check = -1;
						break;
					}
				}
				for (int k = 1; k <= X; k++) {
					visit[i - k][j] = 2;
				}
				standard = map[i][j];
			}
			else if (standard - 1 == map[i][j]) {
				//���� ���� �ö� 
				if (i + X -1 > N) {
					check = -1;
					break;
				}
				for (int k = 0; k < X; k++) {
					if (standard - 1 != map[i+k][j] || visit[i+k][j]==2) {
						check = -1;
						break;
					}
				}
				for (int k = 0; k < X; k++) {
					visit[i + k][j] = 2;
				}
				standard = map[i][j];
			}
			else if (standard == map[i][j]) {
				continue;
			}
			else {
				check = -1;
				break;
			}
		}
		if (check == 1) {
			ans++;
		}
	}
}
void clear() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			map[i][j] = 0;
			visit[i][j] = 0;
		}
	}
	ans = 0;
}
int main(void) {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d %d", &N, &X);
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				scanf(" %d", &map[i][j]);
			}
		}
		calc();
		printf("#%d %d\n", t, ans);
		clear();
	}
	return 0;
}