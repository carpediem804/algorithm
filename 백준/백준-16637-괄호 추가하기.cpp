#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
int number[12];
char operate[10];
int n;
int pick[10]; //operate �������� �ƴ��� Ȯ���ϴ� ��
long long tempans = 0;
long long realans  = -214748367;
queue <int> q;

void calc() {
	for (int i = 1; i <=n/2 ; i++) { //ť�� ��� �����ؾ��ϴ°��� ����ؼ� �ֱ� 
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
				q.push(number[n / 2 + 1]); //������ ���� �ֱ� 
			}
		}
	}
	tempans=0;
	tempans = q.front(); //ó�� ���� 
	q.pop();
	while (q.size() != 0) {
			int temp = q.front(); //temp�� ������ �����ڷ� ������ 
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
void dfs(int picknum, int index, int endpick) { //picknum = 0���� index = 1���� 
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

	if (pick[index - 1] == 0) { //�������� �����Ҽ� ����
		pick[index] = 1;
		dfs(picknum + 1, index + 1, endpick); //������ ��� 
	}
	pick[index] = 0;
	dfs(picknum, index + 1,endpick); // ���þ��� ��� 
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
	}//������ 
	printf("%lld\n", realans);
	return 0;
}