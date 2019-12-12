#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector <pair<long long ,long long>> v;
bool cmp(const pair<long long, long long> v1, const pair<long long, long long> v2) {
	if (v1.second == v2.second) {
		return v1.first < v2.first;
	}
	return v1.second < v2.second ;
}
int main(void) {
	int n;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		long long a, b;
		scanf("%lld %lld", &a, &b);
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end(), cmp);
	int ans = 0;
	long long end_time = 0;
	for (int i = 0; i < n; i++) {

		if (v[i].first >= end_time) {
			end_time = v[i].second;
			ans++;
		}//시작 시간이 end_time보다 크다면 
	}
	printf("%d\n", ans);
	return 0;
}