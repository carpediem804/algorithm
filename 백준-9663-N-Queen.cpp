#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int n;
int ans;
int pick[15];
bool check(int x, int y) {
	for (int i = 1; i < x; i++) { //여태까진 둔 애들좌표 봣을 때 
		if (pick[i] == y || abs(i - x) == abs(pick[i] - y)) { //y좌표가 같거나 대각선일때
			return false;
		}
	}
	return true;
	
}
void dfs(int index) {
	if (index == n+1) {
		//for (int i = 1; i <= n; i++) {
	//		printf("%d ", pick[i]);
	//	}printf("\n");
		ans++;
		return; 
	}
	for (int i = 1; i <= n; i++) {
		if (check(index,i)) { //index =x i = y에 놓을 수 있으면
			pick[index] = i;
			dfs(index + 1);

		}
	}
}
int main(void) {
	scanf("%d", &n);

	dfs(1);
	printf("%d\n", ans);
	
	return 0;
}