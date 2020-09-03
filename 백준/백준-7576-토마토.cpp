#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;
int map[1001][1001];
int visit[1001][1001] ; //-1로 초기화
queue<pair<int, int>>q;
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };//방향 
int n, m;
void bfs() {
	int time = 1; //처음큐에있는 값에는 0을 넣엇으니까 다음부터는 1이다~ 
	while (q.size() != 0) {
		int qsize = q.size();
		for (int t = 0; t < qsize; t++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int dx = x + dir[i][0];
				int dy = y + dir[i][1];
				if (dx >= 1 && dx <= n && dy >= 1 && dy <= m) {
					if (map[dx][dy] == 0 && visit[dx][dy] == -1) {
						visit[dx][dy] = time;
						q.push(make_pair(dx, dy));
					}//안익은 토마토인 경우 && 한번도 방문안했을때만
				}
			}
		}
		time++;
	}
}
int main(void) {
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			visit[i][j] = -1;
		}
	}//visit배열 -1로 초기화
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int temp;
			scanf(" %d", &temp);
			if (temp == 1) {
				q.push(make_pair(i, j));
				visit[i][j] = 0; //익은 토마토의 경우 visit배열을 -1 -> 0으로 초기화 
			}
			map[i][j] = temp;
		}
	}//익은 토마토는 큐에 넣고 map배열 확정
	
	bfs();

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (visit[i][j] == -1&&map[i][j]==0) { //한번도 방문 안했는데 그점이 안익은 토마토면 -1이다~
				ans = -1;
				break;
			}
			else {
				if (ans < visit[i][j]) {
					ans = visit[i][j];
				}//최대시간 구하는 것
			}
		}
		if (ans == -1) {
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}