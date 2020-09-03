#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int map[100001];
int check[100001]; // �湮�޴��� �ٽ� �湮 ���ҷ��� 
int n;
int temp = 0;
vector <int> v;
void dfs(int start,int next) {
	
	if (check[next] == 1 || (next<start && check[next]==0)) {
		temp = 1;
		return;
	}//�������� �ι� �湮�ϸ� �ȵǰ� �� ���� �˻��� ���� �ȵȴٰ� �ߴµ� next�� ���� ��� �ٷ� return 
	if (start == next ) {
		check[next] = 1; //�ٷ� �� ��� 
		temp = 0;
		return;
	}//����Ŭ�� �� ��� 
	check[next] = 1; //������ üũ�ߴٰ� �ϰ� 
	dfs(start, map[next]); //dfs ���ư���~
	if (temp == 1) { // cycle�� �ƴ� ��� !! 
		check[next] = 0;//check�� 1�� �ߴ��͵� �� 0���� �ٲ۴� 
	}
}
int main(void) {
	int t;
	
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		int ans = 0;
		scanf("%d", &n);
		for (int j = 1; j <= n; j++) {
			scanf(" %d", &map[j]);
		}//map�� �� �־���
		for (int start = 1; start <= n; start++) {
			if (check[start] == 0) {
				temp = 0;
				dfs(start,map[start]); //����Ŭ üũ�ϴ� �� 
			}
		}
		for (int x = 1; x <= n; x++) {
			if (check[x] == 0) {
				ans++; //�ȵǴ� ������ 0�̴ϱ� ans ++;
			}
			check[x] = 0; //check�迭 �ʱ�ȭ
			map[x] = 0; //map�迭 �ʱ�ȭ 
		}//����� ���
		printf("%d \n", ans);
	}
	
	return 0;
}