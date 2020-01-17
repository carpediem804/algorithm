#include <iostream>
#include <stdio.h>

using namespace std;
const int DIV_NUM = 1000000000;
int cache[101][10]; //[n][숫자] -> n번째 숫자가 올수 있는 경우의 수 

int stair(int index, int number) {
	if (index == 0) {
		return 0;
	}
	int& ret = cache[index][number];
	if (ret != 0) {
		return ret;
	}
	if (number == 9) {
		ret += stair(index - 1, 8);
		ret %= DIV_NUM;
	}
	else if (number == 0) {
		ret += stair(index - 1, 1);
		ret %= DIV_NUM;
	}
	else{
		ret += stair(index - 1, number - 1) + stair(index - 1, number + 1);
		ret %= DIV_NUM;
	}
	return ret;
}
int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i <= 9; i++) {
		if (i == 0) {
			cache[1][0] = 0;
		}
		cache[1][i] = 1;
	}
	cache[2][0] = 1;
	int ans = 0;
	for (int i = 1; i <= 9; i++) {
		ans += stair(n, i);
		ans %= DIV_NUM;
	}
	printf("%d\n", ans);

	return 0;
}