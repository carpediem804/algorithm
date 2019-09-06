#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int N;
int map[21][21];
int visit[21][21];
struct aa {
	int x, y, size, eatnum;
};
aa shark;
queue <pair<int, int>> q;
vector<pair<int, int>> v;
struct test {
	int x, y;
};
bool cmp(test a1, test a2){

}
int ans;
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
void clear() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			visit[i][j] = 0;
		}
	}
	v.clear();
	while (q.size() != 0) { q.pop(); }
}
void bfs() {
	int time = 0;
	while (1) {
		q.push(make_pair(shark.x, shark.y));
		visit[shark.x][shark.y] = 1;
		time = 0;
		while (q.size()!=0) {
			int qsize = q.size();
			for (int k = 0; k < qsize; k++) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				for (int i = 0; i < 4; i++) {
					int dx = x + dir[i][0];
					int dy = y + dir[i][1];
					if (dx >= 1 && dx <= N && dy >= 1 && dy <= N) {
						if (visit[dx][dy] == 0) {
							if (map[dx][dy] == shark.size || map[dx][dy] == 0) {
								visit[dx][dy] = 1;
								q.push(make_pair(dx, dy));
							}
							else if (map[dx][dy] < shark.size) {
								v.push_back(make_pair(dx, dy));
							}
						}
					}
				}
			}
			time++;
			if (v.size() != 0) {
				break;
			}//먹을수 있는 친구들이없을때 return 
		}
		if (v.size() == 0) {
			return;
		}
		sort(v.begin(), v.end());
		ans += time;
		int eatx = v[0].first;
		int eaty = v[0].second;
		
		map[eatx][eaty] = 0;
		
		shark.x = eatx;
		shark.y = eaty;
	
		if (shark.eatnum + 1 == shark.size) {
			shark.size += 1;
			shark.eatnum = 0;
		}
		else {
			shark.eatnum += 1;
		}
		clear();
	}
}

int main(void) {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int temp;
			scanf(" %d", &temp);
			if (temp == 9) {
				shark.x = i;
				shark.y = j;
				shark.size = 2;
				shark.eatnum = 0;
			}
			else {
				map[i][j] = temp;
			}
		}
	}
	bfs();
	printf("%d\n", ans);
	return 0;
}