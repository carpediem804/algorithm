#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int map[6][6];
int ansnum;
string ans[100000];
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
bool check(string s) {
	for (int i = 1; i <= ansnum; i++) {
		if (s == ans[i]) {
			return false;
		}
	}
	return true;
}
void dfs(int x, int y, int cnt,string s) {
	if (cnt == 6) {
		if (check(s)) {
			ansnum++;
			ans[ansnum] = s;
			//printf("x : %d y : %d cnt : %d\n", x, y, cnt);
		//	cout << s << endl;
			return;
		}
		else return;
	}
	for (int i = 0; i < 4; i++) {
		int dx = x + dir[i][0];
		int dy = y + dir[i][1];
		if (dx >= 1 && dx <= 5 && dy >= 1 && dy <= 5) {
			string temp = s + to_string(map[dx][dy]);
			dfs(dx, dy, cnt + 1, temp);
		}
	}
}
int main(void) {
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			scanf(" %d", &map[i][j]);
		}
	}
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			string temp2 = to_string(map[i][j]);
			dfs(i, j, 1,temp2);
		}
	}
	printf("%d", ansnum);
	return 0;
}