#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
int p[100001][17]; // p[v][d] == v������ 2��d��°�� �θ����� ��ȣ 
int level[100001];
vector <int> v[100001];
queue<int> q;
int main(void) {
	int n, m;
	int a, b;
	int temp;
	int next;

	scanf("%d", &n);
	q.push(1);
	level[1] = 1;
	for (int i = 0; i < n - 1; i++) {
		scanf(" %d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}// �Է� for ��
	while (!q.empty()) {
		temp = q.front();
		//printf("temp : %d\n", temp);
		q.pop();
		for (int i = 0; i < v[temp].size(); i++) {
			next = v[temp][i];  //temp���� ����Ǿ� �ִ� �ٸ� ��尡 next
			if (level[next] == 0) { //����� ����� level ==0�̸� 
				q.push(next);
				level[next] = level[temp] + 1; //temp����� level+1�� ����� ���� level
			//	printf("next : %d temp : %d\n", next,temp);
				p[next][0] = temp; // p ó���� �ʱ�ȭ �޴� 
			}
		}
	}// queue����ؼ� level�̶� q [][0]�ʱ�ȭ ���� //level ==depth �̴� level�� ���۰� ==1 
	for (int i = 1; i < 17; i++) {
		for (int j = 1; j <= n; j++) {
			p[j][i] = p[p[j][i - 1]][i - 1];
		}
	} // p�迭 �ʱ�ȭ �ߴ� 


	scanf("%d", &m);
	int temp3;
	int high;
	int low;
	for (int i = 0; i < m; i++) {
		scanf(" %d %d", &a, &b);
		high = level[a];
		low = level[b];
		//	printf("high : %d low : %d\n", a, b);
		if (low > high) {
			temp3 = a;
			a = b;
			b = temp3;
		}// high�� �׻� ũ��
		high = a;
		low = b;
		//	printf("high : %d low : %d\n", high, low);

		for (int j = 16; j >= 0; j--) {
			if (level[low] <= level[p[high][j]]) {
				high = p[high][j];
			}
		}// ���� ���� �ִ°� 

		//printf("���� ���� �� high : %d low : %d\n", high, low);
		int answer = low;
		if (low != high) { //���� ���̰��̴µ� �ΰ��� �ٸ��� �����������Ѵ� 
			for (int j = 16; j >= 0; j--) {
				if (p[low][j] != p[high][j]) {
					//�ٸ�������ϸ� �ű�� �̵��ؾ��Ѵ�.
					low = p[low][j];
					high = p[high][j];
				}
				else {
					answer = p[low][j];
				}
			}//for
			//printf("������ highh : %d low : %d\n", high, low);
		}// if
		printf("%d\n", answer);


	}//�Է¹ް� ����ϴ°� 


	return 0;
}