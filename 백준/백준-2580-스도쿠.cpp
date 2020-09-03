#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
vector <pair<int, int>> v;// 0���� ��ǥ ���� 
int map[10][10]; //map �׸��°� 
int zerosize; // 0������ ���� 
int check = 0; // 1�ΰ�� �߰��� ������ ��� 3= �Ϻ��ϰ� ���� ��� 
bool rowcheck(int x, int y, int num) { //����üũ
	for (int i = 1; i <= 9; i++) {
		if (map[x][i] == num) {
			return false;
		}
	}
	return true;
}
bool columncheck(int x, int y, int num) {
	for (int i = 1; i <= 9; i++) {
		if (map[i][y] == num) {
			return false;
		}
	}
	return true;
}
bool boxcheck(int x, int y, int num) {
	int dx=0;
	if (x / 3 == 0 || x == 3) { //x�� 1,2,3�ΰ�� 
		dx = 3;
	}
	else if (x / 3 == 1 || x == 6) {//x�� 4,5,6�ΰ��
		dx = 6;
	}
	else { dx = 9; } //x�� 789�ΰ��
	int dy=0;
	if (y / 3 == 0 || y == 3) { //y�� 123�ΰ��
		dy = 3;
	}
	else if (y / 3 == 1 || y == 6) {//y�� 456�ΰ��
		dy = 6;
	}
	else {//y�� 789�ΰ��
		dy = 9;
	}
	for (int i = dx - 2; i <= dx; i++) {
		for (int j = dy - 2; j <= dy; j++) {
			if (map[i][j] == num) {
				return false;
			}
		}
	}
	return true;
}
void dfs(int cnt) {
	if (cnt == zerosize) { check = 3;  return; } //��� 0������ �� ä�m���� check �� 3���� �ٲٰ� return ;
	int x = v[cnt].first;
	int y = v[cnt].second;
	for (int i = 1; i <= 9; i++) {
		if (rowcheck(x, y, i) && columncheck(x, y, i) && boxcheck(x, y, i)) {//���� �ִ� ���ڶ�� 
			check = 0; //�̹��� �ߵȴٰ� check �� 0���� �ٲ� ! 
			map[x][y] = i; //map�� �� ���� �ְ� 
			dfs(cnt + 1);//������첨����
			if (check == 3) { return; } //check ==3 �� �� ������ ��� �ٷ� return ��Ų�� 
			if (check == 1) { map[x][y] = 0;  } //�ȵǴ� ��� 0���� �ٽ� �ٲ۴� }
		}//�� ��� �� �ȴٸ� 
	}
	if (map[x][y] == 0) {
		check = 1;
	}//�ٵ��Ҵµ� �ȵǴ� ���~ 
	
}
int main(void) {
	for (int x = 1; x <= 9; x++) {
		for (int y = 1; y <= 9; y++) {
			int temp;
			scanf(" %d", &temp);
			map[x][y] = temp;
			if (temp == 0) {
				v.push_back(make_pair(x, y));
			}//��ĭ�� ��� v�� �� �ֱ� ~ 
		}
	}// map�����ߴ� 
	zerosize = v.size();//0�� ���� 
	dfs(0);
	for (int x = 1; x <= 9; x++) {
		for (int y = 1; y <= 9; y++) {
			printf("%d ", map[x][y]);
		}printf("\n");
	}
	return 0;
}