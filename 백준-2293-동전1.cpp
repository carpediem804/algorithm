#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
void main() {
	int n, i, j, k, d[1001] = { 0 }, a[1001] = { 0 }; scanf("%d", &n); scanf("%d", &k);
	for (i = 1; i <= n; i++) scanf("%d", &a[i]);
	d[0] = 1;
	for (i = 1; i <= n; i++) {
		for (j = a[i]; j <= k; j++) {
			//printf("d[%d] += d[%d - a[%d]] = ", j, j, i);
			d[j] += d[j - a[i]];
			//printf("%d\n", d[j]);
		}
	}
	printf("%d", d[k]);
}