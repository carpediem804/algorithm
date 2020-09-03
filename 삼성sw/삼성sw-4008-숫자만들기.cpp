#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int N;
int map[13]; //��������
int oper[12];//������ ����
// plus = 1 minus =2 , multiple =3 division =4
int maxnum = -100000000;
int minnum = 100000000;
void calc() {
	int temp = map[1];
	for (int i = 2; i <= N; i++) {
		if (oper[i - 1] == 1) { //plus�� ��� 
			temp += map[i];
		}
		else if (oper[i - 1] == 2) {//minus�� ���
			temp -= map[i];
		}
		else if (oper[i - 1] == 3) { //���ϴ� ���
			temp *= map[i];
		}
		else if (oper[i - 1] == 4) {//������ ��� 
			temp /= map[i];
		}
	}
	if (temp > maxnum) {
		maxnum = temp;
	}
	if (temp < minnum) {
		minnum = temp;
	}

}
void dfs(int index, int plus, int minus, int multiple, int division) {
	if (index == N ) {
		calc();
		return;
	}
	if (plus != 0) {
		oper[index] = 1; //������ ��� 
		dfs(index + 1, plus - 1, minus, multiple, division);
	}
	if (minus != 0) {
		oper[index] = 2; //������ ��� 
		dfs(index + 1, plus , minus-1, multiple, division);
	}
	if (multiple != 0) {
		oper[index] = 3; //������ ��� 
		dfs(index + 1, plus, minus , multiple-1, division);
	}
	if (division != 0) {
		oper[index] = 4; //������ ��� 
		dfs(index + 1, plus, minus , multiple, division-1);
	}
}
void clear() {
	for (int i = 1; i <= N; i++) {
		map[i] = 0;
	}
	for (int i = 1; i <= N-1; i++) {
		oper[i] = 0;
	}
	maxnum = -100000000;
	minnum = 100000000;
}
int main(void) {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d", &N);
		int plus, minus, multiple, division;
		scanf("%d %d %d %d", &plus, &minus, &multiple, &division);
		for (int i = 1; i <= N; i++) {
			scanf(" %d", &map[i]);
		}
		dfs(1, plus, minus, multiple, division);
		printf("#%d %d\n", t, abs(maxnum - minnum));
		clear();
	}
	return 0;
}