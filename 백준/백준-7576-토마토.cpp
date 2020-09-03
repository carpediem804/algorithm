#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;
int map[1001][1001];
int visit[1001][1001] ; //-1�� �ʱ�ȭ
queue<pair<int, int>>q;
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };//���� 
int n, m;
void bfs() {
	int time = 1; //ó��ť���ִ� ������ 0�� �־����ϱ� �������ʹ� 1�̴�~ 
	while (q.size() != 0) {
		int qsize = q.size();
		for (int t = 0; t < qsize; t++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int dx = x + dir[i][0];
				int dy = y + dir[i][1];
				if (dx >= 1 && dx <= n && dy >= 1 && dy <= m) {
					if (map[dx][dy] == 0 && visit[dx][dy] == -1) {
						visit[dx][dy] = time;
						q.push(make_pair(dx, dy));
					}//������ �丶���� ��� && �ѹ��� �湮����������
				}
			}
		}
		time++;
	}
}
int main(void) {
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			visit[i][j] = -1;
		}
	}//visit�迭 -1�� �ʱ�ȭ
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int temp;
			scanf(" %d", &temp);
			if (temp == 1) {
				q.push(make_pair(i, j));
				visit[i][j] = 0; //���� �丶���� ��� visit�迭�� -1 -> 0���� �ʱ�ȭ 
			}
			map[i][j] = temp;
		}
	}//���� �丶��� ť�� �ְ� map�迭 Ȯ��
	
	bfs();

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (visit[i][j] == -1&&map[i][j]==0) { //�ѹ��� �湮 ���ߴµ� ������ ������ �丶��� -1�̴�~
				ans = -1;
				break;
			}
			else {
				if (ans < visit[i][j]) {
					ans = visit[i][j];
				}//�ִ�ð� ���ϴ� ��
			}
		}
		if (ans == -1) {
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}