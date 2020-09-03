#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int ans;
int M, A;
int a_route[101];
int b_route[101];
int xdir[5] = { 0,-1,0,1,0 };
int ydir[5] = { 0,0,1,0,-1 };
struct aa {
	int x, y;
	int coverage, performance;
};
struct bfstemp {
	int x, y, cover;
	bfstemp(int n1, int n2, int n3) :x(n1), y(n2), cover(n3) {

	}
};
struct vecaa {
	int performance, index;
	vecaa(int n1, int n2) : performance(n1), index(n2) {

	}
};
bool cmp(const vecaa& a, const vecaa& b){
	return a.performance > b.performance;
};
queue <bfstemp> q;
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
aa bc[9];
int map[9][11][11];
int visit[11][11];
vector <vecaa > va, vb;
void dfs(int _num) {
	while (q.size() != 0) {
		int x = q.front().x;
		int y = q.front().y;
		int c = q.front().cover;
		q.pop();
		visit[x][y] = 1;
		map[_num][x][y] = 1;
		//printf("x : %d y : %d c : %d\n", x, y, c);
		for (int i = 0; i < 4; i++) {
			int dx = x + dir[i][0];
			int dy = y + dir[i][1];
			if (dx >= 1 && dx <= 10 && dy >= 1 && dy <= 10) {
				if (visit[dx][dy] == 0 && c>0) {
					q.push(bfstemp(dx, dy, c - 1));
				}
			}
		}
	}
}
void visitclear() {
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			visit[i][j] = 0;
		}
	}
}
void clear() {
	for (int i = 1; i <= A; i++) {
	//	printf("i 번째 : %d power : %d\n", i,bc[i].performance);
		for (int x = 1; x <= 10; x++) {
			for (int y = 1; y <= 10; y++) {
		//		printf(" %d", map[i][x][y]);
				map[i][x][y] = 0;
			}//printf("\n");
		}
	}
	for (int x = 1; x <= 10; x++) {
		for (int y = 1; y <= 10; y++) {
			visit[x][y] = 0;
		}
	}
	for (int i = 1; i <= M; i++) {
		a_route[i] = 0;
		b_route[i] = 0;
	}
	ans = 0;
}
int main(void) {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d %d", &M, &A);
		for (int i = 1; i <= M; i++) {
			scanf(" %d", &a_route[i]);
		}
		for (int i = 1; i <= M; i++) {
			scanf(" %d", &b_route[i]);
		}
		for (int i = 1; i <= A; i++) {
			scanf("%d %d %d %d", &bc[i].y, &bc[i].x, &bc[i].coverage, &bc[i].performance);
		}//충전기 정보 저장 
		for (int i = 1; i <= A; i++) {
			q.push(bfstemp(bc[i].x, bc[i].y, bc[i].coverage));
			dfs(i);
			visitclear();
		} // i충전기의 충전 범위를 map[i][][] 에 저장함 
		
		int time = 1;
		int Ax = 1, Ay = 1;
		int Bx = 10, By = 10;
		while (time <= M+1) {
			for (int i = 1; i <= A; i++) {
				if (map[i][Ax][Ay] == 1) {
					va.push_back(vecaa( bc[i].performance,i));
				}
				if (map[i][Bx][By] == 1) {
					vb.push_back(vecaa(bc[i].performance,i));
				}
			} //A사용자와 B사용자가 연결할 수 있는 충전기 번호와 용량 저장
			if (va.size() != 0) {
				sort(va.begin(), va.end(),cmp);
			}
			if (vb.size() != 0) {
				sort(vb.begin(), vb.end(),cmp);
			}
			if ((va.size() == 0 && vb.size() == 0)) {
			
			}
			else{
				if (va.size() >= 2 && vb.size() >= 2) {
					if (va[0].index == vb[0].index) {
						int addnum = 0;
						addnum = max(va[0].performance + vb[1].performance, va[1].performance + vb[0].performance);
						ans += addnum;
					}//둘다 같은게 최대일때 
					else {
						ans += va[0].performance;
						ans += vb[0].performance;
					}//다를때 각자 더하기 
				}
				else if ( vb.size() == 1) {
					if (va.size() >= 2) {
						if (va[0].index == vb[0].index) {
							ans += vb[0].performance + va[1].performance;
						}
						else {
							ans += va[0].performance + vb[0].performance;
						}
					}
					else if (va.size() == 1) {
						if (va[0].index == vb[0].index) {
							ans += vb[0].performance;
						}
						else {
							ans += va[0].performance + vb[0].performance;
						}
					}
					else if(va.size()==0){ //va.size == 0인경우 
						ans += vb[0].performance;
					}
				}
				else if (va.size() == 1 ) {
					if (vb.size() >= 2) {
						if (va[0].index == vb[0].index) {
							ans += va[0].performance + vb[1].performance;
						}
						else {
							ans += va[0].performance + vb[0].performance;
						}
					}
					else if (vb.size() == 1) {
						//위에서 해서 그냥 통과 ~ 
					}
					else { //vb.size == 0인경우 
						ans += va[0].performance;
					}
				}
				else if (vb.size() == 0) {
					ans += va[0].performance;
				}
				else if (va.size() == 0) {
					ans += vb[0].performance;
				}
			} //둘다 범위안에 들때
			
			
			if (va.size() != 0) {
				va.clear();
			}
			if (vb.size() != 0) { 
				vb.clear(); 
			}
			Ax += xdir[a_route[time]];
			Ay += ydir[a_route[time]];
			Bx += xdir[b_route[time]];
			By += ydir[b_route[time]];
			time++;
		}
		printf("#%d %d\n", t, ans);
		clear();
	}
	return 0;
}