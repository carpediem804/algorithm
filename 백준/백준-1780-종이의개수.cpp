#include <stdio.h>

using namespace std;
int map[2188][2188];
int zero, one, minusone;
void dfs(int x, int y, int n) {
	int check_num = map[x][y];
	int check = 0;
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if(check_num != map[i][j] || check ==1){
				check = 1;
				break;
			}
		}
		if (check == 1) {
			break;
		}
	}
	if (check == 1) { //같은숫자가 아닌경우 9개로 나눠짐
		dfs(x, y, n / 3);
		dfs(x, y + n / 3, n / 3);
		dfs(x, y + 2 * (n / 3), n / 3);

		dfs(x + n / 3, y, n / 3);
		dfs(x + n / 3, y + (n / 3), n / 3);
		dfs(x + n / 3, y + 2 * (n / 3), n / 3);

		dfs(x + 2 * (n / 3), y , n / 3);
		dfs(x + 2*(n / 3), y + n / 3, n / 3);
		dfs(x + 2 * (n / 3), y + 2*(n / 3), n / 3);

	}
	else {
		if (check_num == 0) {
			zero++;
		}
		else if (check_num == 1) {
			one++;
		}
		else {
			minusone++;
		}
	}
}
int main(void) {
	int n;
	scanf("%d", &n);
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			int temp;
			scanf("%d", &temp);
			map[x][y] = temp;
		}
	}
	dfs(1, 1, n);
	printf("%d\n%d\n%d\n", minusone, zero, one);
	return 0;
}