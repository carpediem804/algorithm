#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
map<int, int> nerds;
bool is_nerd(int x, int y) {
	map<int, int> ::iterator it = nerds.lower_bound(x);
	//x���� �ٷ�ū �� ã��

	if(it == nerds.end()){//�׷����� ������ 
		return false; //��������� ���� 
	}
	if (y < it->second) { //y�� �� ���� �� 
		return true; //�� nerd�̴��� ~ 
	}
	return false;
}
void remove_nerds(int x, int y) {
	map<int, int> ::iterator it = nerds.lower_bound(x);
	//x���� ū�� �� ���� ���� 
	if (it == nerds.begin()) {//x,y���� ���ʿ� �ִ� ���̾���
		return; //�׳� �����°�~ 
	}
	it--;//���ʿ� �ִ� ���� �ֵ��� --�Ѱ� �ű� ����Ű�°�
	while (1) {
		if (it->second > y) {
			break;
		}//������� 
		
		if (it == nerds.begin()) { //�������� ������ 
			nerds.erase(it);
			break;
		}//�������2
		else { //�ִٸ� 
			map<int, int >::iterator temp_it = it;
			temp_it--;
			nerds.erase(it);
			it = temp_it;
		}
		
	}
}
int main(void) {
	int C;
	scanf("%d",&C);
	int answer = 0;
	for (int t = 1; t <= C; t++) {
		int n;
		scanf("%d", &n);
		answer = 0;
		for (int i = 0; i < n; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			if (is_nerd(x, y)) { //�ʵ�� 
				answer += nerds.size();
				continue;
			}
			remove_nerds(x, y);
			nerds[x] = y;
			answer += nerds.size();
		}
		printf("%d\n", answer);
		nerds.clear();
	}
	return 0;
}