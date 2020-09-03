#include<stdio.h>
//nt map[10000];
int N, M;
int tree[1000000];
int main(void) {
	int a;
	long long min = 0;
	long long mid = 1;
	long long max = 0;
	long long  take = 0;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf(" %d", &a);
		if (a > max) {
			max = a;
		}
		tree[i] = a;
	}
	//	printf("max : %d", max);
	while (min + 1 < max) {
		mid = (max + min) / 2;
		//	printf("min : %d max : %d mid : %d\n", min, max, mid);
		for (int i = 0; i < N; i++) {
			if (tree[i] > mid) {
				take += tree[i] - mid;
			}
		}
		//	printf("take : %d\n", take);
			//for¹®
		if (take >= M) {
			min = mid;
		}
		else {
			max = mid;
		}
		take = 0;
	}//while

	printf("%d", min);
	return 0;
}