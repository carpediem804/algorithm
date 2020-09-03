#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
int n, m;//n은 가로m은 세로
int map[101][101];
int visit[101][101];
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
int connect_num[7][7] ; //[a][b] == a와 b섬의 최소거리 
int can_go[7]; // 섬을 방문할 수 있따묜 1 아니면 0 ~ 

int ans ;
struct aa {
	int index, cost;
	aa(int n1, int n2) : index(n1), cost(n2) {

	}
};
struct cmp {
	bool operator ()(aa a1, aa a2) {
		return a1.cost > a2.cost;
	}
};
priority_queue<aa,vector<aa>,cmp> pq;

queue<pair<int, int>> q[7]; //각 섬마다의 점들 저장 
void bfs(int iland_index) {
	while (q[iland_index].size() != 0) {
		int x = q[iland_index].front().first;
		int y = q[iland_index].front().second;
		q[iland_index].pop();
	
		int up_x = x-1;
		int up_cnt = 0;
		while (up_x >= 1) {
			if (visit[up_x][y] == iland_index) {
				break;
			}
			if (visit[up_x][y] != iland_index && visit[up_x][y]!=0) {
				int visit_iland = visit[up_x][y];
				if ( connect_num[iland_index][visit_iland] > up_cnt) {
					if (up_cnt >= 2) {
						connect_num[iland_index][visit_iland] = up_cnt;
						
					}
					break; //거리 넣었으면 break한다잉 
				}
			}//다른섬 방문했따면 
			
			up_cnt++;
			up_x -= 1;
		}
		int down_x = x + 1;
		int down_cnt = 0;
		while (down_x <= n) {
			if (visit[down_x][y] == iland_index) {
				break;
			}
			if (visit[down_x][y] != iland_index && visit[down_x][y]!=0) {
				int visit_iland = visit[down_x][y];
				if (connect_num[iland_index][visit_iland] > down_cnt) {
					if (down_cnt >= 2){
						connect_num[iland_index][visit_iland] = down_cnt;
					}
					break; //거리 넣었으면 break한다잉 
				}
			}//다른섬 방문했따면 
			down_cnt++;
			down_x += 1;
		}

		int right_y = y + 1;
		int right_cnt = 0;
		while (right_y <= m) {
			if (visit[x][right_y] == iland_index) {
				break;
			}
			if (visit[x][right_y] != iland_index &&visit[x][right_y]!=0) {
				int visit_iland = visit[x][right_y];
				if (connect_num[iland_index][visit_iland] > right_cnt) {
					if (right_cnt >= 2) {
						connect_num[iland_index][visit_iland] = right_cnt;
					}
					break; //거리 넣었으면 break한다잉 
				}
			}//다른섬 방문했따면 
			right_cnt++;
			right_y += 1;
		}
		int left_y = y - 1;
		int left_cnt = 0;
		while (left_y >= 1) {
			if (visit[x][left_y] == iland_index) {
				break;
			}
			if (visit[x][left_y] != iland_index && visit[x][left_y]!=0) {
				int visit_iland = visit[x][left_y];
				if (connect_num[iland_index][visit_iland] > left_cnt) {
					if (left_cnt >= 2) {
						connect_num[iland_index][visit_iland] = left_cnt;
					}
					break; //거리 넣었으면 break한다잉 
				}
			}//다른섬 방문했따면 
		
			left_cnt++;
			left_y -= 1;
		}
	}
}
 void dfs(int x, int y, int iland_num) {
	
	for (int i = 0; i < 4; i++) {
		int dx = x + dir[i][0];
		int dy = y + dir[i][1];
	
		if (dx >= 1 && dx <= n && dy >= 1 && dy <= m) {
			if (map[dx][dy] == 1 && visit[dx][dy]==0) {
				visit[dx][dy] = iland_num;
				dfs(dx, dy, iland_num);
				q[iland_num].push(make_pair(dx, dy));
			}
		}
	}
}

 
int main(void) {
	scanf("%d %d ", &n, &m);
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= m; y++) {
			scanf(" %d", &map[x][y]);
			
		}
	}
	
	int iland = 1;
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= m; y++) {
			if (map[x][y] != 0 && visit[x][y]==0) {
				visit[x][y] = iland;
				q[iland].push(make_pair(x, y));
				dfs(x, y,iland);
				iland++;
			}
		}
	} //visit배열에 iland index순서로 저장되었다 


	for (int i = 1; i < iland; i++) {
		for (int j = 1; j < iland; j++) {
			connect_num[i][j]=101;
		}
	}
	for (int i = 1; i < iland; i++) {
		bfs(i);
	}

	can_go[1] = 1;
	for (int i = 1; i < iland; i++) {
		if (connect_num[1][i] != 101 && connect_num[1][i] >= 2) {
			pq.push(aa(i, connect_num[1][i]));
		}
	}// 1번 마을과 연결되는 애들 pq에 넣기 
	while (pq.size() != 0) {
		int idx = pq.top().index;
		int cost = pq.top().cost;
		if (can_go[idx] == 0) {
			ans += cost;
		}
		can_go[idx] = 1;
		pq.pop();
		for (int i = 1; i < iland; i++) {
			if (connect_num[idx][i] != 101 && connect_num[idx][i] >= 2 && can_go[i]==0) {
				pq.push(aa(i, connect_num[idx][i]));
			}
		}
	}//pqsize가 0일때 까지 
	for (int i = 1; i < iland; i++) {
		if (can_go[i] == 0) {
			printf("-1\n");
			return 0;
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}