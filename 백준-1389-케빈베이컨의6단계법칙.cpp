#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector <int> v[101];
vector <pair<int, int>> ans;
queue<int> q;
int ansmap[101][101];
int visit[101];
int n, m;
void bfs() {
	int connect = 0;
	int startpoint = q.front();
	while (q.size() != 0) {
		int qsize = q.size();
		for (int k = 0; k < qsize; k++) {
			int connectpoint = q.front();
			visit[connectpoint] = 1;
			ansmap[startpoint][connectpoint] = connect;
			q.pop();
			int vsize = v[connectpoint].size();
			for (int i = 0; i < vsize; i++) {
				if (visit[v[connectpoint][i]] == 0) {
					visit[v[connectpoint][i]] = 1;
					q.push(v[connectpoint][i]);
				}
			}
		}
		connect++;
		//printf("-----------\n");
	}
}
int main(void) {
	scanf("%d %d", &n,&m);
	for (int i = 1; i <= m; i++) {
		int from, to;
		scanf(" %d %d", &from, &to);
		v[from].push_back(to);
		v[to].push_back(from);
	}
	for (int i = 1; i <= n; i++) {
		while (q.size() != 0) { q.pop(); }
		q.push(i);
		bfs();
		for (int k = 1; k <= n; k++) {
			visit[k] = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		int temp = 0;
		for (int j = 1; j <= n; j++) {
			temp += ansmap[i][j];
			//printf("%d ", ansmap[i][j]);
		}//printf("\n");
		ans.push_back(make_pair(temp, i));

	}
	sort(ans.begin(), ans.end());
	printf("%d\n", ans[0].second);
	return 0;
}