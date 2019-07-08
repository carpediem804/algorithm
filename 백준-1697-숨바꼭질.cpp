#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;
int visit[100001];
int n,k;
queue <int> q;
int ans;
void bfs() {
	int time = 0;
	while (q.size() != 0) {
		int qsize = q.size();
		
		for (int i = 0; i < qsize; i++) {
			int x = q.front();
			q.pop();
			if (x == k) {
				ans = time;
				return;
			}
			if (x - 1 <= 100000 && visit[x-1]==0) {
				visit[x - 1] = 1;
				q.push(x - 1);
			}
			if (x + 1 <= 100000 && visit[x + 1] == 0) {
				visit[x + 1] = 1;
				q.push(x + 1);
			}
			if (x * 2 <= 100000 && visit[x * 2] == 0) {
				visit[x * 2] = 1;
				q.push(x * 2);
			}
		}
		time++;
	}
}
int main(void) {
	scanf("%d %d", &n,&k);
	q.push(n);
	bfs();
	printf("%d", ans);
}