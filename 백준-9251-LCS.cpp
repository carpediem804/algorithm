#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
string a, b;
int cache[1001][1001];// a_index와 b_index에서의 최대 lcs
int calc(int a_index, int b_index) {
	if (a_index >= a.size() || b_index >= b.size()) {
		return 0;
	}
	
	int& ret = cache[a_index][b_index];
	if (ret != 0) {
		return ret;
	}
	ret = 0;
	if (a[a_index] == b[b_index]) {
		ret = calc(a_index + 1, b_index + 1) + 1;
	}

	ret = max(ret, calc(a_index + 1, b_index));
	ret = max(ret, calc(a_index, b_index + 1));

	
	return ret;
}
int main(void) {
	cin >> a;
	cin >> b;
	
	printf("%d\n", calc(0, 0));
	
	return 0;
}