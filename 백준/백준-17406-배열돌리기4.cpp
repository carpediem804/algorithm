#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;
int n, m,k;
int map[51][51];
int tempmap[51][51]; //회전할때 쓸라구 
int backup[51][51];
int rotate_info[7][3];
int order[7]; //순서 저장 
int visit[7];
int ans = 987654321;

void rotate(int _startx, int _starty, int _endx, int _endy, int s) {
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			tempmap[i][j] = map[i][j];
		}
	}
	for(int sum=0;sum<=s-1;sum++){
		int startx = _startx + sum;
		int starty = _starty + sum;
		int endx = _endx - sum;
		int endy = _endy - sum;
		
		for (int i = starty + 1; i <= endy; i++) {
			int temp = tempmap[startx][i - 1]; //tempmap에 넣어야하는 값이 저장되어잇으므로 
			map[startx][i] = temp;

		} // -> 방향 끝 
		for (int i = startx + 1; i <= endx; i++) {
			int temp = tempmap[i - 1][endy];
			map[i][endy] = temp;
		} //아래방향 

		for (int i = endy - 1; i >= starty; i--) {
			int temp = tempmap[endx][i + 1];
			//tempmap[endx][i] = map[endx][i];
			map[endx][i] = temp;
		}//왼쪽 방향 
		for (int i = endx - 1; i >= startx; i--) {
			int temp = tempmap[i + 1][starty];
			//tempmap[i][starty] = map[i][starty];
			map[i][starty] = temp;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
	//		printf(" %d", map[i][j]);
		}//printf("\n");
	}
}
int calc() {
	for (int i = 1; i <= k; i++) {
		int num = order[i];
		int startx = rotate_info[num][0] - rotate_info[num][2];
		int starty = rotate_info[num][1] - rotate_info[num][2];
		int endx = rotate_info[num][0] + rotate_info[num][2];
		int endy = rotate_info[num][1] + rotate_info[num][2];
		int s = rotate_info[num][2];
		rotate(startx, starty, endx, endy,s);

	}
	int returnnum = 987654321;
	for (int i = 1; i <= n; i++) {
		int rowsum = 0;
		for (int j = 1; j <= m; j++) {
			rowsum += map[i][j];
		}
		if (returnnum > rowsum) {
			returnnum = rowsum;
		}
	}
	return returnnum;
}
void clear() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			map[i][j] = backup[i][j];
		}
	}
}
void dfs(int index) {
	if (index == k +1) {
		
		ans = min(ans,calc());
		clear();
		return;
	}
	for (int i = 1; i <= k; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			order[index] = i;
			dfs(index + 1);
			visit[i] = 0;
		}
	}
	
	
}
int main(void) {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %d", &map[i][j]);
			backup[i][j] = map[i][j];
			tempmap[i][j] = map[i][j];
		}
	}
	for (int i = 1; i <= k; i++) {
		int r, c, s;
		scanf("%d %d %d", &r, &c, &s);
		rotate_info[i][0] = r;
		rotate_info[i][1] = c;
		rotate_info[i][2] = s;
	}
	dfs(1);
	printf("%d\n", ans);
}