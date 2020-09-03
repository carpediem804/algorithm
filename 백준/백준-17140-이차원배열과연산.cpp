#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int map[101][101];
int r, c, k;
int rmax, cmax;//r==x 값 c=y값 
int ans = -1;
int temparray[101];
struct aa {
	int num;
	int cnt;
	aa(int n1, int n2) :num(n1), cnt(n2) {

	}
};
struct cmp {
	bool operator ()(aa a1, aa a2) {

		if (a1.cnt == a2.cnt) {
			return a1.num > a2.num;
		}
		else {
			return a1.cnt > a2.cnt;
		}
	}
};
vector <int >v;
priority_queue <aa, vector<aa>, cmp> q;
void rcalc() {
	for (int x = 1; x <= rmax; x++) {

		for (int y = 1; y <= cmax; y++) {
			temparray[map[x][y]] += 1;
		}//한줄끝나면

		for (int i = 1; i <= 100; i++) {
			if (temparray[i] != 0) {
				//	printf("array에 들어가는 값 %d %d\n", i, temparray[i]);
				q.push(aa(i, temparray[i]));
			}
			temparray[i] = 0;
		} // 큐에 넣고 
		int temp = 1;
		v.push_back(q.size() * 2);
		while (q.size() != 0) {
			int num = q.top().num;
			int cnt = q.top().cnt;
			//	printf("num : %d cnt : %d\n", num, cnt);
			q.pop();
			map[x][temp] = num;
			temp++;
			map[x][temp] = cnt;
			temp++;
		}//배열에 다시넣고 
		for (int i = temp; i <= 100; i++) {
			map[x][i] = 0;
		}

	}
	sort(v.begin(), v.end(), greater<int>());
	cmax = v.front();
	v.clear();
}
void ccalc() {

	for (int y = 1; y <= cmax; y++) {
		//	printf("y : %d\n", y);
		for (int x = 1; x <= rmax; x++) {
			temparray[map[x][y]] += 1;

		}//한줄끝나면 
		for (int i = 1; i <= 100; i++) {
			if (temparray[i] != 0) {
				q.push(aa(i, temparray[i]));
			}
			temparray[i] = 0;
		} // 큐에 넣고 
		int temp = 1;
		v.push_back(q.size() * 2);
		while (q.size() != 0) {

			int num = q.top().num;
			int cnt = q.top().cnt;
			//	printf("num : %d cnt : %d\n", num, cnt);
			q.pop();
			map[temp][y] = num;
			temp++;
			map[temp][y] = cnt;
			temp++;
		}//배열에 다시넣고
	//	printf("temp : %d\n", temp);
		for (int i = temp; i <= 100; i++) {
			map[i][y] = 0;
		}
	}
	sort(v.begin(), v.end(), greater<int>());
	rmax = v.front();
	v.clear();
}
int main(void) {
	scanf("%d %d %d ", &r, &c, &k);
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			scanf(" %d", &map[i][j]);
		}
	}//map 배열에 넣엇다 
	int t = 0;
	rmax = 3;
	cmax = 3;
	while (t <= 100) {

		if (map[r][c] == k) {
			ans = t;
			break;
		}
		t++;
		if (rmax >= cmax) {
			//	printf("rlcac전 %d %d\n", rmax, cmax);
			rcalc();
		}
		else {
			//	printf("cclac전 %d %d\n", rmax, cmax);
			ccalc();
		}
	}
	printf("%d", ans);
	return 0;
}