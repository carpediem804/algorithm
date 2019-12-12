#include <iostream>
#include <stdio.h>

using namespace std;
int gcd(int a, int b) {
	if (a%b == 0) {
		return b;
	}
	return gcd(b, a%b);
}
int map[100];
int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		map[i] = temp;
	}
	for (int i = 1; i < n; i++) {
		int maxgcd = gcd(map[0], map[i]);
		printf("%d/%d\n", map[0] / maxgcd, map[i] / maxgcd);
	}

	return 0;
}