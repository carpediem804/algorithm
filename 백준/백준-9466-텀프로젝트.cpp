#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int map[100001];
int check[100001]; // 방문햇던점 다시 방문 안할려고 
int n;
int temp = 0;
vector <int> v;
void dfs(int start,int next) {
	
	if (check[next] == 1 || (next<start && check[next]==0)) {
		temp = 1;
		return;
	}//같은점을 두번 방문하면 안되고 그 전에 검사한 값이 안된다고 했는데 next로 들어올 경우 바로 return 
	if (start == next ) {
		check[next] = 1; //바로 올 경우 
		temp = 0;
		return;
	}//사이클이 된 경우 
	check[next] = 1; //다음점 체크했다고 하고 
	dfs(start, map[next]); //dfs 돌아간다~
	if (temp == 1) { // cycle이 아닐 경우 !! 
		check[next] = 0;//check를 1로 했던것들 다 0으로 바꾼다 
	}
}
int main(void) {
	int t;
	
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		int ans = 0;
		scanf("%d", &n);
		for (int j = 1; j <= n; j++) {
			scanf(" %d", &map[j]);
		}//map에 다 넣엇다
		for (int start = 1; start <= n; start++) {
			if (check[start] == 0) {
				temp = 0;
				dfs(start,map[start]); //사이클 체크하는 것 
			}
		}
		for (int x = 1; x <= n; x++) {
			if (check[x] == 0) {
				ans++; //안되는 점들은 0이니까 ans ++;
			}
			check[x] = 0; //check배열 초기화
			map[x] = 0; //map배열 초기화 
		}//결과값 계산
		printf("%d \n", ans);
	}
	
	return 0;
}