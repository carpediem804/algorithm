#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long n, m;
vector<int>v;
int main(void) {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		
		scanf(" %lld %lld", &n, &m);
		//printf("%lld %lld\n", n, m);
		for (int i = 1; i <= n; i++) {
			long long temp;
			scanf(" %lld", &temp);
			v.push_back(temp);
		}//vector에 다 넣엇다 
		
		sort(v.begin(), v.end());//vector 소팅
		long long _max = v[n - 1] * m;
		long long left = 0;
		long long right = _max;
		//printf("%lld %lld %lld\n", _max, left, right);
		while (left <= right) {
			if (left > right) {
				break;
			}
			long long cannum = 0;
			long long mid = (left + right) / 2;
			//printf("left : %lld right : %lld mid : %lld\n", left, right, mid);
			for (int i = 0; i < n; i++) {
				cannum += mid / v[i];//mid시간안에 통과하는사람수
			}
			if (cannum >= m) {
				right = mid-1;
			}
			else {
				left = mid + 1;
			}
		}
		printf("#%d %lld\n", t, left);
		v.clear();
	}

	return 0;
}