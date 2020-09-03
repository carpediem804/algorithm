#include<iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct aa {
	int from;
	int to;
	int cost;
	aa(int n1, int n2, int n3) :from(n1), to(n2), cost(n3) {

	}
};
struct cmp {
	bool operator ()(aa a1, aa a2) {
		return a1.cost > a2.cost;
	}
};
priority_queue <aa, vector<aa>, cmp> pq;
vector <pair<int, int> > v[2001]; //�ǳθ� �����ϴ� vector
vector<int> hubo,ans;
int n, m, t;
int s, g, h; //g<->h�� ������ �����ߵȴ�
int a, b, d;
int dist[2001];// �Ÿ�����迭
int visit_candidate_num[2001];//�� �������ϴ� �ǳθ� �������� üũ�迭
void gogo() {
	while (pq.size() != 0) {
		int from = pq.top().from; //���� ��
		int to = pq.top().to; //���� ��
		int cost = pq.top().cost; //from->to������ cost
		pq.pop();
		if (dist[to] < dist[from] + cost) {
			continue;
		}//������ �ִ� ���� �� �۴ٸ� �� �ʿ䵵 ������ ~ 
		else {
			int check = 0;
			if (dist[to] == dist[from] + cost) { //to���� �ּҰŶ�� ���ݰ��� �Ÿ��� ������ 
				if (visit_candidate_num[to] == 1) {// ���ݰ��� ��ο� �����߸� �ϴ� ���� ���ԵǾ� �ִٸ� 
					check = 1;
				}
			}
			if (check != 1) {
				visit_candidate_num[to] = visit_candidate_num[from];
			}
			dist[to] = dist[from] + cost;//to���� dist�� �߰��ϰ� !
			if ((to == g && from == h) || (to == h && from == g)){
				visit_candidate_num[to] = 1;
			}
			int vtosize = v[to].size();
			for (int j = 0; j<vtosize; j++) { //to���� �̾��� ��ε�
				int connect_to = v[to][j].first;
				int connect_to_cost = v[to][j].second;
				if (dist[connect_to] >= dist[to] + connect_to_cost) {
					//����� ��(to)�� ����� ��(connect_to)�� dist������ ���� ���� ���� �� �۰ų� ���� ��
					pq.push(aa(to, connect_to, connect_to_cost));
				}
			}//to���� ����� �ٸ� ������ ť�� �ִ´� 
			
		}
	}
}
void clear() {
	hubo.clear();
	ans.clear();
	while (pq.size() != 0) {
		pq.pop();
	}
	for (int i = 0; i <= 2000; i++) {
		v[i].clear();
		visit_candidate_num[i] = 0;
		dist[i] = 1000 * 2000;
	}
}
int main(void) {
	int T;
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++) {
		scanf("%d %d %d", &n, &m, &t);
		scanf("%d %d %d", &s, &g, &h);
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &d);
			v[a].push_back(make_pair(b, d));
			v[b].push_back(make_pair(a, d));
		}
		for (int i = 0; i < t; i++) {
			int x;
			scanf(" %d", &x);
			hubo.push_back(x);
		}
		for (int i = 1; i <= 2000; i++) {
			dist[i] = 1000 * 2000; 
		} //dist�迭 �ʱ�ȭ 
		pq.push(aa(s, s, 0));//�������� s��
		dist[s] = 0;
		gogo();

		int hubosize = hubo.size();
		for (int i = 0; i < hubosize; i++) {
			if (visit_candidate_num[hubo[i]] == 1) {
				ans.push_back(hubo[i]);
			}
		}
		sort(ans.begin(), ans.end());
		int anssize = ans.size();
		for (int i = 0; i < anssize; i++) {
			printf("%d ", ans[i]);
		} //printf("\n");
		clear();
	}
	return 0;
}