#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> ans_repair[10];
vector <int> ans_recept[10];
int reception_dest[10]; //정보저장
int repair_dest[10]; //정보저장

int doing_reception[10]; //지금 처리중인 사람의 index 저장 
int doing_repair[10];

int check_reception[10];// 볏는지 안비엇는지 완료 시간이 저장되어 있음 
int check_repair[10];

queue<pair<int, int>> visit;
queue<int > wait_reception;
queue<int> wait_repair;

int n, m, k, a, b;//n=recptionnum m = reqpair num

void clear() {
	while (visit.size() != 0) {
		visit.pop();
	}
	while (wait_reception.size() != 0) {
		wait_reception.pop();
	}
	while (wait_repair.size() != 0) {
		wait_repair.pop();
	}
	for (int i = 0; i <= 9; i++) {
		ans_repair[i].clear();
		ans_recept[i].clear();
	}

	for (int i = 0; i <= 9; i++) {
		reception_dest[i] = 0;
		repair_dest[i] = 0;
		doing_reception[i] = 0;
		doing_repair[i] = 0;
		check_reception[i] = 0;
		check_repair[i] = 0;
	}
}
int main(void) {
	int T;
	scanf(" %d", &T);
	for (int t = 1; t <= T; t++) {
		scanf(" %d %d %d %d %d", &n, &m, &k, &a, &b);
		for (int i = 1; i <= n; i++) {
			scanf(" %d", &reception_dest[i]);
		}
		for (int i = 1; i <= m; i++) {
			scanf(" %d", &repair_dest[i]);
		}
		for (int i = 1; i <= k; i++) {
			int temp;
			scanf(" %d", &temp);
			visit.push(make_pair(i, temp));
		}
		int time = 0;
		int outnum=0;
		while (1) {
			for (int i = 1; i <= m; i++) {
				if (check_repair[i] == time && check_repair[i] != 0) {
					outnum += 1;
				}
			}
			if (outnum == k) {
				break;
			}
			while (visit.size() != 0 && visit.front().second == time) {
				wait_reception.push(visit.front().first);
				visit.pop();
			}
			for (int i = 1; i <= n; i++) {
				if (check_reception[i] == time) { //reception의 완료시간이 지금시간일 때 
					if (doing_reception[i] != 0) { //만약 그 안의 사람ㅇ index가 0이면 wait_repair큐에 넣지않는다 
						wait_repair.push(doing_reception[i]); //repair대기 큐에 현재 i번째 receoption이 처리한 사람 index넣기
					}
				}
			}

			if (wait_reception.size() != 0) { //wait_reception의 큐에 사람이 대기한다면 
				for (int i = 1; i <= n; i++) {
					if (wait_reception.size() == 0) {
						break;
					}//만약 기다리는 사람을 다 넣어서 없을 때면 그냥 break
					if (check_reception[i] <= time) { //만약 check안의 완료시간이 현재시간이랑 같거나 적다면 그 reception은 사용할 수 있음으로
						check_reception[i] = time + reception_dest[i]; //시간넣고 

						doing_reception[i] = wait_reception.front(); //현재 기다리는 사람의 index를 doing에 넣기
						ans_recept[i].push_back(wait_reception.front()); //
						wait_reception.pop(); //wait_reception의 맨앞 값을 뺀다 
					}//들어갈수 있을 때 
				}
			}//기다리는 친구 있을 때 
			
			if (wait_repair.size() != 0) { //repair를 기다리는 사람이 있을 때 
				for (int i = 1; i <= m; i++) {
					if (wait_repair.size() == 0) {
						break;
					}
					if (check_repair[i] <= time) { //repair 완료시간이 현재 시간보다 적거나 같으면 사람을 넣을수 있다
						check_repair[i] = time + repair_dest[i]; // check_repair에 걸릴 시간을 넣는다 
						ans_repair[i].push_back(wait_repair.front());
						wait_repair.pop();
					}
				}
			}			
			time++;
		}//while 끝
		int realans = 0;
		//두개안에 포함되어 있는 친구들을 더해야한다 
		for (int i = 0; i < ans_recept[a].size(); i++) {
			if (ans_repair[b].end() != find(ans_repair[b].begin(), ans_repair[b].end(), ans_recept[a][i])) {
				realans += ans_recept[a][i];
			}
		}
		if (realans == 0) { realans = -1; }
	//	printf("time : %d\n", time);
		printf("#%d %d\n", t, realans);
		clear();

	}//testcase;

	return 0;
}