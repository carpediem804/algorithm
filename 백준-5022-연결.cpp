#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int a1x, a1y, a2x, a2y, b1x, b1y, b2x, b2y;
struct aa {
	int x, y;
	vector <pair<int, int>> v;
};
queue <aa> aq, bq;
queue <pair<int, int> > can_go;
vector <pair<int, int>> route;
int apicktempans;
int bpicktempans;
int visit[101][101];
int visit2[101][101];
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
int second_bfs(int what) {
	while (can_go.size() != 0) {
		can_go.pop();
	}
	if (what == 0) { //b가 갈수 있는 지찾는거 
		can_go.push(make_pair(b1x, b1y));
	}
	else if (what == 1) {
		can_go.push(make_pair(a1x, a1y));
	}
	int can = 0;
	while (can_go.size() != 0) {
			int cansize = can_go.size();
			can++;
			for (int k = 0; k < cansize; k++) {
				int x = can_go.front().first;
				int y = can_go.front().second;
				can_go.pop();
				for (int i = 0; i < 4; i++) {
					int dx = x + dir[i][0];
					int dy = y + dir[i][1];
					if (dx >= 0 && dx <= n && dy >= 0 && dy <= m) {
						if (what == 0) {
							if ((dx == a1x && dy == a1y) || (dx == a2x && dy == a2y)) {
								continue;
							}
						}
						else if (what == 1) {
							if ((dx == b1x && dy == b1y) || (dx == b2x && dy == b2y)) {
								continue;
							}
						}
						if (visit2[dx][dy] == 0) {
							visit2[dx][dy] = 1;
							if (what == 0) {
								if (dx == b2x && dy == b2y) {
									return can;
								}
							}
							else if (what == 1) {
								if (dx == a2x && dy == a2y) {
									return can;
								}
							}
							can_go.push(make_pair(dx, dy));
						}
					}
				}
			}
			
	}
	return 0;
}
void bfs(int what) { //what ==0 a부터 what==1 b부터
	int time = 1;
		while (aq.size() != 0) {
			int aqsize = aq.size();
			for (int k = 0; k < aqsize; k++) {
				int x = aq.front().x;
				int y = aq.front().y;
				route = aq.front().v;
				aq.pop();
				for (int i = 0; i < 4; i++) {
					int dx = x + dir[i][0];
					int dy = y + dir[i][1];
					if (dx >= 0 && dx <= n && dy >= 0 && dy <= m) {
						if (what == 0) {
							if ((dx == b1x && dy == b1y) || (dx == b2x && dy == b2y)) {
								continue;
							}
						}
						else if (what == 1) {
							if ((dx == a1x && dy == a1y) || (dx == a2x && dy == a2y)) {
								continue;
							}
						}
						if (visit[dx][dy] == 0) {
							visit[dx][dy] = 1;
							if (what == 0) {
								if (dx == a2x && dy == a2y) {
									for (int j = 0; j < route.size(); j++) {
										visit2[route[j].first][route[j].second] = 1;
									}

									int check = second_bfs(0);
									if (check == 0) {
										apicktempans = 987654321;
									}
									else {
										//printf("time : %d check : %d\n", time, check);
										apicktempans = time + check;
									}
									return;
								}//최단거리 찾았따!!
							}
							else if (what == 1) {
								if (dx == b2x && dy == b2y) {
									for (int j = 0; j < route.size(); j++) {
										visit2[route[j].first][route[j].second] = 1;
									}
									int check = second_bfs(1);
									if (check == 0) {
										bpicktempans = 987654321;
									}
									else {
										//printf("time : %d check : %d\n", time, check);
										bpicktempans = time + check;
									}
									return;
								}//최단거리 찾았따!!
							}
								aa temp;
								temp.x = dx;
								temp.y = dy;
								//printf("route에 push dx: %d dy :%d\n", dx, dy);
								vector <pair<int, int>> tempvector;
								tempvector = route;
								tempvector.push_back(make_pair(dx, dy));
								temp.v = tempvector;
								aq.push(temp);
							
						}
					}
				}
			}
			time++;
		}
	
}
void clear() {
	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			visit[i][j] = 0;
			visit2[i][j] = 0;
		}
	}
	while (aq.size() != 0) { aq.pop(); }
	while (bq.size() != 0) { bq.pop(); }
	while (can_go.size() != 0) { can_go.pop(); }
	route.clear();

}
int main(void) {
	scanf("%d %d", &n, &m);
	scanf(" %d %d", &a1x, &a1y);
	scanf(" %d %d", &a2x, &a2y);
	scanf(" %d %d", &b1x, &b1y);
	scanf(" %d %d", &b2x, &b2y);
	aa a1;
	a1.x = a1x;
	a1.y = a1y;
	a1.v.push_back(make_pair(a1x, a1y));
	aq.push(a1);
	bfs(0);
	printf("tempans : %d\n", apicktempans);
	clear();
	aa b1;
	b1.x = b1x;
	b1.y = b1y;
	b1.v.push_back(make_pair(b1x, b1y));
	aq.push(b1);
	bfs(1);
	printf("bpick :%d\n", bpicktempans);
	if (apicktempans == 987654321 && bpicktempans == 987654321) {
		printf("IMPOSSIBLE\n");
	}
	else {
		printf("%d\n", min(apicktempans, bpicktempans));
	}
	
	return 0;
}