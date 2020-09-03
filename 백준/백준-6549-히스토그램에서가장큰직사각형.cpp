#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
long long map[100002];
long long solve(int left, int right) {//left~ right���� �ִ� ���簢�� ���� return 
	
	if (left == right) {
		return map[left];
	} ///left�� right�� �������� �� ���̰� ���� 

	int mid = (left + right) / 2;
	long long ret = max(solve(left, mid), solve(mid + 1, right));//2���� ���� ~ 
	
	int lo = mid;
	int hi = mid + 1;
	long long height = min(map[lo], map[hi]);
	//mid �翷���� ��ġ�� ����2�� ���簢�� ���̵� ��� 
	ret = max(ret, height * 2);
	// mid�� ��ġ�� �� �ִ� ���簢�� ���� �� �� 
	//�簢���� �Է� ��ü�� ���� �� ���� Ȯ�� 
	while (left < lo || hi < right) {//lo or hi �� ���̸� ������ �Ѵ� 
		//�׻� ���̰� �� ���������� Ȯ�� 
		if (lo == left) { //����
			if (right == hi) { //�����ʵ� �����̸�
				hi++;
				continue;
			}
			hi++;
			height = min(height, map[hi]);
		}
		else if (hi == right) { //����
			if (lo == left) {//���ʵ� �����̸� 
				lo--;
				continue;
			}
			lo--;
			height = min(height, map[lo]);
		}
		else {
			if (map[lo - 1] > map[hi + 1]) {
				lo--;
				height = min(height, map[lo]);
			}
			else {
				hi++;
				height = min(height, map[hi]);
			}
		}
		//printf("lo : %d hi : %d height : %d\n", lo, hi, height);
		ret = max(ret, height*(hi - lo + 1));

	}
	//printf("left : %d right :%d ret : %d\n", left, right, ret);
	return ret;
}
int main(void) {
	while (1) {
		int n;
		scanf("%d", &n);
		//printf("n : %d\n", n);
		if (n == 0) {
			return 0;
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &map[i]);
		}
		long long ans = solve(1, n);
		printf("%lld\n", ans);
	}
	return 0;
}