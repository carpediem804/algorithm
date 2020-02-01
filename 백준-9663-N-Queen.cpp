#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int n;
int ans;
int pick[15];
bool check(int x, int y) {
	for (int i = 1; i < x; i++) { //���±��� �� �ֵ���ǥ �f�� �� 
		if (pick[i] == y || abs(i - x) == abs(pick[i] - y)) { //y��ǥ�� ���ų� �밢���϶�
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
		if (check(index,i)) { //index =x i = y�� ���� �� ������
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