#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
int N, M;
char map[51][51];

struct aa {
	int x, y;
};
aa item[7];
int order[7];
int order_visit[7];
int item_num;
int st_x, st_y;
int end_x, end_y;
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
int real_ans = 987654321;
int from_to_length(int f_x, int f_y, int t_x, int t_y) {
	queue <pair<int, int>> q;
	q.push(make_pair(f_x, f_y));
	int visit[51][51] = { 0, };
	int cnt = 0;

	while (q.size() != 0) {
		int qsize = q.size();
		for (int i = 0; i < qsize; i++) {
			int x = q.front().first;
			int y = q.front().second;
			//			printf("%d %d\n", x, y);
			q.pop();
			if (x == t_x && y == t_y) {
				//		printf("%d,%d 에서 %d,%d 까지 cnt : %d\n", f_x, f_y, t_x, t_y,cnt);
				return cnt;
			}
			visit[x][y] = 1;
			for (int a = 0; a < 4; a++) {
				int dx = x + dir[a][0];
				int dy = y + dir[a][1];
				if (dx >= 1 && dx <= N & dy >= 1 && dy <= M) {
					if (map[dx][dy] != '#' && visit[dx][dy] == 0) {
						visit[dx][dy] = 1;
						q.push(make_pair(dx, dy));
					}
				}
			}
		}
		cnt++;
	}

}
void calc() {
	int temp_ans = 0;

	for (int i = 0; i <= item_num; i++) {
		int st_index = order[i];
		int end_index = order[i + 1];
		temp_ans += from_to_length(item[st_index].x, item[st_index].y, item[end_index].x, item[end_index].y);
	}
	//printf("temp_Ans : %d\n", temp_ans);
	real_ans = min(temp_ans, real_ans);
}
void dfs(int index) {
	//printf("index: %d item_num : %d\n", index, item_num);
	if (index == item_num + 1) {
		//	for (int i = 0; i <= item_num+1; i++) {
		//		printf("%d ", order[i]);
		//	}printf("\n");
		calc();
		return;
	}
	for (int i = 1; i <= item_num; i++) {
		if (order_visit[i] == 0) {
			order[index] = i;
			order_visit[i] = 1;
			dfs(index + 1);
			order_visit[i] = 0;
		}
	}
}
int main(void) {
	scanf("%d %d", &M, &N);

	item_num = 0; //1부터
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= M; y++) {
			scanf(" %c", &map[x][y]);
			if (map[x][y] == 'X') { item_num++; item[item_num].x = x; item[item_num].y = y; }
			if (map[x][y] == 'S') { st_x = x; st_y = y; }
			if (map[x][y] == 'E') { end_x = x; end_y = y; }
		}
	}

	item[0].x = st_x;
	item[0].y = st_y;
	item[item_num + 1].x = end_x;
	item[item_num + 1].y = end_y;
	order[item_num + 1] = item_num + 1;
	dfs(1);

	printf("%d\n", real_ans);


	return 0;
}