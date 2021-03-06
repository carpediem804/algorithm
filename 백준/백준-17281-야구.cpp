#include <iostream>
#include <stdio.h>

using namespace std;
int order[10]; //몇번 선수가 1번부터 9번까지 스는지
int n;
int map[51][10];
int visit[10];
int base[3];
int tempans = 0;
int ans = 0;
void calc2(int num) { //진루하는거 체크
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
	int temp = 1; //변수
	int ining = 1; //이닝 변수 
	int outcnt = 0; //아웃카운트 
	int running_num = 0;
	tempans = 0;
	while (1) {
		if (ining == n+1) {
			return ;
		}
		int taza = order[temp]; //타자 선수 
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
				base[2] = 0; //base초기화
			}
		}
		else { //안타 2루타 3루타 홈런 할 경우 running num에 추가함
			int anta_num = map[ining][taza];
			calc2(anta_num);
			if (temp == 9) { //9번타자까지 쳣다면 이제 다시 1번타자 부터 봐야댐
					temp = 0;
			}
			temp++; //다음 타자를 위해 고고싱 
		}
	}
}
void dfs(int index) { //sunsu = 1번~9번선수 index = 타자 순서
	if (index == 10) {
		
		calc();
		//printf("tempans : %d\n", tempans);
		
		if (tempans > ans) {
			ans = tempans;
		}
		//이제 계산 
		return;
	}
	if (index == 4) {
		order[index] = 1; //1번선수가 4번타자다 
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