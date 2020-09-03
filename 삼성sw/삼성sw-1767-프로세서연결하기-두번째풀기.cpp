#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int map[13][13];
int n;
vector<pair<int, int>> core;
int ans[13] ;
int max_core = 0;
bool can_go(int x, int y, int dir) {
	if (dir == 0) { //위 
		int dx = x;
		int dy = y;
		while (dx >= 1) {
			dx -= 1;
			if (map[dx][dy] == 1) {
				return false;
			}
		}
	}
	else if (dir == 1) {//아래
		int dx = x;
		int dy = y;
		while (dx <= n) {
			dx += 1;
			if (map[dx][dy] == 1) {
				return false;
			}
		}
	}
	else if (dir == 2) {//오른쪽
		int dx = x;
		int dy = y;
		while (dy <= n) {
			dy += 1;
			if (map[dx][dy] == 1) {
				return false;
			}
		}
	}
	else if (dir == 3) {//왼쪽
		int dx = x;
		int dy = y;
		while (dy >=1 ) {
			dy -= 1;
			if (map[dx][dy] == 1) {
				return false;
			}
		}
	}
	return true;
}
int draw(int x, int y, int dir) {

	int cnt = 0;
	if (dir == 0) { //위 
		int dx = x;
		int dy = y;
		while (dx > 1) {
			dx -= 1;
			map[dx][dy] = 1;
			cnt++;
		}
	}
	else if (dir == 1) {//아래
		int dx = x;
		int dy = y;
		while (dx < n) {
			dx += 1;
			map[dx][dy] = 1;
			cnt++;
		}
	}
	else if (dir == 2) {//오른쪽
		int dx = x;
		int dy = y;
		while (dy < n) {
			dy += 1;
			map[dx][dy] = 1;
			cnt++;
		}
	}
	else if (dir == 3) {//왼쪽
		int dx = x;
		int dy = y;
		while (dy > 1) {
			dy -= 1;
			map[dx][dy] = 1;
			cnt++;
		}
	}
	return cnt;
}
void de_draw(int x, int y, int dir) {
	if (x == 1 || y == 1 || x == n || y == n) {
		return ;
	}
	if (dir == 0) { //위 
		int dx = x;
		int dy = y;
		while (dx > 1) {
			dx -= 1;
			map[dx][dy] = 0;
			
		}
	}
	else if (dir == 1) {//아래
		int dx = x;
		int dy = y;
		while (dx < n) {
			dx += 1;
			map[dx][dy] = 0;
			
		}
	}
	else if (dir == 2) {//오른쪽
		int dx = x;
		int dy = y;
		while (dy < n) {
			dy += 1;
			map[dx][dy] = 0;
			
		}
	}
	else if (dir == 3) {//왼쪽
		int dx = x;
		int dy = y;
		while (dy > 1) {
			dy -= 1;
			map[dx][dy] = 0;
		}
	}
}
void dfs(int index, int connect_core_num, int rope_num) {
	if (index == core.size()) { //모든 코어 다 방향 정했을때
		//printf("index : %d connect_core_num : %d rope_num : %d\n", index, connect_core_num, rope_num);
		max_core = max(max_core, connect_core_num);
		ans[connect_core_num] = min(ans[connect_core_num], rope_num);
		//printf("maxcore : %d ans : %d\n", max_core, ans[max_core]);
		return;
	}
	int x = core[index].first;
	int y = core[index].second;
	
	for (int i = 0; i < 4; i++) { //한점의 상하좌우 봐야댐 
		if (x == 1 || x == n || y == 1 || y == n) { //일단 한점이 끝점이면 걍 통과 ~ 
			dfs(index + 1, connect_core_num + 1, rope_num);
			return;
		}
		if (can_go(x, y, i)) { //방향 별로 쭉 이동했을 때 전선 연결할수 있따면
			int plus_rope = draw(x, y, i); //그리고 rope길이 추가해서 다음점을 본다 
			dfs(index + 1, connect_core_num + 1, rope_num + plus_rope);
			de_draw(x, y, i); // 다시 원상 복구 ~ 
		}
	}
	dfs(index + 1, connect_core_num, rope_num); //그냥 통과해서 가는 것 
}
int main(void) {
	int T;
	scanf("%d", &T);
	for (int t = 1; t<= T; t++) {
		scanf("%d", &n);
		for (int i = 1; i <= 12; i++) {
			ans[i] = 987654321;
		}
		for (int x = 1; x <= n; x++) {
			for (int y = 1; y <= n; y++) {
				int temp;
				scanf("%d", &temp);
				map[x][y] = temp;
				if (temp == 1) {
					core.push_back(make_pair(x, y));
				}
			}
		}
		int core_num = core.size();
		dfs(0, 0, 0);
		//printf("max_core_num : %d\n", max_core);
		//for (int i = 1; i <= 7; i++) {
		//	printf(" %d ", ans[i]);
	//	}
		printf("#%d %d\n",t, ans[max_core]);
		core.clear();
		max_core = 0;
	}
	return 0;
}