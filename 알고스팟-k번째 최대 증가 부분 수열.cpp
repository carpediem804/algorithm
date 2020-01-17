#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
const int MAX_NUM = 2000000000+1;
int n, k;
int map[501];
int cache[501];
int hubo_num_cache[501];
int max_lis_num;
vector <int> ans;
int lis(int index) {
	if (index == n) {
		cache[index] = 1;
		return 1;
	}
	int &ret = cache[index];
	if (ret != 0) {
		return ret;
	}
	ret = 1;
	for (int i = index + 1; i <= n; i++) {
		if (map[index] < map[i]) {
			ret = max(ret, lis(i)+1);
		}
	}
	return ret;
}
int calc_hubo_num(int index) { //index에서의 lis return
	
	if (cache[index] == 1) {
		hubo_num_cache[index] = 1;
		return 1;
	}//기저 사례 -> 나밖에 없을때 return 1


	int& ret = hubo_num_cache[index];

	if (ret != 0) {
		return ret;
	}

	for (int next = index + 1; next <= n; next++) {
		if (cache[index] - 1 == cache[next] && map[index] < map[next]) {
			ret = min<long long >(MAX_NUM, (long long)ret + calc_hubo_num(next));
		}
	}
	return ret;
}
void k_pick_numbers(int index, int skip) {
	//printf("index : %d skip : %d\n", index, skip);
	//2. 뒤에올수 있는 숫자들과 위치의 목록을 만든다 
	// ( 숫자,숫자의 위치)목록 
	vector <pair<int, int> > followers;

	for (int next = index + 1; next <= n; next++) {
		//printf("index : %d next :%d\n", index, next);
		if (cache[index] - 1 == cache[next] && map[index] < map[next]) {
			//printf("in if \n");
			followers.push_back(make_pair(map[next],next));
		}
	}
	sort(followers.begin(), followers.end());
	for (int i = 0; i < followers.size(); i++) {
		int hubo_number = hubo_num_cache[followers[i].second];
		//printf("index : %d hubo_num : %d hubo_number : %d\n", index, hubo_number, followers[i].first);
		if (skip <= hubo_number) {
			ans.push_back(followers[i].first);
			//printf("push_number : %d\n", followers[i].first);
			k_pick_numbers(followers[i].second, skip);
			break;
		}
		else {
			skip -= hubo_number;
		}
	}

}
int main(void) {
	int C;
	scanf("%d", &C);
	for (int t = 1; t <= C; t++) {
		scanf("%d %d", &n, &k);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &map[i]);
		}
		memset(cache, 0, sizeof(cache));
		memset(hubo_num_cache, 0, sizeof(hubo_num_cache));

		lis(0);
		max_lis_num = cache[0] - 1;
		
		printf("%d\n", max_lis_num);
		
		calc_hubo_num(0);
		
		k_pick_numbers(0, k);
		for (int i = 0; i < ans.size(); i++) {
			printf("%d ", ans[i]);
		}printf("\n");
		ans.clear();
	}

	return 0;
}