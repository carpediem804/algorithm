#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int map[801][801];
int dist1[801];//무조건 방문해야하는 기준점에서 모든정점의 거리저장
int n, e;
struct aa {
	int startindex;
	int cost;
	int previusindex;
	aa(int n1, int n2, int n3) :startindex(n1), cost(n2), previusindex(n3) {

	}
};
struct cmp {
	bool operator ()(aa a1, aa a2) {
		return a1.cost > a2.cost;
	}
};
priority_queue <aa, vector<aa>, cmp> pq;
void find() {
	while (pq.size() != 0) {
		int startnode = pq.top().startindex;
		int cost = pq.top().cost;
		int previousnode = pq.top().previusindex;
		pq.pop();
		if (cost <= dist1[startnode]) { //기존의 cost보다 같거나 작을때만
			for (int i = 1; i <= n; i++) {
				if (map[startnode][i] != 0 ) {//연결된 점이 있을때
					if (dist1[i] > dist1[startnode] + map[startnode][i]) { //원래 있는 값보다 지금 오는 게 더 작으면 수정해야하니까 그것 pq에 넣는다 
						dist1[i] = min(dist1[i], dist1[startnode] + map[startnode][i]);
						pq.push(aa(i, dist1[i], startnode));
					}
				}
			}
		}
	}
}
void clear() {
	for (int i = 1; i <= n; i++) {
		dist1[i] = 1000*800;
	}
}
int main(void) {
	scanf("%d %d", &n, &e);
	for (int i = 0; i < e; i++) {
		int x, y, c;
		scanf("%d %d %d", &x, &y, &c);
		map[x][y] = c;
		map[y][x] = c;
	}
	int mustgo1, mustgo2;
	scanf("%d %d", &mustgo1, &mustgo2);
	
	for (int i = 1; i <= n; i++) {
		dist1[i] = 1000 * 800;
	} // dist1 배열 최대값으로 초기화 ~ 

	pq.push(aa(mustgo1, 0, mustgo1));//기준점 큐에 넣어주기
	dist1[mustgo1] = 0; //자기 자신의 점은 0으로 바꾸고 
	find(); // mustgo1점에서 모든 노드까지의 최단거리 구하는 함수 
	
	
	int must1_to_one = dist1[1]; //mustgo1에서 1노드까지의 최단거리 
	int must1_to_must2 = dist1[mustgo2]; //mustgo1에서 mustgo2노드까지의 최단거리
	int must1_to_last = dist1[n];  //mustgo1노드에서 마지막 노드까지의 최단거리 
	
	clear(); // dist1배열 초기화 pq는 이미 size가 0이다~
	pq.push(aa(mustgo2, 0, mustgo2));//mustgo2점에서 모든 점까지의 최단거리
	dist1[mustgo2] = 0; //자기자신은 거리가 0이다
	find(); //mustgo2점에서 모든 노드까지의 최단거리 구하는 함수 
	
	int must2_to_one = dist1[1]; //mustgo2에서 노드 1까지의 최단거리
	int must2_to_must1 = dist1[mustgo1]; //mustgo2에서 mustgo1노드까지의 최단거리
	int must2_to_last = dist1[n]; // mustgo2에서 마지막 노드까지의 최단거리
	
	int ans = min(must1_to_one + must1_to_must2 + must2_to_last, must2_to_one + must2_to_must1 + must1_to_last);
	//총 두개의 경우가 있다 : 
	// 1. must1노드에서 1번 노드까지 최단거리 +must1노드에서 must2노드 까지 최단거리 +must2노드에서 last노드까지 최단거리 
	// 2. must2노드에서 1번 노드까지 최단거리 + must2노드에서 must1노드까지 최단거리 +must1노드에서 last 노드 까지 최단거리 
	if (ans >= 800 * 1000) {
		printf("-1\n");
	}
	else { printf("%d\n", ans); }
	return 0;
}