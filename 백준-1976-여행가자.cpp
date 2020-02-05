#include <iostream>
#include <stdio.h>

using namespace std;
int n, m;
int root_map[201];
int travle[1001];
int find_root(int a) {
	if (root_map[a] == a) {
		return a;
	}
	return root_map[a] = find_root(root_map[a]);
}
void union_(int a, int b) {
	int root_a = find_root(a);
	int root_b = find_root(b);
	root_map[root_a] = root_map[root_b];
}

int main(void) {
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 1; i <= n; i++) {
		root_map[i] = i;
	}
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			int temp;
			scanf("%d", &temp);
			if (temp == 1) {
				union_(x, y);
			}
		}
	}
	
	for (int i = 1; i <= m; i++) {
		scanf("%d", &travle[i]);
	}
	int cango = find_root(travle[1]);
	for (int i = 2; i <= m; i++) {
		if (cango != find_root(travle[i])) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");

	return 0;
}