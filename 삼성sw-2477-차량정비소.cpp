#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> ans_repair[10];
vector <int> ans_recept[10];
int reception_dest[10]; //��������
int repair_dest[10]; //��������

int doing_reception[10]; //���� ó������ ����� index ���� 
int doing_repair[10];

int check_reception[10];// ������ �Ⱥ������ �Ϸ� �ð��� ����Ǿ� ���� 
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
				if (check_reception[i] == time) { //reception�� �Ϸ�ð��� ���ݽð��� �� 
					if (doing_reception[i] != 0) { //���� �� ���� ����� index�� 0�̸� wait_repairť�� �����ʴ´� 
						wait_repair.push(doing_reception[i]); //repair��� ť�� ���� i��° receoption�� ó���� ��� index�ֱ�
					}
				}
			}

			if (wait_reception.size() != 0) { //wait_reception�� ť�� ����� ����Ѵٸ� 
				for (int i = 1; i <= n; i++) {
					if (wait_reception.size() == 0) {
						break;
					}//���� ��ٸ��� ����� �� �־ ���� ���� �׳� break
					if (check_reception[i] <= time) { //���� check���� �Ϸ�ð��� ����ð��̶� ���ų� ���ٸ� �� reception�� ����� �� ��������
						check_reception[i] = time + reception_dest[i]; //�ð��ְ� 

						doing_reception[i] = wait_reception.front(); //���� ��ٸ��� ����� index�� doing�� �ֱ�
						ans_recept[i].push_back(wait_reception.front()); //
						wait_reception.pop(); //wait_reception�� �Ǿ� ���� ���� 
					}//���� ���� �� 
				}
			}//��ٸ��� ģ�� ���� �� 
			
			if (wait_repair.size() != 0) { //repair�� ��ٸ��� ����� ���� �� 
				for (int i = 1; i <= m; i++) {
					if (wait_repair.size() == 0) {
						break;
					}
					if (check_repair[i] <= time) { //repair �Ϸ�ð��� ���� �ð����� ���ų� ������ ����� ������ �ִ�
						check_repair[i] = time + repair_dest[i]; // check_repair�� �ɸ� �ð��� �ִ´� 
						ans_repair[i].push_back(wait_repair.front());
						wait_repair.pop();
					}
				}
			}			
			time++;
		}//while ��
		int realans = 0;
		//�ΰ��ȿ� ���ԵǾ� �ִ� ģ������ ���ؾ��Ѵ� 
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