#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;
char map[21][21];
char visit[401];
int _x, _y;
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
int ans = 0;
bool check(int num,char s) {
	for (int i = 1; i <= num; i++) {
		if (visit[i] == s) {
			return false;
		}
	}
	return true;
} //������ �ִ� �� üũ 
void dfs(int x, int y, int cnt) {
//	printf("x : %d y : %d cnt : %d\n", x, y, cnt);
	if (ans < cnt) {
		ans = cnt;
	}
	visit[cnt] = map[x][y]; //�湮������ visit�迭�� �߰�
	for (int i = 0; i < 4; i++) {
		int dx = x + dir[i][0];
		int dy = y + dir[i][1];
		if (dx >= 1 && dx <= _x && dy >= 1 && dy <= _y) {
			if (check(cnt, map[dx][dy])) { 
				dfs(dx, dy, cnt + 1);
				visit[cnt + 1] = 0;
			}//�湮�� ���� ���̶��  dfs������ dfs �������� visit �װ� �ʱ�ȭ 
		}
	}
}
int main(void) {
	scanf("%d %d", &_x, &_y);
	for (int i = 1; i <= _x; i++) {
		for (int j = 1; j <= _y; j++) {
			scanf(" %1c", &map[i][j]);
			//printf("%c ", map[i][j]);
		}//printf("\n");
	}
	dfs(1, 1, 1);
	printf("%d", ans);
	return 0;
}