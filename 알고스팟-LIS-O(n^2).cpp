#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int map[501];
int cache[501];
int lis(int index) {

	int& ret = cache[index];
	if (ret != 0) {
		return ret;
	}//0�� �ƴϸ� �̹� ��� ������ �׳� return 

	ret = 1; //������ ��ó������ 1�̴� 
	for (int i = index + 1; i <= n; i++) {
		if (map[i] > map[index]) {//ū�ֵ��� ���� �� 
			ret = max(ret, lis(i) + 1);
			//�ڱ��� ���� ret�� �ڱ⺸��ū ���� ���� �� 
		}
	}
	return ret;
}
int main(void) {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &map[i]);
		}
		
		memset(cache, 0, sizeof(cache));
		int ans = 1;
		for (int i = 1; i <= n; i++) {
			ans = max(ans,lis(i));
		}
		printf("%d\n", ans);
		
	}
	
	return 0;
}