#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
int n, m;
int map[51][51];
int visit[51][51];
int virus[11][2];
int pick[11];
int viruscnt = 1;
int ans = 2147483647;
int tempans;
struct aa {
	int x;
	int y;
	aa(int n1, int n2) : x(n1), y(n2) {

	}
};
queue <aa> q;
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
void bfs() {

	//int time = 0;
	while (q.size() != 0) {

		int qsize = q.size();
		for (int i = 0; i < qsize; i++) {
			int x = q.front().x;
			int y = q.front().y;
			//visit[x][y] = time;
			q.pop();
			//printf("time : %d x : %d y : %d\n", time, x, y);
			for (int i = 0; i < 4; i++) {
				int dx = x + dir[i][0];
				int dy = y + dir[i][1];
				if (dx >= 1 && dx <= n && dy >= 1 && dy <= n) {
					if (map[dx][dy] != 1 && visit[dx][dy] == -1) {//갈수있는경우
						visit[dx][dy] = visit[x][y] + 1;
						q.push(aa(dx, dy));
					}
				}
			}
		}//시간마다 퍼지는거 측정됫다

	}//다퍼졋다 이제확인 
	int check = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == 0) {
				if (visit[i][j] == -1) {
					check = 1;
				}
				else {
					if (tempans < visit[i][j]) {
						tempans = visit[i][j];
					}
				}

			}//이게 안되는 경우
		}
	}
	if (check == 1) {
		//printf("안된다 %d\n",ans);
		if (ans == 2147483647) {
			ans = 2147483646;
		}
	}
	else {
		if (tempans < ans) {
			ans = tempans;
		}
	}
	//	printf("ans : %d tempans : %d\n", ans,tempans);
	tempans = 0;

}
void calc() {
	for (int i = 1; i <= 50; i++) {
		for (int j = 1; j <= 50; j++) {
			visit[i][j] = -1;
		}
	}
	for (int i = 1; i <= 10; i++) {
		if (pick[i] == 1) {
			//	printf("X : %d y : %d\n", virus[i][0], virus[i][1]);
			visit[virus[i][0]][virus[i][1]] = 0;
			q.push(aa(virus[i][0], virus[i][1]));
		}
	} // 선택된 바이러스들 큐에 넣는다 

	bfs();
}
void dfs(int end, int temp, int cnt) {
	if (end + 1 == cnt) {
		calc();
		return;
	}
	for (int i = temp; i <= viruscnt; i++) {
		if (pick[i] == 0) {
			pick[i] = 1;
			dfs(end, i + 1, cnt + 1);
		}
		pick[i] = 0;

	}

}
int main(void) {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int temp;
			scanf(" %d", &temp);
			if (temp == 2) {
				virus[viruscnt][0] = i;
				virus[viruscnt][1] = j;
				viruscnt++;
			}
			map[i][j] = temp;
		}
	} // map과 바이러스 정보저장햇다


	dfs(m, 1, 1);

	if (ans == 2147483646) {
		printf("-1\n");
	}
	else {
		printf("%d\n", ans);
	}

	return 0;
}