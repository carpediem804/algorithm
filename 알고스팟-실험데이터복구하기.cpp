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
	if (which_used == (1 << k) - 1) { //11111111111 ��� ���ڿ��� �ٻ��̴ٸ�
		return 0;
	}
	int& ret = cache[last][which_used];
	if (ret != -1) {
		return ret;
	}
	ret = 0;
	for (int next = 0; next < k; next++) {
		if ((which_used & (1 << next)) == 0) {//���� ���ȵ� next° �κ� ���ڿ��� �߰�������
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
		}//�̹� ���̴ٸ� ����

		int if_used = restore(next, used + (1 << next)) + overlap[last][next];
		//next�� ����������� ��� ���� �����ؿ� ���ٸ� next��� 
		if (restore(last, used) == if_used) {
			return (word[next].substr(overlap[last][next]) + reconstruct(next, used + (1 << next)));
		}

	}
	return "error~~";
}
//overlap�ʱ�ȭ ->s1�� s2�� ��ġ�� �� return 
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
					if (j != k_ && word[j].find(word[k_]) != -1) { //�κ� ���ڿ��� ��ģ�ٸ� ~ 
						//printf("in\n");
						word[k_] = word[k - 1]; //�ǳ����ִ� string�� ��ġ���� 
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

		//overlap�ʱ�ȭ
		for (int j = 0; j <= k; j++) {
			for (int k_ = 0; k_ <= k; k_++) {
				overlap[j][k_] = get_overlap(word[j], word[k_]);
			}
		}


		cout << reconstruct(k, 0) << endl;
	}

	return 0;
}