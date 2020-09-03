#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
int n, m;
int visit[100];
vector <int > v1[100], v2[100]; //v1 == 위에 개수 v2=아래의 개수
int ans[100];
int cnt2; //개수세는 변수 
void dfs(int start, int next) {
	if (cnt2 >= (n + 1) / 2) {
		//printf("start : %d next : %d cnt : %d\n", start, next, cnt2);
		ans[start]= 1;
		return;
	}//dfs끝나는 조건 
	for (int i = 0; i < v1[next].size(); i++) {
		if (visit[v1[next][i]] == 0) {
			cnt2+=1;
			visit[v1[next][i]] = 1;
			dfs(start, v1[next][i]);
		}
	}
}

void dfs2(int start, int next) {//위에거랑 같음
	if (cnt2 >= (n + 1) / 2) {
		ans[start]= 1;
		return;
	}
	for (int i = 0; i < v2[next].size(); i++) {
		if (visit[v2[next][i]] == 0) {
			visit[v2[next][i]] = 1;
			cnt2+=1;
			dfs2(start, v2[next][i]);
		}
	}
}
int main(void) {
	scanf(" %d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf(" %d %d", &x, &y);
		v1[x].push_back(y);
		v2[y].push_back(x);
	}//벡터에 다 넣엇다 

	for (int i = 1; i <= n; i++) {
		cnt2 = 0;
		dfs(i,i); //나보다 작은 애들 갯수 세는 것 
		for (int j = 1; j <= n; j++) {
			visit[j] = 0;
		}//방문 배열 초기화 
		cnt2 = 0;
		dfs2(i, i);//나보다 큰 애들 갯수 세는 것
		for (int j = 1; j <= n; j++) {
			visit[j] = 0;
		}//방문 배열 초기화 
	 //	printf("----------------\n");
	}
	int realans = 0;
	for (int i = 1; i <= n; i++) {
		if (ans[i] == 1) {
			realans++;
		}
	}//정답개수세는것
	printf("%d", realans);
	return 0;
}