#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	vector <int> v;
	int n,c;
	scanf("%d %d", &n,&c);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	int min_diff = 1;
	int max_diff = v[v.size() - 1] - v[0];
	
	
	int ans = 0;
	while (min_diff <= max_diff) {
		int wifi_num = 1;
		int mid_diff = (min_diff + max_diff) / 2;
		int prev_idex = 0;
		//printf("%d %d %d\n", min_diff, mid_diff, max_diff);
		for (int i = 0; i < v.size(); i++) {
			if (v[i] - v[prev_idex] >= mid_diff) { //mid_diff보다 차이가 클때 와이파이설치
				prev_idex = i;
				wifi_num++;
			}
		}
		//printf("wifinum : %d\n", wifi_num);
		if (c <= wifi_num) { //설치개수보다 wifi_num이 클 경우
			min_diff = mid_diff + 1;
		}
		else {
			max_diff = mid_diff - 1;
		}
		if (c <= wifi_num && ans <= mid_diff) {
			ans = mid_diff;
		}
	}
	printf("%d\n", ans);
	return 0;
}