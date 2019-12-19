#include <iostream>
#include <stdio.h>
#include <string>
#include <deque>

using namespace std;

int main(void) {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		string order;
		cin >> order;
		int n;
		cin >> n;
		deque <int> dq;
		string s;
		cin >> s;
		string temp = "";
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '[' ) {
				continue;
			}
			if (s[i] >= '0' && s[i] <= '9') {
				temp += s[i];
			}
			if (s[i] == ']') {
				if (temp != "") {
					dq.push_back(atoi(temp.c_str()));
				}
				temp = "";
			}
			if (s[i] == ',') {
				dq.push_back(atoi(temp.c_str()));
				temp = "";
			}
		} //dq에 다 넣엇다 
		int check = 0;
		int check2 = 0;
		//printf("Dq.size  \%d\n", dq.size());
		for (int i = 0; i < order.size(); i++) {
			if (order[i] == 'R') {
				if (check == 0) {
					check = 1;
				}
				else if (check == 1) {
					check = 0;
				}
			}
			else if (order[i] == 'D') {
				if (check == 0) { //제대로 된 순서 ~ 
					if (dq.size() == 0) {
						printf("error\n");
						check2 = 1;
						break;
					}
					dq.pop_front();
				}
				else if (check == 1) { //거꾸로 된 순서 
					if (dq.size() == 0) {
						printf("error\n");
						check2 = 1;
						break;
					}
					dq.pop_back();
				}
			}
		}
		if (check2 == 1) {
			continue;
		}
		printf("[");
		if (check == 0) {
			for (int i = 0; i < dq.size(); i++) {
				printf("%d", dq[i]);
				if (i != dq.size() - 1) {
					printf(",");
				}
			}
		}
		else {
			for (int i = dq.size()-1; i >=0; i--) {
				printf("%d", dq[i]);
				if (i != 0) {
					printf(",");
				}
			}
		}
		printf("]\n");
		dq.clear();
	}

	return 0;
}