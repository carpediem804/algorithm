#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

int main(void) {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int n, m;
		queue <pair<int,int>> q1;
		queue <pair<int,int>> q2;
		
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			int temp;
			scanf("%d", &temp);
			q1.push(make_pair(temp,i));
			
		}
		int out_order = 1;
		while (q1.size() != 0) {
			int num = q1.front().first;
			int index = q1.front().second;
			q1.pop();
			q2 = q1;
			int check = 0;
			while (q2.size() != 0) {
				int q2num = q2.front().first;
				q2.pop();
				if (q2num > num) { //뒤에 큰값이 있따면 
					check = 1;
					q1.push(make_pair(num,index));
					break;
				}
			}
			if (check != 1) {
				if (index == m) {
					printf("%d\n", out_order);
					break;
				}
				else {
					out_order++;
				}
			}//뒤에 큰값이 없다면 
		}

	}

	return 0;
}