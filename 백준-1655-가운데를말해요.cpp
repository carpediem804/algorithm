#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
struct cmp {
	bool operator()(int a, int b) {
		return a > b;
	}
};
/*
중간값 
1. maxheap 크기는 minheap.size() or +1;
2. max_heap top < min_heap 
맞지않으면 swap (max_heap top ,min_heap top)
*/
int main(void) {
	int n;
	priority_queue <int,vector<int>,cmp> min_heap;
	priority_queue <int, vector<int>> max_heap;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		
		if (max_heap.size() == min_heap.size() ) {
			max_heap.push(temp);
		}
		else {
			min_heap.push(temp);
		}
		if (min_heap.size() == 0) {
			printf("%d\n", max_heap.top());
			continue;
		}
		if (max_heap.top() < min_heap.top()) {
			printf("%d\n", max_heap.top());
		}
		else {
			int max_num = max_heap.top();
			max_heap.pop();
			int min_num = min_heap.top();
			min_heap.pop();
			max_heap.push(min_num);
			min_heap.push(max_num);
			printf("%d\n", max_heap.top());
		}
		
	}
	return 0;
}