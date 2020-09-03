#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int cost[10001];
int cache[10001][2]; //0�� �ȸԾ����� 1�� �Ծ�����
int calc(int index,int eat) {
	
	int& ret = cache[index][eat];

	if (ret != -1) {
		return ret;
	}
	ret = 0;
	
	if (eat == 0) { //�ȸԾ��� �� 
		ret = max(calc(index-1,0),calc(index-1,1));
	}
	else {//�Ծ��� �� 
		ret = max(calc(index - 1, 0) + cost[index], calc(index - 2, 0) + cost[index - 1] + cost[index]);
	}

	return ret;
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &cost[i]);
	}
	memset(cache, -1, sizeof(cache));
	cache[1][0] = 0;
	cache[1][1] = cost[1];
	cache[2][0] = cache[1][1];
	cache[2][1] = cache[1][1] + cost[2];
	printf("%d\n", max(calc(n,0),calc(n,1)));

	return 0;
}