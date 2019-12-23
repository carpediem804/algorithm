#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct cmp {
	bool operator()(long long a, long long b) {
		if (abs(a) == abs(b)) {
			return a > b;
		}
		return abs(a) > abs(b);
	}
};
priority_queue <long long, vector<long long>, cmp> pq;
int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		long long temp;
		scanf("%lld", &temp);
		if (temp != 0) {
			pq.push(temp);
		}
		else {
			if (pq.size() == 0) {
				printf("0\n");
			}
			else {
				printf("%lld\n", pq.top());
				pq.pop();
			}
		}
	}
	return 0;
}