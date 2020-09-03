#include <iostream>
#include <stdio.h>

using namespace std;

int N;
int peoplenum[11];
int one_or_two[11];
int connect[11][11];
int visit[11];
int realans = 987654321;
int tempans = 987654321;
void check(int index,int cnt) {
	
	if (cnt == 1) {
		visit[index] = 1;
		for (int i = 1; i <= N; i++) {
			if (connect[index][i] == 1 && visit[i] == 0 && one_or_two[i]==1) {
				visit[i] = 1;
				check(i, 1);
			}
		}
	}
	else if (cnt == 2) {
		visit[index] = 2;
		for (int i = 1; i <= N; i++) {
			if (connect[index][i] == 1 && visit[i] == 0 && one_or_two[i]==2) {
				visit[i] = 2;
				check(i, 2);
			}
		}
	}
}
void calc() {
	for (int i = 1; i <= N; i++) {
		visit[i] = 0;
	}
	for (int i = 1; i <= N; i++) {
		if (one_or_two[i] == 1) {		
			check(i,1);
			break;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (one_or_two[i] == 2) {
			check(i, 2);
			break;
		}
	}
	
	int onesum = 0;
	int twosum = 0;
	for (int i = 1; i <= N; i++) {
		if (visit[i] == 1) {
			onesum += peoplenum[i];
		}
		else if (visit[i] == 2) {
			twosum += peoplenum[i];
		}
		else if (visit[i] == 0) {
			tempans = 987654321;
			return ;
		}
	}
	if (onesum == 0 || twosum == 0) {
		tempans = 987654321;
	}
	else {
		tempans = abs(onesum - twosum);
	}
	

	return;
}
void divide(int index) {
	if (index == N + 1) {
		calc();
		if (realans > tempans) {
			realans = tempans;
		}
		return;
	}
	one_or_two[index] = 1;
	divide(index + 1);
	one_or_two[index] = 2;
	divide(index + 1);
}
int main(void) {
	scanf(" %d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d ", &peoplenum[i]);
	}
	for (int i = 1; i <= N; i++) {
		int temp;
		scanf("%d", &temp);
		for (int j = 1; j <= temp; j++) {
			int temp2;
			scanf("%d", &temp2);
			connect[i][temp2] = 1;
			connect[temp2][i] = 1;
		}
	}
	
	divide(0);
	if (realans == 987654321) {
		printf("-1\n");
	}
	else {
		printf("%d\n", realans);
	}
	return 0;
}


