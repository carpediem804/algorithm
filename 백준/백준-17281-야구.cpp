#include <iostream>
#include <stdio.h>

using namespace std;
int order[10]; //��� ������ 1������ 9������ ������
int n;
int map[51][10];
int visit[10];
int base[3];
int tempans = 0;
int ans = 0;
void calc2(int num) { //�����ϴ°� üũ
	if (num == 1) {
		if (base[2] == 1) {
			tempans += 1;
			base[2] = 0;
		}
		if (base[1] == 1) {
			base[2] = 1;
			base[1] = 0;
		}
		if (base[0] == 1) {
			base[0] = 1;
			base[1] = 1;
		}
		base[0] = 1;
	}
	else if (num == 2) {
		if (base[2] == 1) {
			tempans += 1;
			base[2] = 0;
		}
		if (base[1] == 1) {
			tempans += 1;
			base[1] = 0;
		}
		if (base[0] == 1) {
			base[0] = 0;
			base[2] = 1;
		}
		base[1] = 1;
	}
	else if (num == 3) {
		if (base[2] == 1) {
			tempans += 1;
			base[2] = 0;
		}
		if (base[1] == 1) {
			tempans += 1;
			base[1] = 0;
		}
		if (base[0] == 1) {
			tempans += 1;
			base[0] = 0;
			
		}
		base[2] = 1;
	}
	else if (num == 4) {
		if (base[2] == 1) {
			tempans += 1;
			base[2] = 0;
		}
		if (base[1] == 1) {
			tempans += 1;
			base[1] = 0;
		}
		if (base[0] == 1) {
			tempans += 1;
			base[0] = 0;
		}
		tempans += 1;
	}
}
void calc() {
	int temp = 1; //����
	int ining = 1; //�̴� ���� 
	int outcnt = 0; //�ƿ�ī��Ʈ 
	int running_num = 0;
	tempans = 0;
	while (1) {
		if (ining == n+1) {
			return ;
		}
		int taza = order[temp]; //Ÿ�� ���� 
	//	printf("ining : %d outcnt : %d taza : %d running_num : %d\n",ining, outcnt, taza, running_num);
		if (map[ining][taza] == 0) {
			outcnt++;
			if (temp == 9) {
				temp = 0;
			}
			temp++;
			if (outcnt == 3) {
				outcnt = 0;
				ining++;
				base[0] = 0;
				base[1] = 0;
				base[2] = 0; //base�ʱ�ȭ
			}
		}
		else { //��Ÿ 2��Ÿ 3��Ÿ Ȩ�� �� ��� running num�� �߰���
			int anta_num = map[ining][taza];
			calc2(anta_num);
			if (temp == 9) { //9��Ÿ�ڱ��� ���ٸ� ���� �ٽ� 1��Ÿ�� ���� ���ߴ�
					temp = 0;
			}
			temp++; //���� Ÿ�ڸ� ���� ���� 
		}
	}
}
void dfs(int index) { //sunsu = 1��~9������ index = Ÿ�� ����
	if (index == 10) {
		
		calc();
		//printf("tempans : %d\n", tempans);
		
		if (tempans > ans) {
			ans = tempans;
		}
		//���� ��� 
		return;
	}
	if (index == 4) {
		order[index] = 1; //1�������� 4��Ÿ�ڴ� 
		dfs(index + 1);

	}
	else {
		for (int i = 2; i <= 9; i++) {
			if (visit[i] == 0) {
				visit[i] = 1;
				order[index] = i;
				dfs(index + 1);
				visit[i] = 0;
			}
		}
	}
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 9; j++) {
			scanf(" %d", &map[i][j]);

		}
	}
	
	dfs(1);
	printf("%d\n",ans);
	return 0;
}