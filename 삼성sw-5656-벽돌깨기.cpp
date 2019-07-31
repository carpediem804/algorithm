#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;
int map[16][13];
int clonemap[16][13];
int visit[16][13];
int route[5]; // ������ ��� �������� ���ϱ� 
struct aa {
	int x;
	int y;
	int num;
	aa(int n1, int n2, int n3) :x(n1), y(n2), num(n3) {

	}
};
int realans = 12 * 15;
queue <aa> q;
int n, w, h;
void broke(int dir) { //dir == ������ �������� y��
	for (int i = 1; i <= h; i++) {
		if (map[i][dir] != 0) {
			//printf("x : %d y : %d num : %d\n", i, dir, map[i][dir]);
			q.push(aa(i, dir, map[i][dir]));
			break;
		}//ó������ 0�� �ƴ� ���� �߰��ߴ�! ->queue�� �־���
	}
	while (q.size() != 0) {
		int x = q.front().x;
		int y = q.front().y;
		int num = q.front().num;
		q.pop();
		map[x][y] = 0;
		//���ʹ��⺸��
		for (int i = 1; i <= num-1; i++) {
			if (y-i>=1 && map[x][y - i] != 0 &&visit[x][y-i]==0) {
				visit[x][y - i] = 1;
				q.push(aa(x, y - i, map[x][y - i]));
			} //���ʹ���
			if (x-i>=1 && map[x - i][y] != 0 &&visit[x-i][y]==0) {
				visit[x - i][y] = 1;
				q.push(aa(x - i, y, map[x - i][y]));
			}//���ʹ���
			if (y + i <= w && map[x][y + i] != 0 &&visit[x][y+i]==0) {
				visit[x][y + i] = 1;
				q.push(aa(x, y + i, map[x][y + i]));
			}//�����ʹ���
			if (x + i <= h && map[x + i][y] != 0&&visit[x+i][y]==0) {
				visit[x + i][y] = 1;
				q.push(aa(x + i, y, map[x + i][y]));
			}
		} 
	}
}
void downdfs(int x, int y,int num) {
	for (int i = x+1; i <= h; i++) {
		if (map[i][y] == 0) { // �Ʒ� ĭ�� 0�̸� 
			map[i][y] = num;
			map[i-1][y] = 0;
		}
		else {
			break;
		}
	}
}
void down() {
	for (int i = 1; i <= w; i++) {
		for (int j = h; j >= 1; j--) {
			if (map[j][i] != 0) {
				downdfs(j, i,map[j][i]);
			}
		}
	}
}
void calc() {
	for (int i = 1; i <= n; i++) {
		int dir = route[i];
		broke(dir); //������ �������� 0���� �� �ٲٰ���
		down(); //���� �ٿ� ��Ű��
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				visit[i][j] = 0;
			}
		}
	}

	return;
}
void dfs(int index, int num) {
	//num ���� : 1~w��ŭ 
	if (num > w+1) {
		return;
	}
	if (index == n+1) {
		calc();
		int tempans = 0;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (map[i][j] != 0) {
					tempans++;
				}
				map[i][j] = clonemap[i][j];
			}//printf("\n");
		} // ���� ���� ���� 
		if (realans > tempans) {
			realans = tempans;
		}
		return;
	}
	for (int i = 1; i <= w; i++) {
		route[index] = i;
		dfs(index + 1, i + 1);
	}
	
}
void clear() {
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			map[i][j] = 0;
			clonemap[i][j] = 0;
		}
	}
	realans = 12 * 15;
	for (int i = 1; i <= n; i++) {
		route[i] = 0;
	}
}
int main(void) {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d %d %d", &n, &w, &h);
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				scanf(" %d", &map[i][j]);
				clonemap[i][j] = map[i][j];
			}
		}//map �׸��� 
		dfs(1,1);
		
		printf("#%d %d\n", t, realans);
		clear();
		
	}
	return 0;
}