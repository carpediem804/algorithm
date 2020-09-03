#include <stdio.h>
#include <queue>
using namespace std;
int pan[6][6][6];
int tempmap[6][6][6];
int visit[6][6][6];
int order[6];
int order_visit[6];
int rotate_array[6]; //index = 층수 저장되는값이 회전 방향
struct aa {
	int height, x, y;
	aa(int n1, int n2, int n3) :x(n1), y(n2), height(n3) {

	}
};
queue <aa> q;
int ans=987654321;
int dir[6][3] = { {1,0,0},{0,1,0},{0,0,1},{-1,-0,0},{0,-1,0},{0,0,-1} };
void gogo(int s_h, int s_x, int s_y, int e_h, int e_x, int e_y) {
	while (q.size() != 0) {
		q.pop();
	}
	q.push(aa(s_x, s_y, s_h));
	int time = 0;
	while (q.size() != 0) {
		int qsize = q.size();
		for (int k = 0; k < qsize; k++) {
			int x = q.front().x;
			int y = q.front().y;
			int z = q.front().height;
			q.pop();
			if (x == e_x && y == e_y && z == e_h) {
				if (ans > time) {
					ans = time;
					return;
				}
			}
			for (int i = 0; i < 6; i++) {
				int dx = x + dir[i][0];
				int dy = y + dir[i][1];
				int dz = z + dir[i][2];
				if (dx >= 1 && dx <= 5 && dy >= 1 && dy <= 5 && dz >= 1 && dz <= 5) {
					if (visit[dz][dx][dy] == 0 && tempmap[dz][dx][dy]==1) {
						visit[dz][dx][dy] = 1;
						q.push(aa(dx, dy, dz));
					}
				}
			}
		}
		time++;
		
	}
}
void push_map(int hight,int row,int rot){ 
	if (rot == 1) {
		for (int x = 1; x <= 5; x++) {
			for (int y = 1; y <= 5; y++) {
				tempmap[hight][x][y] = pan[row][x][y];
			}
		}
	}//그대로
	else if (rot == 2) {
		for (int x = 1; x <= 5; x++) {
			for (int y = 1; y <= 5; y++) {
				tempmap[hight][x][y] = pan[row][y][6-x];
			}
		}
	}
	else if (rot == 3) {
		for (int x = 1; x <= 5; x++) {
			for (int y = 1; y <= 5; y++) {
				tempmap[hight][x][y] = pan[row][6-x][6-y]; 
			}
		}
	}
	else if(rot ==4){
		for (int x = 1; x <= 5; x++) {
			for (int y = 1; y <= 5; y++) {
				tempmap[hight][x][y] = pan[row][6-y][x];
			}
		}
	}
}
void calc() {

	for (int i = 1; i <= 5; i++) {
		push_map(i,order[i], rotate_array[i]);
	}//선택한 층과 방향으로 tempmap에 넣는다 
	
	for (int h = 1; h <= 5; h++) {
		for (int x = 1; x <= 5; x++) {
			for (int y = 1; y <= 5; y++) {
				visit[x][y][h] = 0;
			}
		}
	}
	if (tempmap[1][1][1] == 1) {
		gogo(1, 1, 1, 5, 5, 5);
	}
	
	if (tempmap[1][1][5] == 1) { gogo(1, 1, 5, 5, 5, 1); }
	if (tempmap[1][5][5] == 1) { gogo(1, 5, 5, 5, 1, 1); }
	if (tempmap[1][5][1] == 1) { gogo(1, 5, 1, 5, 1, 5); }
	
}
void dfs2(int index) {
	if (ans == 12) {
		return;
	}
	if (index == 6) {
		calc();
		return;
	}
	for (int i = 1; i <= 4; i++) {
		rotate_array[index] = i;
		dfs2(index + 1);
	}
}
void dfs(int index) {
	if (ans == 12) {
		return;
	}
	if (index == 6) {	
		dfs2(1);
		return;
	}//순서 다 정했다 
	
	for (int i = 1; i <= 5; i++) {
		if (order_visit[i] == 0) {
			order[index] = i;
			order_visit[i] = 1;
			dfs(index+1);
			order_visit[i] = 0;
		}
	}
}
int main(void) {
	for (int i = 1; i <= 5; i++) {
		for (int x = 1; x <= 5; x++) {
			for (int y = 1; y <= 5; y++) {
				scanf(" %d", &pan[i][x][y]);
			}
		}
	}
	//판 순서 정하기
	
	dfs(1);
	if (ans == 987654321) {
		ans = -1;
	}
	printf("%d\n", ans);
	return 0;
}