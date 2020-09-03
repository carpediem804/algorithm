#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int map[701][701];  //�̰� �Ⱦ��°�
int visit[701][701]; //�湮�޴��� ���ߴ���


int n, m, k;
struct aa {
	int x, y, cost, active_time,left_time;
	aa(int n1, int n2, int n3, int n4,int n5) :x(n1), y(n2), cost(n3),active_time(n4),left_time(n5) {

	}
};
struct cmp {
	bool operator()(aa a1, aa a2) {
		if (a1.active_time == a2.active_time) { //Ȱ��ȭ�ð��� ���� �� cost�� ���� �ֺ��� Ȱ��ȭ ��Ų�� => �����ֶ� �������� ���Ǹ� ū�ְ� �̹� �湮�������� �Ⱥ���
			return a1.cost < a2.cost;
		}
		return a1.active_time > a2.active_time;
	}
};
priority_queue <aa, vector<aa>, cmp> pq;
queue <aa> q;
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
int ans;
void bfs() {
	int time = 0;
	while (pq.size() != 0) {
		int pqsize = pq.size();
		if (time == k) {
			return;
		}

		for (int t = 0; t < pqsize; t++) {
			int x = pq.top().x;
			int y = pq.top().y;
			int cost = pq.top().cost;			
			int active_time = pq.top().active_time;
			int left_time = pq.top().left_time;			
			if (left_time == 0) {
				pq.pop();
				continue;
			}

			if (time < active_time) {
				break;
			} //pq������ ģ������ ���� active time�� ���� x 
			else if(time == active_time){
				pq.pop();
				for (int i = 0; i < 4; i++) {
					int dx = x + dir[i][0];
					int dy = y + dir[i][1];
					if (dx >= 1 && dy >= 1 && dx <= 700 && dy <= 700) {
						if (visit[dx][dy]==0) {
							visit[dx][dy] = 1;// �湮�ߴٰ� fix�ϰ� 
							pq.push(aa(dx, dy, cost, active_time + cost + 1, left_time));
						}//���� ���׾��� �� && �ѹ��� �湮���� �� �϶�
					}
				}
				if (left_time > 0) { //���� ����ִ� �ð��� �������� 
					if (left_time != 1) {
						pq.push(aa(x, y, cost, active_time+1, left_time - 1));
					}
				}
			}
		}
		
		time++;
	}
}
int main(void) {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d %d %d", &n, &m, &k);

		for (int x = 1; x <= n; x++) {
			for (int y = 1; y <= m; y++) {
				int temp;
				scanf(" %d", &temp);
				map[x+350][y+350] = temp;
				if (temp != 0) {
					visit[x + 350][y + 350] = 1;
					pq.push(aa(x + 350, y + 350, temp, temp, temp));
				}
			}
		}
		bfs();
		ans = pq.size();
		printf("#%d %d\n", t, ans);
		while (pq.size() != 0) {
			pq.pop();
		}
		memset(visit, 0, sizeof(visit));
		memset(map, 0, sizeof(map));
	}
}
