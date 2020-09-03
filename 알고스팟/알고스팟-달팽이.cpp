#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;
int n,m;
double cache[1001][2001]; //[day][오른높이]

double climb(int done_day, int height) {
	if (done_day == m) {
		if (height >= n) {
			return (double)1; 
		}
		return (double)0;
	}
	double& ret = cache[done_day][height];

	if (ret != -1) {
		return ret;
	}
	ret = 0.25*climb(done_day + 1, height + 1) + 0.75*climb(done_day + 1, height + 2);

	return ret;
}

int main(void) {
	int C;
	scanf("%d", &C);
	for (int t = 1; t <= C; t++) {
		scanf("%d %d", &n,&m);
		
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= 2 * m; j++) {
				cache[i][j]=-1;
			}
		}
		printf("%.9f\n", climb(0, 0));

	}

	return 0;
}