#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
int number[12];
char operate[10];
int n;
int pick[10]; //operate 선택인지 아닌지 확인하는 것
long long tempans = 0;
long long realans  = -214748367;
queue <int> q;

void calc() {
	for (int i = 1; i <=n/2 ; i++) { //큐에 계산 먼저해야하는것은 계산해서 넣기 
		if (pick[i] == 1) {
			if (operate[i] == '+') {
				q.push(number[i] + number[i + 1]);
			}
			else if (operate[i] == '-') {
				q.push(number[i] - number[i + 1]);
			}
			else if (operate[i] == '*') {
				q.push(number[i] * number[i + 1]);
			}
		}
		else {
			q.push(number[i]);
			q.push(operate[i]);
			if (i == n / 2) {
				q.push(number[n / 2 + 1]); //마지막 숫자 넣기 
			}
		}
	}
	tempans=0;
	tempans = q.front(); //처음 숫자 
	q.pop();
	while (q.size() != 0) {
			int temp = q.front(); //temp는 무조건 연산자로 나오니 
			q.pop();
			if (temp == '+') {
				tempans += (q.front());
				q.pop();
			}
			else if (temp == '-') {
				tempans -= (q.front());
				q.pop();
			}
			else if (temp == '*') {
				tempans *= (q.front());
				q.pop();

			}
	}
}
void dfs(int picknum, int index, int endpick) { //picknum = 0부터 index = 1부터 
	if (picknum == endpick) {
		for (int i = 1; i <= n/2; i++) {
			printf("%d ", pick[i]);
		}
		calc();
		if (realans < tempans) {
			realans = tempans;
		}
		return ;
	}
	if (index >= n/2+1) {
		return ;
	} 

	if (pick[index - 1] == 0) { //연속으로 선택할수 없다
		pick[index] = 1;
		dfs(picknum + 1, index + 1, endpick); //선택한 경우 
	}
	pick[index] = 0;
	dfs(picknum, index + 1,endpick); // 선택안한 경우 
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0) {
			scanf("%1c", &operate[i / 2]);
		}
		else {
			scanf("%1d", &number[i - (i / 2)]);
		}
	}
	if (n == 1) {
		printf("%d\n", number[1]);
		return 0;
	}
	for (int i = 0; i <= n / 2; i++) {
		dfs(0, 1, i);
	}//연산자 
	printf("%lld\n", realans);
	return 0;
}