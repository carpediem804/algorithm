#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector <pair<int, int>> power_pole;
int dp[501];
int calc(int index) {

	int& ret = dp[index];
	if (ret != 0) {
		return ret;
	}
	for (int i = index + 1; i < power_pole.size(); i++) {
		if (power_pole[index].second < power_pole[i].second) {
			ret = max(ret, calc(i) + 1);
		}//둘 수 있는 경우 
	}
	return ret;

}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		power_pole.push_back(make_pair(a, b));
	}
	sort(power_pole.begin(), power_pole.end());
	//오름차순 정렬 했다잉 
	
	//안겹치고 만들수 있는 최대 수 계산 
	int can_make_num = 0;
	for (int i = 0; i < power_pole.size(); i++) {
		can_make_num = max(can_make_num, calc(i));
	}
	printf("%d\n", power_pole.size() - can_make_num-1);
	return 0;
}