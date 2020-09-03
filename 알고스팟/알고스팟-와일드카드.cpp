#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
int n;
string W,S;
int cache[101][101];
vector <string> ans;

bool check_memory(int w_index,int s_index) {
	
	int& ret = cache[w_index][s_index];
	//ret이 주소값임으로 ret 바꾸면 cache[w_index][s_index]도 바뀐다 
	if (ret != -1) {
		return ret;
	} //기저값 
	//W[w]와 S[s]를 맞춰나간다 
	while (w_index < W.size() && s_index < S.size() && (W[w_index] == S[s_index] || W[w_index] == '?')) {
		return ret = check_memory(w_index + 1, s_index + 1);
	}
	if (w_index == W.size()) {
		if (s_index == S.size()) {
			return ret = 1;
		}
		
		return ret = 0;
	}
	if (W[w_index] == '*') {
		while (check_memory(w_index + 1, s_index) || (s_index < S.size() && check_memory(w_index, s_index + 1))) {
			return ret = 1;
		}
	}

	return ret = 0;

}
int main(void) {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		cin >> W;
		
		scanf("%d", &n);
		
		for (int i = 1; i <= n; i++) {
			memset(cache, -1, sizeof(cache));
			cin >> S;
			if (check_memory(0, 0)) {
				ans.push_back(S);
			}
		}
		sort(ans.begin(), ans.end());
		//printf("ans : --------\n");
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << "\n";
		}
		//printf("------------\n");
		ans.clear();

	}

	return 0;
}

