#include<iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct aa {
	int from;
	int to;
	int cost;
	aa(int n1, int n2, int n3) :from(n1), to(n2), cost(n3) {

	}
};
struct cmp {
	bool operator ()(aa a1, aa a2) {
		return a1.cost > a2.cost;
	}
};
priority_queue <aa, vector<aa>, cmp> pq;
vector <pair<int, int> > v[2001]; //건널목 저장하는 vector
vector<int> hubo,ans;
int n, m, t;
int s, g, h; //g<->h를 무조건 지나야된다
int a, b, d;
int dist[2001];// 거리저장배열
int visit_candidate_num[2001];//꼭 지나야하는 건널목 지낫는지 체크배열
void gogo() {
	while (pq.size() != 0) {
		int from = pq.top().from; //시작 점
		int to = pq.top().to; //가는 점
		int cost = pq.top().cost; //from->to까지의 cost
		pq.pop();
		if (dist[to] < dist[from] + cost) {
			continue;
		}//기존에 있는 값이 더 작다면 볼 필요도 없다잉 ~ 
		else {
			int check = 0;
			if (dist[to] == dist[from] + cost) { //to까지 최소거라와 지금가는 거리가 같을때 
				if (visit_candidate_num[to] == 1) {// 지금가는 경로에 꼭가야만 하는 길이 포함되어 있다면 
					check = 1;
				}
			}
			if (check != 1) {
				visit_candidate_num[to] = visit_candidate_num[from];
			}
			dist[to] = dist[from] + cost;//to점의 dist를 추가하고 !
			if ((to == g && from == h) || (to == h && from == g)){
				visit_candidate_num[to] = 1;
			}
			int vtosize = v[to].size();
			for (int j = 0; j<vtosize; j++) { //to점과 이어진 경로들
				int connect_to = v[to][j].first;
				int connect_to_cost = v[to][j].second;
				if (dist[connect_to] >= dist[to] + connect_to_cost) {
					//연결된 점(to)과 연결된 점(connect_to)의 dist값보다 지금 가는 값디 더 작거나 같을 때
					pq.push(aa(to, connect_to, connect_to_cost));
				}
			}//to점과 연결된 다른 점들을 큐에 넣는다 
			
		}
	}
}
void clear() {
	hubo.clear();
	ans.clear();
	while (pq.size() != 0) {
		pq.pop();
	}
	for (int i = 0; i <= 2000; i++) {
		v[i].clear();
		visit_candidate_num[i] = 0;
		dist[i] = 1000 * 2000;
	}
}
int main(void) {
	int T;
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++) {
		scanf("%d %d %d", &n, &m, &t);
		scanf("%d %d %d", &s, &g, &h);
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &d);
			v[a].push_back(make_pair(b, d));
			v[b].push_back(make_pair(a, d));
		}
		for (int i = 0; i < t; i++) {
			int x;
			scanf(" %d", &x);
			hubo.push_back(x);
		}
		for (int i = 1; i <= 2000; i++) {
			dist[i] = 1000 * 2000; 
		} //dist배열 초기화 
		pq.push(aa(s, s, 0));//시작점이 s다
		dist[s] = 0;
		gogo();

		int hubosize = hubo.size();
		for (int i = 0; i < hubosize; i++) {
			if (visit_candidate_num[hubo[i]] == 1) {
				ans.push_back(hubo[i]);
			}
		}
		sort(ans.begin(), ans.end());
		int anssize = ans.size();
		for (int i = 0; i < anssize; i++) {
			printf("%d ", ans[i]);
		} //printf("\n");
		clear();
	}
	return 0;
}