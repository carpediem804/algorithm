#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;
int n, k,s;
int check[401];
vector <int> v[401];
queue <int >q;
bool bfs(int from, int to) {
	q.push(from);
	check[from] = 1;
	while (q.size() != 0) {
		int qsize = q.size();
		for (int i = 0; i < qsize; i++) {
			int find = q.front();
			//printf("%d\n", find);
			q.pop();
			for (int j = 0; j < v[find].size(); j++) {
				if (check[v[find][j]] == 0) {
					check[v[find][j]] = 1;
					if (to == v[find][j]) { //찾는 값이랑 같다면
						return true;
					}
					q.push(v[find][j]);//큐에 연결된친구들 넣기
				}
			}//연결된 애들만큼 ~ 
		}
	}
	return false;
}
void clear() {
	while (q.size() != 0) {
		q.pop();
	}
	for (int i = 1; i <= n; i++) {
		check[i] = 0;
	}
}
int main(void) {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= k; i++) {
		int first, second;
		scanf("%d %d", &first, &second);
		v[first].push_back(second);
	}//vector에 넣엇다 
	scanf(" %d", &s);
	for (int i = 0; i < s; i++) {
		clear();
		int q1, q2;
		scanf(" %d %d", &q1, &q2);
		if (bfs(q1, q2)) { printf("-1\n"); continue; }
		clear();
		if (bfs(q2, q1)) { printf("1\n"); continue; }
		printf("0\n");
		
	}
	return 0;
}