#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int map[801][801];
int dist1[801];//������ �湮�ؾ��ϴ� ���������� ��������� �Ÿ�����
int n, e;
struct aa {
	int startindex;
	int cost;
	int previusindex;
	aa(int n1, int n2, int n3) :startindex(n1), cost(n2), previusindex(n3) {

	}
};
struct cmp {
	bool operator ()(aa a1, aa a2) {
		return a1.cost > a2.cost;
	}
};
priority_queue <aa, vector<aa>, cmp> pq;
void find() {
	while (pq.size() != 0) {
		int startnode = pq.top().startindex;
		int cost = pq.top().cost;
		int previousnode = pq.top().previusindex;
		pq.pop();
		if (cost <= dist1[startnode]) { //������ cost���� ���ų� ��������
			for (int i = 1; i <= n; i++) {
				if (map[startnode][i] != 0 ) {//����� ���� ������
					if (dist1[i] > dist1[startnode] + map[startnode][i]) { //���� �ִ� ������ ���� ���� �� �� ������ �����ؾ��ϴϱ� �װ� pq�� �ִ´� 
						dist1[i] = min(dist1[i], dist1[startnode] + map[startnode][i]);
						pq.push(aa(i, dist1[i], startnode));
					}
				}
			}
		}
	}
}
void clear() {
	for (int i = 1; i <= n; i++) {
		dist1[i] = 1000*800;
	}
}
int main(void) {
	scanf("%d %d", &n, &e);
	for (int i = 0; i < e; i++) {
		int x, y, c;
		scanf("%d %d %d", &x, &y, &c);
		map[x][y] = c;
		map[y][x] = c;
	}
	int mustgo1, mustgo2;
	scanf("%d %d", &mustgo1, &mustgo2);
	
	for (int i = 1; i <= n; i++) {
		dist1[i] = 1000 * 800;
	} // dist1 �迭 �ִ밪���� �ʱ�ȭ ~ 

	pq.push(aa(mustgo1, 0, mustgo1));//������ ť�� �־��ֱ�
	dist1[mustgo1] = 0; //�ڱ� �ڽ��� ���� 0���� �ٲٰ� 
	find(); // mustgo1������ ��� �������� �ִܰŸ� ���ϴ� �Լ� 
	
	
	int must1_to_one = dist1[1]; //mustgo1���� 1�������� �ִܰŸ� 
	int must1_to_must2 = dist1[mustgo2]; //mustgo1���� mustgo2�������� �ִܰŸ�
	int must1_to_last = dist1[n];  //mustgo1��忡�� ������ �������� �ִܰŸ� 
	
	clear(); // dist1�迭 �ʱ�ȭ pq�� �̹� size�� 0�̴�~
	pq.push(aa(mustgo2, 0, mustgo2));//mustgo2������ ��� �������� �ִܰŸ�
	dist1[mustgo2] = 0; //�ڱ��ڽ��� �Ÿ��� 0�̴�
	find(); //mustgo2������ ��� �������� �ִܰŸ� ���ϴ� �Լ� 
	
	int must2_to_one = dist1[1]; //mustgo2���� ��� 1������ �ִܰŸ�
	int must2_to_must1 = dist1[mustgo1]; //mustgo2���� mustgo1�������� �ִܰŸ�
	int must2_to_last = dist1[n]; // mustgo2���� ������ �������� �ִܰŸ�
	
	int ans = min(must1_to_one + must1_to_must2 + must2_to_last, must2_to_one + must2_to_must1 + must1_to_last);
	//�� �ΰ��� ��찡 �ִ� : 
	// 1. must1��忡�� 1�� ������ �ִܰŸ� +must1��忡�� must2��� ���� �ִܰŸ� +must2��忡�� last������ �ִܰŸ� 
	// 2. must2��忡�� 1�� ������ �ִܰŸ� + must2��忡�� must1������ �ִܰŸ� +must1��忡�� last ��� ���� �ִܰŸ� 
	if (ans >= 800 * 1000) {
		printf("-1\n");
	}
	else { printf("%d\n", ans); }
	return 0;
}