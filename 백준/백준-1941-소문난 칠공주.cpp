#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
queue<pair<int, int>> q;
int map[6][6]; //S,Y저장
int map2[6][6]; //선택한 사람이 연결되어 있는지 확인하기 위해 
int selected[26]; // 25중에 7명 선택 저장 
int ans; //답
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
bool check1() { 
	int twonum = 0;
	for (int i = 0; i <= 24; i++) {
		if (selected[i] == 1) {
			int x = i / 5 + 1;
			int y = i % 5 + 1;;
			if (map[x][y] == 2) {
				twonum++;
			}
		}
	}
	if (twonum < 4) {
		return false;
	}
	return true;
}//2의 개수 찾는것
bool check2() {
	int pushnum = 0;
	for (int i = 0; i <= 24; i++) {
		if (selected[i] == 1) {
			int x = i / 5 + 1;
			int y = i % 5 + 1;
			pushnum++;
			if (pushnum == 1) {
				q.push(make_pair(x, y));
			}
			map2[x][y] = 1;
		}
	} // MAP2를 그리고 한 점을 Q에 넣는다 
	while (q.size() != 0) {
		int x = q.front().first;
		int y = q.front().second;
		map2[x][y] = 0;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int dx = x + dir[i][0];
			int dy = y + dir[i][1];
			if (dx >= 1 && dx <= 5 && dy >= 1 && dy <= 5) {
				if (map2[dx][dy] == 1) {
					map2[dx][dy] = 0;
					q.push(make_pair(dx, dy));
				}
			}
		}
	} //BFS로 방문 가능한점 0으로 다 바꿈
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			if (map2[i][j] == 1) {
				return false;
			}
		}
	}
	return true;
}//다 연결되어 있는지 확인하는거
void clear() {
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			map2[i][j] = 0;
		}
	}
}
void dfs(int cnt,int index) {
	if (cnt == 7) {
		clear(); //MAP2함수 초기화 
		if (check1()) {
			//printf("1pass\n");
			if (check2()) {
			//	printf("2pass\n");
				ans++;
				return;
			}
		}
		else {
			return;
		}
	}
	if (index > 24) {
		return;
	}
	selected[index] = 1;
	dfs(cnt + 1, index + 1);
	selected[index] = 0;
	dfs(cnt, index + 1);
}
int main(void) {
	char c;
	for (int x = 1; x <= 5; x++) {
		for (int y = 1; y <= 5; y++) {
			scanf(" %1c", &c);
			if (c == 'Y') {
				map[x][y] = 1;
			}
			else {
				map[x][y] = 2;
			}
		}
	}
	

	dfs(0,0);
	
	printf("%d\n", ans);
	return 0;
}