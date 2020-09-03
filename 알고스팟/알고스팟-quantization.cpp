#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int n, s;
vector <int> v;
int cache[101][11];
int min_error(int start_index, int end_index) { //start_index ~ end_index 까지 제곱 최소 값 
	//printf("start_index : %d end_index : %d\n", start_index, end_index);
	int sum = 0;
	for (int i = start_index; i <= end_index; i++) {
		sum += v[i];
	}
	float mid_sum = floor(float(sum) / float(end_index - start_index + 1)+0.5);
	int  mid_num = (int)mid_sum;
	int re_ans = 0;
	for (int i = start_index; i <= end_index; i++) {
		re_ans += (mid_num - v[i])*(mid_num - v[i]);
	}
	return re_ans;

}
int quantum(int index, int part) {
	//printf("index : %d part : %d\n", index, part);
	//기저사례 
	if (index >= n) {
		return 0;
	}
	//모든 숫자를 다 양자화 했으면 return 0;

	if (part == 0) {
		return 987654321;
	}
	//숫자는 남았는데 part ==0 이면 아주큰수 return 
	
	int& ret = cache[index][part];
	if (ret != -1) {
		return ret;
	}

	ret = 987654321;
	for (int part_size = 1; index + part_size <= n; part_size++) {
		ret = min(ret, min_error(index, index + part_size-1) + quantum(index + part_size, part - 1));
	}
	return ret;
	
}
int main(void) {
	int C;
	cin >> C;
	for (int t = 1; t <= C; t++) {
		scanf("%d %d", &n, &s);
		v.clear();
		for (int i = 1; i <= n; i++) {
			int temp;
			scanf("%d", &temp);
			v.push_back(temp);
		}
		memset(cache, -1, sizeof(cache));
		sort(v.begin(), v.end());
		//vector sort 
		printf("%d\n",quantum(0, s));

	}
	return 0;
}