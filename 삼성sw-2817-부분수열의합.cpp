#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> v;
int n,k;
int ans;
void dfs(int index, int sum,int picknum, int totalpick) {
	
	if (sum > k) {
		return;
	}//sort������ sum �Ѿ�� ������ �ʴ´� 
	if (picknum == totalpick) { //���ÿϷ� ���� �� 
		if (sum == k) {
			ans++;
		}
		return;
	}
	if (index >= v.size()) {
		return;
	}//index���� �����ִ� �� 
	dfs(index + 1, sum + v[index], picknum + 1, totalpick);//�����Ѱ��
	dfs(index + 1, sum, picknum, totalpick);//���þ��� ���
}
int main(void) {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d %d", &n, &k);
		ans = 0;
		v.clear();
		for (int i = 1; i <= n; i++) {
			int temp;
			scanf(" %d", &temp);
			v.push_back(temp);
		}
		sort(v.begin(), v.end());
		for (int i = 1; i <= n; i++) {
			dfs(0,0,0,i);
		}
		printf("#%d %d\n", t, ans);
	}
	return 0;
}