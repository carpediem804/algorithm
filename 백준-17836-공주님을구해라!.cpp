#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
int m, n;
int must_in_time ;
int map[101][101];
int visit[101][101];
int gram_x, gram_y;
queue<pair<int, int>> q;
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
int to_gram_time = 987654321;
int temp_ans;
void bfs() {
	q.push(make_pair(1, 1));
	visit[1][1] = 1;
	int time = 0;
	
	while (q.size() != 0) {
		int qsize = q.size();
		
		for (int t = 0; t < qsize; t++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (x == n && y == m) {
				temp_ans = time;
				return;
			}
			for (int i = 0; i < 4; i++) {
				int dx = x + dir[i][0];
				int dy = y + dir[i][1];
				if (dx >= 1 && dx <= n && dy >= 1 && dy <= m) {
					if (visit[dx][dy] == 0 && map[dx][dy]!=1) {
						visit[dx][dy] = 1;
						q.push(make_pair(dx,dy));
						if (map[dx][dy] == 2) {
							to_gram_time = min(time+1,to_gram_time);
						}
					}
				}
			}
		}
		time++;
	}
}
int main(void) {
	
	scanf("%d %d %d", &n, &m,&must_in_time);
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= m; y++) {
			scanf(" %d", &map[x][y]);
			if (map[x][y] == 2) { gram_x = x; gram_y = y; }
		}
	}
	bfs();
	
	int real_ans = 987654321;
	//printf("temp_ans : %d to_gram_time : %d\n", temp_ans, to_gram_time);
	if (temp_ans == 0) { temp_ans = 987654321; }
	real_ans = min(real_ans, temp_ans);
	//printf("%d %d %d %d\n", gram_x, gram_y, n, m);
	//printf("%d             %d %d    \n", to_gram_time + abs(gram_x - n) + abs(gram_y - m), abs(gram_x - n), abs(gram_y - m));
	real_ans = min(real_ans,to_gram_time + abs(gram_x - n) + abs(gram_y - m));
	if (must_in_time < real_ans) {
		printf("Fail\n");
	}
	else {
		printf("%d\n", real_ans);
	}

	return 0;
}
