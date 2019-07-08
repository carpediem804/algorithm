#include<iostream>
#include<stdio.h>

using namespace std;

int map[101];
int downcheck[101];
int n;
int temp = 0; //배열 초기화할지 안할지 체크하는고다잉
void dfs(int start, int next) {
	if (start == next) {
		downcheck[start] = 1;
		return;
	}//사이클일경우 
	if (downcheck[next] == 1) {
		temp = 1;
		return;
	}//사이클이 아닐 경우 ! 

	downcheck[next] = 1;
	dfs(start, map[next]);
	if (temp == 1) {
		downcheck[next] = 0; //배열초기화
	}
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &map[i]);
	}//map에 넣기 
	for (int i = 1; i <= n; i++) {
		temp = 0;
		if (downcheck[i] == 0) {
			dfs(i, map[i]);//각 점에서의 cycle 체크하기
		}
	}
	int cntans = 0;
	for (int i = 1; i <= n; i++) {
		if (downcheck[i] == 1) {
			cntans++;
		}
	}
	printf("%d\n", cntans);
	for (int i = 1; i <= n; i++) {
		if (downcheck[i] == 1) {
			printf("%d\n", i);
		}
	}
	return 0;
}