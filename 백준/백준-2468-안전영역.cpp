#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
int map[101][101];
int visit[101][101];
queue<pair<int, int>> q;
int N;
int maxrain;
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
void bfs(int water) {
	while (q.size() != 0) {
		int x = q.front().first;
		int y = q.front().second;
		
		q.pop();
		for (int i = 0; i < 4; i++) {
			int dx = x + dir[i][0];
			int dy = y + dir[i][1];
			if (dx >= 1 && dx <= N && dy >= 1 && dy <= N) {
				if (visit[dx][dy] == 0 && map[dx][dy] > water) {
					visit[dx][dy] = 1;
					q.push(make_pair(dx, dy));
				}
			}
		}
	}
}
int main(void) {
	
	scanf(" %d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf(" %d", &map[i][j]);
			if (map[i][j] > maxrain) maxrain = map[i][j];
		}
	}
	int tempans=0;
	int realans=0;
	for (int a = 0; a <= maxrain ; a++) {
		//printf("===============\n");
		tempans = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (visit[i][j] == 0 && map[i][j] > a) {
					tempans++;
					q.push(make_pair(i, j));
					visit[i][j] = 1;
					//printf("-------------\n");
					bfs(a);
				}//잠긴경우
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				visit[i][j] = 0;
			}
		}
		if (realans < tempans) {
			realans = tempans;
		}
	}
	printf("%d", realans);
	
}