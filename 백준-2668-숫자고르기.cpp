#include<iostream>
#include<stdio.h>

using namespace std;

int map[101];
int downcheck[101];
int n;
int temp = 0; //�迭 �ʱ�ȭ���� ������ üũ�ϴ°����
void dfs(int start, int next) {
	if (start == next) {
		downcheck[start] = 1;
		return;
	}//����Ŭ�ϰ�� 
	if (downcheck[next] == 1) {
		temp = 1;
		return;
	}//����Ŭ�� �ƴ� ��� ! 

	downcheck[next] = 1;
	dfs(start, map[next]);
	if (temp == 1) {
		downcheck[next] = 0; //�迭�ʱ�ȭ
	}
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &map[i]);
	}//map�� �ֱ� 
	for (int i = 1; i <= n; i++) {
		temp = 0;
		if (downcheck[i] == 0) {
			dfs(i, map[i]);//�� �������� cycle üũ�ϱ�
		}
	}
	int cntans = 0;
	for (int i = 1; i <= n; i++) {
		if (downcheck[i] == 1) {
			cntans++;
		}
	}
	printf("%d\n", cntans);
	for (int i = 1; i <= n; i++) {
		if (downcheck[i] == 1) {
			printf("%d\n", i);
		}
	}
	return 0;
}