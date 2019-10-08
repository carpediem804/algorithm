#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
int must_num[1001]; //����Ǿ� �ִ� vertex ����
int node_time[1001]; //�� ��庰 �Ǽ� �ð�
int ans_time[1001]; //������ �ּ� �ð� 
int taked_time[1001]; //max ���ϱ� ����  
int visit[1001]; //�ٽ� �湮 x 
queue<int> q;
int map[1001][1001]; //������ �� �ʿ���� 
int n, k;
int endnode;
void clear() {
	for (int i = 1; i <= n; i++) {
		node_time[i] = 0;
		must_num[i] = 0;
		taked_time[i] = 0;
		ans_time[i] = 0;
		visit[i] = 0;
		for (int j = 1; j <= n; j++) {
			map[i][j] = 0;
		}
	}
	while (q.size() != 0) {
		q.pop();
	}
}
void bfs() {
	int tempans=0;
	while(q.size() != 0) {
		int qsize = q.size();
		for (int t = 0; t < qsize; t++) {
			int node = q.front();
			q.pop();
			//printf("node : %d time : %d\n", node, node_time[node]);
			if (node == endnode) {
				return;
			}//�߰����� ��
			for (int i = 1; i <= n; i++) {
				if (map[i][node] == 1) {
					must_num[i] -= 1;
					map[i][node] = 0;
					taked_time[i] = max(taked_time[i], ans_time[node]);
				}
			}//����� vertex ����� !! 
		}

		for (int i = 1; i <= n; i++) {
			ans_time[i] = node_time[i] + taked_time[i];
			if (must_num[i] == 0 && visit[i]==0) {
				visit[i] = 1;
				q.push(i);
			}
		}
	}
}
int main(void) {
	int T;
	scanf("%d ", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d %d", &n, &k);
		for (int i = 1; i <= n; i++) {
			scanf("%d ", &node_time[i]);
		}
		for (int i = 1; i <= k; i++) {
			int from, to;
			scanf("%d %d ", &from, &to);
			must_num[to] +=1;
			map[to][from] = 1;
		}
		scanf("%d", &endnode);
		for (int i = 1; i <= n; i++) {
			if (must_num[i] == 0) {
				visit[i] = 1;
				ans_time[i] = node_time[i];
				q.push(i);
			}
		}
		bfs();
		printf("%d\n", ans_time[endnode]);
		clear();
	}
}