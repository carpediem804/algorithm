#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
vector <pair<int,int>> convenience[101];
int visit[101];
int n;
int startx, starty;
int endx, endy;
int ans;
void dfs(int x, int y, int bottle) {
	if ((abs(x - endx) + abs(y - endy)) <= 1000) {
		ans = 1;
		return;
	}//갈수있으면 ans = 1로 바꾸고 return ;
	for (int i = 1; i <= n; i++) {
		int dx = convenience[i].front().first;
		int dy = convenience[i].front().second;
		if (visit[i]==0 && abs(x - dx) + abs(y - dy) <= 1000) {
			visit[i] = 1;
			dfs(dx, dy, 20);
			if (ans == 1) {
				return;
			}
		}
	}//모든 편의점 

}
void clear() {
	ans = 0;
	for (int i = 1; i <= n; i++) {
		convenience[i].clear();
	}//vector 초기화
	for (int i = 1; i <= n; i++) {
		visit[i] = 0;
	}
}
int main(void) {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d", &n);
		scanf("%d %d", &startx, &starty);
		for (int i = 1; i <= n; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			convenience[i].push_back(make_pair(a, b));
		}
		scanf("%d %d", &endx, &endy);
		//다입력 받았다
		dfs(startx, starty, 20);
		if (ans == 1) {
			printf("happy\n");
		}
		else { printf("sad\n"); }
		clear();
	}
	return 0;
}