#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
int map[13][13];
int visit[13];
vector <pair<int, int> > v;
int n;
int corenum;
int linenum;
int reallinenum=987654321;
bool check(int x, int y, int dir) { //x,y점에서 dir 방향으로 전선을 연결 할수 있나 없나 체크 하는 함수 만약 연결할수 있으면 그 길을 1로 채운다 ~ 
	if (dir == 1) { //위쪽 보는경우
		for (int i = x-1; i >= 1; i--) {
			if (map[i][y] == 1) {
				return false;
			}
		}
		for (int i = x-1; i >= 1; i--) {
			map[i][y] = 1;
		}
	}
	else if (dir == 2) { //아래쪽 보는경우
		for (int i = x+1; i <= n; i++) {
			if (map[i][y] == 1) {
				return false;
			}
		}
		for (int i = x+1; i <= n; i++) {
			map[i][y] = 1;
		}
	}
	else if (dir == 3) {//오른쪽
		for (int i = y+1; i <= n; i++) {
			if (map[x][i] == 1) {
				return false;
			}
		}
		for (int i = y+1; i <= n; i++) {
			map[x][i] = 1;
		}
	}
	else if (dir == 4) {//왼쪽
		for (int i = y-1; i >= 1; i--) {
			if (map[x][i] == 1) {
				return false;
			}
		}
		for (int i = y-1; i >= 1; i--) {
			map[x][i] = 1;
		}
	}

	return true;
}
void rollback(int x, int y, int dir) { //1로 map을 칠했던 것을 다시 0으로 바꾸는 함수 
	if (dir == 1) { //위쪽 보는경우
		for (int i = x-1; i >= 1; i--) {
			map[i][y] = 0;
		}
	}
	else if (dir == 2) { //아래쪽 보는경우
		for (int i = x+1; i <= n; i++) {
			map[i][y] = 0;
		}
	}
	else if (dir == 3) {//오른쪽
		for (int i = y+1; i <= n; i++) {
			map[x][i] = 0;
		}
	}
	else if (dir == 4) {//왼쪽
		for (int i = y-1; i >= 1; i--) {
			map[x][i] = 0;
		}
	}
}
void calc() {// 전선의 길이 세는 함수 ~ 
	linenum = 0;
	for (int i = 1; i <= n; i++) {
		if (visit[i] == 1) { //위쪽방향
			int x = v[i-1].first;
			linenum += (x - 1);
		} 
		else if (visit[i] == 2) { //아래쪽 방향
			linenum += (n - v[i-1].first);
		}
		else if (visit[i] == 3) { //오른쪽방향
			linenum += (n - v[i-1].second);
		}
		else if (visit[i] == 4) { //왼쪽방향
			linenum += (v[i-1].second - 1);
		}
	}
}
void dfs(int index, int dir) { //1인점 즉 core인 점의 전선 방향을 잡아주기

	if (index == v.size()+1) { //모든 core에게 전선 방향 or 선택인지 잡아주는 것 끝낫다면 계산한다
		int tempans = 0;
		for (int i = 1; i <= v.size(); i++) {
			if (visit[i] != 0) {
				tempans++;
			}
		}//전원이 연결된 core의 개수를 세고 
		if (corenum == tempans) { //그전에 세었던 core의 값과 똑같으면 
			calc(); //전선 길이 세어주고 
			if (reallinenum >= linenum) { //작은걸로 바꾼다	
				reallinenum = linenum;
			}
		}
		else if (corenum < tempans) { //그전에 셋던 core의 개수보다 지금 온 core의 개수가 더 많으면 corenu과 전선 길이 update
			corenum = tempans;
			calc();
			reallinenum = linenum;
		}
		return;
	}//계산 ~ 
	int x = v[index-1].first; //vector는 index-1~~ 
	int y = v[index-1].second;
	if ((x == 1) || (x == n) || (y == 1) || (y == n)) { //끝점이라면 visit[index]=-1로 넣고 다시 돈다~ 
		visit[index] = -1;
		dfs(index + 1, -1);
		
		return;
	}
	
	if (check(x, y, 1)) { //위쪽 방향으로 전선 연걸 할 수 있따면 
		visit[index] = 1; //visit에 1로표시하고 
		dfs(index + 1, 1); //dfs돈다~ 
		visit[index] = 0; //dfs끝난후에 visit배열에 0으로 초기화하고
		rollback(x, y, 1); //map에 1로 체크했던 값들 다시 rollback시킨다.
	}
	if (check(x, y, 2)) { //아래방향 ~ 
		visit[index] = 2;
		dfs(index + 1, 2);
		visit[index] = 0;
		rollback(x, y, 2);
	}
	if (check(x, y, 3)) { //오른쪽방향
		visit[index] = 3;
		dfs(index + 1, 3);
		visit[index] = 0;
		rollback(x, y, 3);
	}
	if (check(x, y, 4)) { //왼쪽방향 ~~ 
		visit[index] = 4;
		dfs(index + 1, 4);
		visit[index] = 0;
		rollback(x, y, 4);
	}
	//선택 안하는 경우도 체크해야한다 !!! 
	dfs(index + 1, 0);
}
void clear() { //testcase한벙 할때마다 map과 vector, vist배열, 전역변수들 초기화 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] = 0;
		}
	}
	v.clear();
	for (int i = 1; i <= n; i++) {
		visit[i] = 0;
	}
	corenum =0;
	linenum=0;
	reallinenum = 987654321;
}
int main(void) {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf(" %d", &n);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int temp;
				scanf(" %d", &temp);
				if (temp == 1) {
					v.push_back(make_pair(i, j));
				}
				map[i][j] = temp;
			}
		}//map에 다 넣엇당 
		dfs(1, 1);
		printf("#%d %d\n", t, reallinenum);
		clear();

	}
	return 0;
}