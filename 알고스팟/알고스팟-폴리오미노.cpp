#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;
int n;
int cache[101][101];
int poly(int remain_box, int first_low_box_num) { //���� �ڽ��� ù��° ���� ���� �ڽ��� ���ؠ����� ����� �� 
	if (remain_box == first_low_box_num) {
		return 1;
	}//������� ���� �ڽ� == ù��° ���̿� �ڽ� �δ°��� ������ ����Ǽ� 1

	int& ret = cache[remain_box][first_low_box_num];
	if (ret != -1) {
		return ret;
	}
	ret = 0;
	for (int next = 1; next <= remain_box - first_low_box_num; next++) {

		int previous_num = first_low_box_num + next - 1;
		int add = (poly(remain_box - first_low_box_num, next));
		add = (add * previous_num);
		add %= 10000000;
		ret += add ;
		ret %= 10000000;
	}
	return ret;

}
int main(void) {
	int C;
	scanf("%d", &C);
	for (int t = 1; t <= C; t++) {
		scanf("%d", &n);
		memset(cache, -1, sizeof(cache));
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			ans += poly(n, i);
			ans %= 10000000;
		}
		printf("%d\n", ans);
	}

	return 0;
}