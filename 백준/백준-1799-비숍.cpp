#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int n;
int map[11][11]; //1은 둘수있는곳, 0은 둘수없는 곳
vector <pair<int, int> > v1,v2;
int ans1, ans2;
bool check(int x, int y) {
	int i = x;
	int j = y;
	while (i >= 1 && i <= n && j >= 1 && j <= n) {
		i -= 1;
		j += 1;
		if (map[i][j] == 2) {
			return false;
		}
	} //오른쪽 위 보기
	i = x;
	j = y;
	while (i >= 1 && i <= n && j >= 1 && j <= n) {
		i += 1;
		j -= 1;
		if (map[i][j] == 2) {
			return false;
		}
	} //오른쪽 아래 보기
	i = x;
	j = y;
	while (i >= 1 && i <= n && j >= 1 && j <= n) {
		i += 1;
		j -= 1;
		if (map[i][j] == 2) {
			return false;
		}
	} //왼쪽 아래 보기
	i = x;
	j = y;
	while (i >= 1 && i <= n && j >= 1 && j <= n) {
		i -= 1;
		j -= 1;
		if (map[i][j] == 2) {
			return false;
		}
	} //왼쪽 위 보기
	return true;
}
void dfs1(int cnt,int index) {
	if (index >= v1.size()) {
		if (ans1 < cnt) {
			ans1 = cnt;
		}
		return;
	}
	int x = v1[index].first;
	int y = v1[index].second;
	if (check(x, y)) {
		map[x][y] = 2;
		dfs1(cnt + 1, index + 1);
		map[x][y] = 1;
	}
	dfs1(cnt, index + 1);

}
void dfs2(int cnt, int index) {
	if (index >= v2.size()) {
		if (ans2 < cnt) {
			ans2 = cnt;
		}
		return;
	}
	int x = v2[index].first;
	int y = v2[index].second;
	if (check(x, y)) {
		map[x][y] = 2;
		dfs2(cnt + 1, index + 1);
		map[x][y] = 1;
	}
	dfs2(cnt, index + 1);

}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %d", &map[i][j]);
			if ((i % 2 == 1 && j % 2 == 1) || (i % 2 == 0 && j % 2 == 0)) {
				if (map[i][j] == 1) {
					v1.push_back(make_pair(i, j));
				}
			}
			else if ((i % 2 == 1 && j % 2 == 0) || (i % 2 == 0 || j % 2 == 1)) {
				if (map[i][j] == 1) {
					v2.push_back(make_pair(i, j));
				}
			}
		}
	} //map그리고 v1,v2에 넣엇당
	if (v1.size() != 0) {
		dfs1(0, 0);
	}
	if (v2.size() != 0) {
		dfs2( 0, 0);
	}
	printf("%d", ans1 + ans2);
	return 0;
}