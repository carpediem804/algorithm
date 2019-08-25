#include <iostream>
#include <stdio.h>

using namespace std;
int N,X;
int map[21][21]; 
int visit[21][21]; //경사로 놓는 점 체크
int ans;
void calc() {
	int standard; //기준점
	int check = 1;
	for (int i = 1; i <= N; i++) {
		check = 1;
		for (int j = 1; j <= N; j++) {
			if (j == 1) {
				standard = map[i][j]; //기준점 설정
				continue;
			}
			if (standard+1 == map[i][j]) {
				//큰 값이 올때 
				if (j - X < 1) {
					check = -1;
					break;
				} //범위 바깥이면 안됨 
				for (int k = 1; k <= X; k++) {
					if (map[i][j] - 1 != map[i][j - k] || visit[i][j-k]==1) {
						check = -1;
						break;
					} // 경사로가 안 놓아져 있거나 같은 높이가 아니면 
				}
				for (int k = 1; k <= X; k++) {
					visit[i][j - k] = 1;
				} //경사로 설치 ~ 
				standard = map[i][j]; //기준점 바꾸깅 ~ 
			}
			else if (standard-1 == map[i][j]) {
				//작은 값이 올때 
				if (j + X -1 > N) {
					check = -1;
					break;
				} //경사로가 범위 안에 놓여질수 있는 지확인 
				for (int k = 0; k < X; k++) {
					if (standard - 1 != map[i][j + k] || visit[i][j+k]==1) {
						check = -1;
						break;
					}
				} // 경사로가 설치되어 있거나 높이가 같은지 확인 
				for (int k = 0; k < X; k++) {
					visit[i][j + k] = 1;
				} // 경사로 놓기 
				standard = map[i][j]; //기준점 바꾸기 
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
 // 가로 줄을 볼때 경사로 설치된 점들은 visit = 1로 하였고 
//	세로 줄을 볼때 경사로 설치된 점들은 visit =2 로 하였다 ~ 
	for (int j = 1; j <= N; j++) {
		check = 1;
		for (int i = 1; i <= N; i++) {
			if (i == 1) {
				standard = map[i][j];
				continue;
			}
			if (standard + 1 == map[i][j]) {
				//큰 값이 올때 
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
				//작은 값이 올때 
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