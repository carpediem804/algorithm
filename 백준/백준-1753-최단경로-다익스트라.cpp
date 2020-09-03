#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_NUM = 987654321;
int v, e;
int k;
int ans[20001];
struct aa {
	int  start_vertex, cost;
	aa(int n2, int n3) : start_vertex(n2), cost(n3) {

	}
};
struct cmp {
	bool operator ()(aa a1, aa a2) {
		return a1.cost > a2.cost;
	}
};
struct edge_cost {
	int connect_vertex, cost;
	edge_cost(int n1, int n2) :connect_vertex(n1), cost(n2) {

	}
};
priority_queue<aa, vector<aa>, cmp> pq;
vector <edge_cost> edge[20001];
int main(void) {
	scanf("%d %d", &v, &e);
	scanf("%d", &k);
	for (int i = 1; i <= e; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edge[a].push_back(edge_cost(b, c));
	}
	for (int i = 1; i <= v; i++) {
		if (i == k) { ans[i] = 0; }
		else { ans[i] = MAX_NUM; }
	}
	pq.push(aa(k, 0)); //시작점은 cost가 0이당 ~ 
	while (pq.size() != 0) {
		int pick_vertex = pq.top().start_vertex;
		int cost = pq.top().cost;
		//printf("pick_vertex : %d cost : %d\n", pick_vertex, cost);
		pq.pop();
		
		for (int i = 0; i < edge[pick_vertex].size(); i++) {//vertex와 연결된 모든 cost값 계산해서 업데이트
			int next_vertex = edge[pick_vertex][i].connect_vertex;
			int next_cost = edge[pick_vertex][i].cost;
			if (ans[next_vertex] > cost + next_cost) {
				ans[next_vertex] = cost + next_cost;
				pq.push(aa(next_vertex, next_cost + cost));
			}
		}
	}

	for (int i = 1; i <= v; i++) {
		if (ans[i] == MAX_NUM) {
			printf("INF\n");
		}
		else {
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}