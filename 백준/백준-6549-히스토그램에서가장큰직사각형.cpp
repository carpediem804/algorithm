#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
long long map[100002];
long long solve(int left, int right) {//left~ right까지 최대 직사각형 넓이 return 
	
	if (left == right) {
		return map[left];
	} ///left와 right가 같을때는 그 높이가 넓이 

	int mid = (left + right) / 2;
	long long ret = max(solve(left, mid), solve(mid + 1, right));//2개로 분할 ~ 
	
	int lo = mid;
	int hi = mid + 1;
	long long height = min(map[lo], map[hi]);
	//mid 양옆으로 곂치는 길이2인 직사각형 넓이도 고려 
	ret = max(ret, height * 2);
	// mid와 겹치는 게 최대 직사각형 넓이 일 때 
	//사각형이 입력 전체를 덮을 때 까지 확장 
	while (left < lo || hi < right) {//lo or hi 가 사이면 무조건 한다 
		//항상 높이가 더 높은쪽으로 확장 
		if (lo == left) { //끝점
			if (right == hi) { //오른쪽도 끝점이면
				hi++;
				continue;
			}
			hi++;
			height = min(height, map[hi]);
		}
		else if (hi == right) { //끝점
			if (lo == left) {//왼쪽도 끝점이면 
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