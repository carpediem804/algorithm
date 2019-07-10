#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int map[501][501];
int timemap[501][501];

int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
int dp(int x,int y) { //x,y�������� �ִ� �ϼ� 
	if (timemap[x][y] != 0) { return timemap[x][y]; }
	timemap[x][y] = 1;//return ��ų �ʱⰪ ���� 
	for (int i = 0; i < 4; i++) {
		int dx = x+dir[i][0];
		int dy = y+dir[i][1];
		if (dx >= 1 && dx <= n && dy >= 1 && dy <= n) {//�����ȿ�
			if (map[x][y] < map[dx][dy]) {
				timemap[x][y] = max(timemap[x][y],dp(dx,dy)+1);
			}//�̵������� �� 
		}
	}
	return timemap[x][y];
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %d", &map[i][j]);
		}
	}//map �׷Ǵ� 
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans = max(ans, dp(i, j));
		}
	}
	
	printf("%d", ans);
	return 0;
}