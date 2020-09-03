#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector <int> v[10001];
vector< int > ans;
int deep[10001]; //�� ��庰 �ִ� ���� ���� �迭 
int visit[10001];
int check = 0;
int cnt;
void dfs(int start) {//start�������� ����
//	
	visit[start] = 1;
	
	for (int i = 0; i < v[start].size(); i++) {
		int next = v[start][i];
		if (visit[next] == 0) {
			cnt++;
			dfs(next);
		}
	}
	
}
int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		v[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
			cnt = 1;
			for (int i = 1; i <= n; i++) {
				visit[i] = 0;
			}
			dfs(i);
			deep[i] = cnt;
		
	}
	int maxdeep=0;
	for (int i = 1; i <= n; i++) {
		if (deep[i] >= maxdeep){
			maxdeep = deep[i];
		}
	} //max����ã�°�
	for (int i = 1; i <= n; i++) {
		if (maxdeep == deep[i]) {
			ans.push_back(i);
		}
	}//max���̶� ������ ans�� �ֱ� 
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i]);
	}  //�װ� ��� 
	
	return 0;
}