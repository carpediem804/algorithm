#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
 
int N, M,fuel;
int map[22][22];
int visit[22][22];
//int driver_x, driver_y;
struct aa {
	int sx, sy, ex, ey, live;
	aa(int n1, int n2, int n3, int n4,int n5):sx(n1),sy(n2),ex(n3),ey(n4),live(n5) {

	}
};
vector <aa> customer;
bool cmp(aa &a1, aa &a2) {
	if (a1.sx == a2.sx) {
		return a1.sy < a2.sy;
	}

	return a1.sx < a2.sx;
}

int dir[4][2] = { {-1,0},{0,-1},{0,1},{1,0} };
int ans = 0;
int get_distance(int sx, int sy, int ex, int ey) {
	//printf("sx : %d sy : %d ex : %d ey : %d\n", sx, sy, ex, ey);
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			//printf("%d ",map[x][y]);
			visit[x][y] = 0;
		}//printf("\n");
	}

	if (sx == ex && sy == ey) { return 0; }
	queue<pair<int, int> > dq;
	dq.push(make_pair(sx, sy));
	visit[sx][sy] = 1;
	int cnt = 0;
	while (dq.size() != 0) {
		int dqsize = dq.size();
		for (int k = 0; k < dqsize; k++) {
			int x = dq.front().first;
			int y = dq.front().second;
			if (x == ex && y == ey) {
				return cnt;
			}
			dq.pop();
			for (int i = 0; i < 4; i++) {
				int dx = x + dir[i][0];
				int dy = y + dir[i][1];
				if (dx >= 1 && dx <= N && dy >= 1 && dy <= N) {
					if (visit[dx][dy] == 0 && map[dx][dy] == 0) {
						visit[dx][dy] = 1;
						dq.push(make_pair(dx, dy));
					}
				}
			}
		}
		cnt++;
	}

	return -1;
}
struct ab {
	int x, y, index;
	ab(int n1, int n2, int n3) :x(n1), y(n2), index(n3) {

	}
};
struct cmp2 {
	bool operator() (ab a1, ab a2) {
		if (a1.x == a2.x) {
			return a1.y > a2.y;
		}
		return a1.x > a2.x;
	}
};
void calc(int driver_x,int driver_y,int pick) {

	//printf("dirvier x : %d driver y : %d pick : %d\n", driver_x, driver_y, pick);
	if (pick >= M) { return; }
	//자동차에서 가장 가까운 손님 찾기 
	queue<pair<int, int> > q;
	q.push(make_pair(driver_x, driver_y));
	
	//int pick_fuel = 0;
	int pick_customer_index = -1;

	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			visit[x][y] = 0;
		}
	}
	priority_queue<ab, vector<ab>, cmp2> pq;

	while (q.size() != 0) {

		if (fuel < 0) { ans = -1; return; }
		int qsize = q.size();
		
		for (int k = 0; k < qsize; k++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
		
			visit[x][y] = 1;
			for (int i = 0; i < customer.size(); i++) {
				if (customer[i].live == 0) { continue; }
				if (x == customer[i].sx && y == customer[i].sy) {
					pq.push(ab(x,y,i));
					//customer[i].live = 0; //태운 친구야~ 
					break; 
				}
			}
			if (pq.size() != 0) { continue; }

			for (int i = 0; i < 4; i++) {
				int dx = x + dir[i][0];
				int dy = y + dir[i][1];
				if (dx >= 1 && dx <= N && dy >= 1 && dy <= N) {
					if (visit[dx][dy] == 0 && map[dx][dy] == 0) {
						visit[dx][dy] = 1;
						q.push(make_pair(dx, dy));
					}
				}
			}
		}
		if (pq.size() != 0) { break; }

		fuel--;
	}
	//태우기 
	if (pq.size() != 0) { // 승객을 태웟다~
		driver_x = pq.top().x;
		driver_y = pq.top().y;
		pick_customer_index = pq.top().index;
		customer[pick_customer_index].live = 0;
		pq.pop();
		while (pq.size() != 0) { pq.pop(); }
	}
	else {// 승객 못태운 경우 
		ans = -1; return;
	}


	if (fuel < 0) {
		ans = -1;
		return;
	}

	// 목적지 까지 가는 거리 측정 ~ 
	

	int end_x = customer[pick_customer_index].ex;
	int end_y = customer[pick_customer_index].ey;


	//printf("pick_ sx : %d pick_sy : %d fuel : %d \n", driver_x, driver_y,fuel);
	int distance = get_distance(driver_x, driver_y, end_x, end_y);
	//printf("distance : %d \n ", distance);
	// 연료 ++ or return ~ 
	if (distance == -1) { ans = -1; return; }
	if (fuel - distance < 0) { ans = -1; return; }
	fuel += (distance );
	//printf("fuel  : %d \n", fuel);
	calc(end_x, end_y, pick + 1);

	//이제 다시 자동차에서 가까운 손님 ~ 

}
int main(void) {
	scanf("%d %d %d", &N, &M,&fuel);
	
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			scanf(" %d", &map[x][y]);
		}
	}
	
	int driver_x, driver_y;
	scanf("%d %d", &driver_x, &driver_y);

	for (int i = 0; i < M; i++) {
			int x, y, ex, ey;
			scanf(" %d %d %d %d", &x, &y, &ex, &ey);
			customer.push_back(aa(x, y, ex, ey,1));
	}
	sort(customer.begin(), customer.end(),cmp);
	//for (int i = 0; i < customer.size(); i++) {
	//	printf(" %d %d \n", customer[i].sx, customer[i].sy);
	//}

//	q.push(make_pair(driver_x, driver_y));
	calc(driver_x,driver_y,0);
	if (ans == -1) { printf("-1\n"); return 0; }
	printf("%d\n", fuel);
	return 0;
}