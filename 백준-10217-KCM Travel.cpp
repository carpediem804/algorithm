#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
struct aa {
	int connect, cost, day;
	aa(int n1, int n2, int n3) :connect(n1), cost(n2), day(n3) {

	}
};
vector <aa> route[101];//길정보 저장 
int cache[101][10001]; // 1번 노드에서 i번째 노드까지 j의 cost로 갈때 최소 데이 
int n, m, k;
struct pq_in {
	int next, cost, day;
	pq_in(int n1, int n2, int n3) :next(n1), cost(n2), day(n3) {

	}
};
struct cmp {
	bool operator()(pq_in a, pq_in b) {
		if (a.day == b.day) {
			return a.cost > b.cost;
		}
		return a.day > b.day;
	}
};
priority_queue<pq_in,vector<pq_in>,cmp> pq;
int main(void) {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d %d %d", &n, &m, &k);
		for (int i = 1; i <= k; i++) {
			int a, b, c, d;
			scanf("%d %d %d %d", &a, &b, &c, &d);
			route[a].push_back(aa(b, c, d));
		}//길정보 다 저장 했다 
		memset(cache, -1, sizeof(cache));
		cache[1][0] = 0;//처음값 초기화 ~ 
		pq.push(pq_in(1, 0, 0));
		while (pq.size() != 0) {
			int next_index = pq.top().next;
			int current_cost = pq.top().cost;
			int current_day = pq.top().day;
			//printf("current index : %d  cost : %d  day : %d\n", next_index, current_cost, current_day);
			pq.pop();

			if (current_cost > m || current_day > cache[next_index][current_cost]) { continue; }
				
			for (int i = 0; i < route[next_index].size(); i++) { //연결된 모드 노드 다 보기 
				int sum_cost = route[next_index][i].cost + current_cost;
				int sum_day = route[next_index][i].day + current_day;
				int connect = route[next_index][i].connect;
				if (sum_cost > m) {
					continue;
				}
				int& ret = cache[connect][sum_cost];
				if (ret == -1 || ret > sum_day) {
					ret = sum_day;
					pq.push(pq_in(connect, sum_cost, sum_day));
				}
			}

		}
		int tempans = 987654321;
		for (int i = 0; i <= m; i++) { //최대 코스트가  m이니까 
			//printf("i :%d  day : %d\n", i,cache[n][i]);
			if (cache[n][i] == -1) { continue; }
			else { tempans = min(tempans, cache[n][i]); }
		}
		if (tempans == 987654321) { printf("Poor KCM\n"); }
		else { printf("%d\n", tempans); }
		for (int i = 0; i <= n; i++) {
			route[i].clear();
		}
	}

	return 0;
}