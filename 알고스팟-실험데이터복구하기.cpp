#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int k;
string word[16];
int cache[15][(1<<15)+1], overlap[16][16];
int restore(int last, int which_used) {
	if (which_used == (1 << k) - 1) { //11111111111 모든 문자열이 다사용됫다면
		return 0;
	}
	int& ret = cache[last][which_used];
	if (ret != -1) {
		return ret;
	}
	ret = 0;
	for (int next = 0; next < k; next++) {
		if ((which_used & (1 << next)) == 0) {//아직 사용안된 next째 부분 문자열을 발견했으면
			int candidate = overlap[last][next] + restore(next, which_used + (1 << next));
			ret = max(ret, candidate);
		}
	}
	return ret;
}
string reconstruct(int last, int used) {
	if (used == (1 << k) - 1) {
		return "";
	}
	for (int next = 0; next < k; next++) {

		if ((used & (1 << next))!=0 ) {
			//printf("test : %d\n", (used & (1 << next)));
			continue;
		}//이미 사용됫다면 제외

		int if_used = restore(next, used + (1 << next)) + overlap[last][next];
		//next를 사용했을때의 경우 답이 최적해와 같다면 next사용 
		if (restore(last, used) == if_used) {
			return (word[next].substr(overlap[last][next]) + reconstruct(next, used + (1 << next)));
		}

	}
	return "error~~";
}
//overlap초기화 ->s1과 s2가 겹치는 수 return 
int get_overlap(const string &s1, const string &s2) {
	int length = min(s1.size(), s2.size());
	for (; length > 0; length--) {
		if (s1.substr(s1.size() - length) == s2.substr(0, length)) {
			return length;
		}
	}
	return 0;
}
int main(void) {
	int C;
	scanf("%d", &C);
	for (int t = 1; t <= C; t++) {
		scanf("%d", &k);
		for (int i = 0; i < k; i++) {
			cin >> word[i];
		}
		memset(cache, -1, sizeof(cache));
		while (true) {
			bool removed = false;
			for (int j = 0; j < k && !removed; j++) {
				for (int k_ = 0; k_ < k; k_++) {
					if (j != k_ && word[j].find(word[k_]) != -1) { //부분 문자열이 겹친다면 ~ 
						//printf("in\n");
						word[k_] = word[k - 1]; //맨끝에있는 string과 위치변경 
						k--;
						removed = true;
					}
				}
			}
			if (!removed) {
				break;
			}
		}
		//printf("k : %d\n", k);
		word[k] = "";

		//overlap초기화
		for (int j = 0; j <= k; j++) {
			for (int k_ = 0; k_ <= k; k_++) {
				overlap[j][k_] = get_overlap(word[j], word[k_]);
			}
		}


		cout << reconstruct(k, 0) << endl;
	}

	return 0;
}