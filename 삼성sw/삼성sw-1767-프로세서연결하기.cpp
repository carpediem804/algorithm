#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
int map[13][13];
int visit[13];
vector <pair<int, int> > v;
int n;
int corenum;
int linenum;
int reallinenum=987654321;
bool check(int x, int y, int dir) { //x,y������ dir �������� ������ ���� �Ҽ� �ֳ� ���� üũ �ϴ� �Լ� ���� �����Ҽ� ������ �� ���� 1�� ä��� ~ 
	if (dir == 1) { //���� ���°��
		for (int i = x-1; i >= 1; i--) {
			if (map[i][y] == 1) {
				return false;
			}
		}
		for (int i = x-1; i >= 1; i--) {
			map[i][y] = 1;
		}
	}
	else if (dir == 2) { //�Ʒ��� ���°��
		for (int i = x+1; i <= n; i++) {
			if (map[i][y] == 1) {
				return false;
			}
		}
		for (int i = x+1; i <= n; i++) {
			map[i][y] = 1;
		}
	}
	else if (dir == 3) {//������
		for (int i = y+1; i <= n; i++) {
			if (map[x][i] == 1) {
				return false;
			}
		}
		for (int i = y+1; i <= n; i++) {
			map[x][i] = 1;
		}
	}
	else if (dir == 4) {//����
		for (int i = y-1; i >= 1; i--) {
			if (map[x][i] == 1) {
				return false;
			}
		}
		for (int i = y-1; i >= 1; i--) {
			map[x][i] = 1;
		}
	}

	return true;
}
void rollback(int x, int y, int dir) { //1�� map�� ĥ�ߴ� ���� �ٽ� 0���� �ٲٴ� �Լ� 
	if (dir == 1) { //���� ���°��
		for (int i = x-1; i >= 1; i--) {
			map[i][y] = 0;
		}
	}
	else if (dir == 2) { //�Ʒ��� ���°��
		for (int i = x+1; i <= n; i++) {
			map[i][y] = 0;
		}
	}
	else if (dir == 3) {//������
		for (int i = y+1; i <= n; i++) {
			map[x][i] = 0;
		}
	}
	else if (dir == 4) {//����
		for (int i = y-1; i >= 1; i--) {
			map[x][i] = 0;
		}
	}
}
void calc() {// ������ ���� ���� �Լ� ~ 
	linenum = 0;
	for (int i = 1; i <= n; i++) {
		if (visit[i] == 1) { //���ʹ���
			int x = v[i-1].first;
			linenum += (x - 1);
		} 
		else if (visit[i] == 2) { //�Ʒ��� ����
			linenum += (n - v[i-1].first);
		}
		else if (visit[i] == 3) { //�����ʹ���
			linenum += (n - v[i-1].second);
		}
		else if (visit[i] == 4) { //���ʹ���
			linenum += (v[i-1].second - 1);
		}
	}
}
void dfs(int index, int dir) { //1���� �� core�� ���� ���� ������ ����ֱ�

	if (index == v.size()+1) { //��� core���� ���� ���� or �������� ����ִ� �� �����ٸ� ����Ѵ�
		int tempans = 0;
		for (int i = 1; i <= v.size(); i++) {
			if (visit[i] != 0) {
				tempans++;
			}
		}//������ ����� core�� ������ ���� 
		if (corenum == tempans) { //������ ������ core�� ���� �Ȱ����� 
			calc(); //���� ���� �����ְ� 
			if (reallinenum >= linenum) { //�����ɷ� �ٲ۴�	
				reallinenum = linenum;
			}
		}
		else if (corenum < tempans) { //������ �´� core�� �������� ���� �� core�� ������ �� ������ corenu�� ���� ���� update
			corenum = tempans;
			calc();
			reallinenum = linenum;
		}
		return;
	}//��� ~ 
	int x = v[index-1].first; //vector�� index-1~~ 
	int y = v[index-1].second;
	if ((x == 1) || (x == n) || (y == 1) || (y == n)) { //�����̶�� visit[index]=-1�� �ְ� �ٽ� ����~ 
		visit[index] = -1;
		dfs(index + 1, -1);
		
		return;
	}
	
	if (check(x, y, 1)) { //���� �������� ���� ���� �� �� �ֵ��� 
		visit[index] = 1; //visit�� 1��ǥ���ϰ� 
		dfs(index + 1, 1); //dfs����~ 
		visit[index] = 0; //dfs�����Ŀ� visit�迭�� 0���� �ʱ�ȭ�ϰ�
		rollback(x, y, 1); //map�� 1�� üũ�ߴ� ���� �ٽ� rollback��Ų��.
	}
	if (check(x, y, 2)) { //�Ʒ����� ~ 
		visit[index] = 2;
		dfs(index + 1, 2);
		visit[index] = 0;
		rollback(x, y, 2);
	}
	if (check(x, y, 3)) { //�����ʹ���
		visit[index] = 3;
		dfs(index + 1, 3);
		visit[index] = 0;
		rollback(x, y, 3);
	}
	if (check(x, y, 4)) { //���ʹ��� ~~ 
		visit[index] = 4;
		dfs(index + 1, 4);
		visit[index] = 0;
		rollback(x, y, 4);
	}
	//���� ���ϴ� ��쵵 üũ�ؾ��Ѵ� !!! 
	dfs(index + 1, 0);
}
void clear() { //testcase�Ѻ� �Ҷ����� map�� vector, vist�迭, ���������� �ʱ�ȭ 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] = 0;
		}
	}
	v.clear();
	for (int i = 1; i <= n; i++) {
		visit[i] = 0;
	}
	corenum =0;
	linenum=0;
	reallinenum = 987654321;
}
int main(void) {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf(" %d", &n);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int temp;
				scanf(" %d", &temp);
				if (temp == 1) {
					v.push_back(make_pair(i, j));
				}
				map[i][j] = temp;
			}
		}//map�� �� �־��� 
		dfs(1, 1);
		printf("#%d %d\n", t, reallinenum);
		clear();

	}
	return 0;
}