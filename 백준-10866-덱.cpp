#include <iostream>
#include <stdio.h>
#include <deque>
#include <string>
using namespace std;

int main(void) {
	int n;
	scanf("%d", &n);
	deque <int> dq;
	for (int i = 1; i <= n; i++) {
		
		string s;
		int n;
		cin >> s ;
		if (s == "push_back") {
			cin >> n;
			dq.push_back(n);
		}
		else if (s == "push_front") {
			cin >> n;
			dq.push_front(n);
		}
		else if (s == "pop_front") {
			if (dq.size() == 0) {
				printf("-1\n");
				continue;
			}
			printf("%d\n", dq.front());
			dq.pop_front();
		}
		else if (s == "pop_back") {
			if (dq.size() == 0) {
				printf("-1\n");
				continue;
			}
			printf("%d\n", dq.back());
			dq.pop_back();
		}
		else if (s == "size") {
			printf("%d\n", dq.size());
		}
		else if (s == "empty") {
			printf("%d\n", dq.empty());
		}
		else if (s == "front") {
			if (dq.size() == 0) {
				printf("-1\n");
				continue;
			}
			printf("%d\n", dq.front());
		}
		else if (s == "back") {
			if (dq.size() == 0) {
				printf("-1\n");
				continue;
			}
			printf("%d\n", dq.back());
		}
	}

	return 0;
}