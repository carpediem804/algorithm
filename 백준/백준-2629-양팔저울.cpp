#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int visit[31]; //추 개수가 30개임으로 
int chu[31]; //추무게 저장
int can[31][40001];  //추의 개수 / 추의개수일때 가능 한 추 무게 
int ans[40001];
int chunum;
void dfs(int start,int weight) {//chu[start]에서의 무게 값
	
	ans[weight] = 1;
	if (start >= chunum) {
		return;
	}
	if (can[start][weight] == 1) {
		return;
	}
	can[start][weight] = 1;
	
	dfs(start + 1, chu[start] + weight);
	dfs(start + 1, weight);
	dfs(start + 1, abs(weight - chu[start]));

}
int main(void) {
	
	scanf("%d", &chunum);
	for (int i = 0; i < chunum; i++) {
		int temp;
		scanf("%d", &temp);
		chu[i] = temp; //추무게 저장
	}
	dfs(0,0);
	int q;
	scanf("%d",&q);
	for (int i = 0; i < q; i++) {
		int qnum;
		scanf("%d", &qnum);
		if (ans[qnum] == 1) {
			printf("Y ");
		}
		else {
			printf("N ");
		}
	}


	return 0;
}