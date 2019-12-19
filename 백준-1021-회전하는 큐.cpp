#include <stdio.h>
#include <deque>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	int n, m;
	queue <int> q;
	deque <int> dq;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int temp;
		scanf("%d", &temp);
		q.push(temp);
	}
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}
	
	int ans = 0;
	while(q.size() != 0) {
		int visit_num = q.front();
		q.pop();
		
		int index = 0;
		for (int i = 0; i < dq.size(); i++) {
			
			if (dq[i] == visit_num) {
				index = i;
				break;
			}
		}
		int dq_first = dq.front();
		int dqsize = dq.size();
		
		if (index < dq.size() - index) {
			while(dq_first != visit_num) {
				dq.push_back(dq.front());
				dq.pop_front();
				ans++;
				dq_first = dq.front();
			}
			dq.pop_front();
		}//2번하는게 더 가까운 경우 
		else {
			while (dq_first != visit_num) {
				dq.push_front(dq.back());
				dq.pop_back();
				ans++;
				dq_first = dq.front();
			}
			dq.pop_front();
		}

	}
	printf("%d\n", ans);
	return 0;
}