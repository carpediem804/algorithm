#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;
int map[16][13];
int clonemap[16][13];
int visit[16][13];
int route[5]; // 구슬이 어디에 떨어질지 정하기 
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
void broke(int dir) { //dir == 구슬이 떨어지는 y값
	for (int i = 1; i <= h; i++) {
		if (map[i][dir] != 0) {
			//printf("x : %d y : %d num : %d\n", i, dir, map[i][dir]);
			q.push(aa(i, dir, map[i][dir]));
			break;
		}//처음으로 0이 아닌 것을 발견했다! ->queue에 넣엇당
	}
	while (q.size() != 0) {
		int x = q.front().x;
		int y = q.front().y;
		int num = q.front().num;
		q.pop();
		map[x][y] = 0;
		//왼쪽방향보기
		for (int i = 1; i <= num-1; i++) {
			if (y-i>=1 && map[x][y - i] != 0 &&visit[x][y-i]==0) {
				visit[x][y - i] = 1;
				q.push(aa(x, y - i, map[x][y - i]));
			} //왼쪽방향
			if (x-i>=1 && map[x - i][y] != 0 &&visit[x-i][y]==0) {
				visit[x - i][y] = 1;
				q.push(aa(x - i, y, map[x - i][y]));
			}//위쪽방향
			if (y + i <= w && map[x][y + i] != 0 &&visit[x][y+i]==0) {
				visit[x][y + i] = 1;
				q.push(aa(x, y + i, map[x][y + i]));
			}//오른쪽방향
			if (x + i <= h && map[x + i][y] != 0&&visit[x+i][y]==0) {
				visit[x + i][y] = 1;
				q.push(aa(x + i, y, map[x + i][y]));
			}
		} 
	}
}
void downdfs(int x, int y,int num) {
	for (int i = x+1; i <= h; i++) {
		if (map[i][y] == 0) { // 아래 칸이 0이면 
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
		broke(dir); //구슬이 떨어져서 0으로 다 바꾸고난뒤
		down(); //이제 다운 시키장
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				visit[i][j] = 0;
			}
		}
	}

	return;
}
void dfs(int index, int num) {
	//num 범위 : 1~w만큼 
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
		} // 벽돌 개수 세기 
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
		}//map 그리기 
		dfs(1,1);
		
		printf("#%d %d\n", t, realans);
		clear();
		
	}
	return 0;
}