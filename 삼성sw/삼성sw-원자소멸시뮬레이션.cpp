#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N;
int map[4001][4001];
struct aa {
	int x, y, dir, k;
	aa(int n1, int n2, int n3, int n4) :x(n1), y(n2), dir(n3), k(n4) {

	}
};
vector <aa> v;
queue <pair<int, int>> q;
int calc() {
	int time = 0;
	int power = 0;
	while (time <= 4000) {
		time++;
		//printf("----------------------\n");
		for (int i = 0; i < v.size(); i++) {
			int x = v[i].x;
			int y = v[i].y;
			int dir = v[i].dir;
		//	printf("x : %d y : %d dir : %d\n", x, y, dir);
			if (x == -1 && y == -1) {
				continue;
			}
			map[x][y] = 0;
			if (dir == 0) { y += 1; }
			else if (dir == 1) { y -= 1; }
			else if (dir == 2) { x -= 1; }
			else if (dir == 3) { x += 1; }
			if (x >= 0 && x <= 4000 && y >= 0 && y <= 4000) {
				v[i].x = x;
				v[i].y = y;
				map[x][y] += 1;
				if (map[x][y] >= 2) {
					q.push(make_pair(x, y));
				}
			}
			else {
				v[i].x = -1;
				v[i].y = -1;
			}
		}//애들이동 1초동안 

		
		while (q.size() != 0) {
			int x = q.front().first;
			int y = q.front().second;
			map[x][y] = 0;
			q.pop();
			for (int i = 0; i < v.size(); i++) {
				if (v[i].x == x && v[i].y == y) {
					v[i].x = -1;
					v[i].y = -1;
					power += v[i].k;
				}
			}
		}
	}
	return power;
}
int main(void) {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d", &N);
		int x, y, dir, k;
		for (int i = 1; i <= N; i++) {
			scanf("%d %d %d %d", &x, &y, &dir, &k);
			x = (x + 1000) * 2;
			y = (y + 1000) * 2;
		//	printf("x : %d y:%d\n", x, y);
			map[x][y] = 1;
			v.push_back(aa(x, y, dir, k));
		}
		printf("#%d %d\n",t,calc());


		v.clear();


	}

	return 0;
}