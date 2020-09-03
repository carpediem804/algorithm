#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

int cache[10001];
string s;

int level(int start_index,int last_index) {
	
	string temp_s = s.substr(start_index, last_index-start_index+1);
	//���̵�1 - ��� ���ڰ� ���� ��
	int check1 = 0;
	for (int i = 0; i < temp_s.size(); i++) {
		if (temp_s[0] != temp_s[i]) {
			check1 = 1;
			break;
		}
	}
	if (check1 == 0) {
		return 1;
	}

	//���̵�2 = > 1�� ���� �ϰų� �����Ҷ� 
	check1 = 0;
	for (int i = 1; i < temp_s.size(); i++) {
		if (temp_s[1]-temp_s[0] != temp_s[i]-temp_s[i-1]) {
			check1 = 1;
			break;
		}
	}
	int level_five = 0;
	if (check1 == 0 ) {
		if (temp_s[1] - temp_s[0] == 1 || temp_s[1] - temp_s[0] == -1) {
			return 2;
		}
		level_five = 1;
	}
	//���̵� 4 -> �ΰ��� ���ڰ� ������ ���� ���� 
	check1 = 0;
	bool alternating = true;
	for (int i = 0; i < temp_s.size(); i++) {
		if (temp_s[i] != temp_s[i % 2]) {
			alternating = false;
		}
	}
	if (alternating)  return 4;
	if (level_five == 1) {
		return 5;
	}
	return 10;

}
int calc(int start_index) { //0�� index���� ~ 
	if (s.size() <= start_index) {
		return 0;
	}//n�� ������ �̸� 
	
	int& ret = cache[start_index];
	if (ret != 0) {
		return ret;
	}

	ret = 987654321 ; 
	for (int i = 3; i <= 5; i++) {
		if (start_index + i <= s.size()) {
			ret = min(ret, level(start_index, start_index + i - 1) + calc(start_index + i));
		}
	}

	return ret;

}
int main(void) {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		
		cin >> s;
		memset(cache, 0, sizeof(cache));
		printf("%d\n", calc(0));
	}

	return 0;
}