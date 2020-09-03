#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int n, m, t;
vector<int> v[52];
struct aa {
	int x, dir, k;
	aa(int n1, int n2, int n3) : x(n1), dir(n2), k(n3) {

	}
};
int check = 0;
void rotating(int index, int dir, int k) {
//	printf("%d %d %d\n", index, dir, k);
	if (dir == 0) {//�ð���� ȸ�� 
		vector <int> temp_v;
		temp_v = v[index];
		for (int i = 0; i < v[index].size(); i++) {
			int next_index = i + k;
			
			if (next_index >= v[index].size()) {
				next_index -= v[index].size();
			}
	//		printf("next _ index : %d\n", next_index);
			temp_v[next_index] = v[index][i];
		}
		v[index] = temp_v;
	}
	else { //�ݽð� ���� ȸ�� 
		vector <int> temp_v;
		temp_v = v[index];
		for (int i = 0; i < v[index].size(); i++) {
			int next_index = i - k;
			if (next_index < 0) {
				next_index += v[index].size();
			}
			temp_v[next_index] = v[index][i];
		}
		v[index] = temp_v;
	}
}
void find_same_num() {
	vector <pair<int, int>> del_v;
	int sum = 0;
	int num = 0;
	int check = 0;
	int real_check = 0;
	for (int i = 1; i <= n; i++) { //n��° ���Ǳ��� �ؾ���
		for (int j = 0; j < v[i].size(); j++) { //�� ������ ���� �� ã��
			check = 0;
		//	printf("i:%d j : %d    %d\n", i,j,v[i][j]);
			if (v[i][j] == -1) {
				continue;
			}
			if (j == v[i].size()-1  ) {
				if(v[i][j] == v[i][0]){
					check = 1;
					del_v.push_back(make_pair(i, 0));
				}
			}
			else {
				if (v[i][j] == v[i][j + 1]) {
					check = 1;
					del_v.push_back(make_pair(i, j + 1));
				}
			}
			
			if (j==0) {
				if (v[i][j] == v[i][v[i].size() - 1]) {
					check = 1;
					del_v.push_back(make_pair(i, v[i].size()-1));
				}
			}
			else {
				if (v[i][j] == v[i][j - 1]) {
					check = 1;
					del_v.push_back(make_pair(i, j - 1));
				}
			}
			
			if (i == n) {

			}
			else {
				if (v[i][j] == v[i + 1][j]) {
					check = 1;
					del_v.push_back(make_pair(i + 1, j));
				}
			}
			
			if (i == 1 ) {
				
			}
			else {
				if (v[i][j] == v[i - 1][j]) {
					check = 1;
					del_v.push_back(make_pair(i - 1, j));
				}
			}
			//printf("check = %d\n", check);
			if (check == 0 || del_v.size()==0) {
				sum += v[i][j];
				num++;
			}//��ġ�°Ծ�����
			if(check==1) {
		//		printf("in %d %d\n", i, j);
				del_v.push_back(make_pair(i, j));
			}
		}
	}
	for (int i = 0; i < del_v.size(); i++) {
		v[del_v[i].first][del_v[i].second] = -1;
	}
	
	//printf("6666\n");

	if (del_v.size() == 0) { //��¥ �ƹ��͵� �Ȱ�ģ�ٸ� 
		float mid_num = ((float)sum / (float)num);
		//printf("sum : %d num : %d mid : %f\n", sum, num, mid_num);
		for (int i = 1; i <= n; i++) { //n��° ���Ǳ��� �ؾ���
			for (int j = 0; j < v[i].size(); j++) {
				//printf("%d ", v[i][j]);
				if (v[i][j] == -1) {
					continue;
				}
				if (float(v[i][j]) > mid_num) {
					v[i][j] -= 1;
				}
				else if(float(v[i][j]) < mid_num){
					v[i][j] += 1;
				}
			}
			//printf("\n");
		}
	}
	del_v.clear();
}
int main(void) {
	scanf("%d %d %d", &n, &m, &t);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int temp;
			scanf("%d", &temp);
			v[i].push_back(temp);
		}
	}
	//������ ���� ���ڸ� ���Ϳ� �� ����
	for (int i = 0; i < t; i++) {
		int x, dir,k;
		scanf("%d %d %d", &x, &dir, &k);
		for (int j = 1; j <= n; j++) {
			if (j%x == 0) {
				rotating(j, dir, k);
			}
		}//������� ȸ�� ��Ų��!! 
		//printf("rotatin ���� ��\n");
		//������ �� ã�� �ؾߵ� 
		
		find_same_num();

	}
	int ans = 0;
	for (int i = 1; i <= n; i++) { //n��° ���Ǳ��� �ؾ���
		for (int j = 0; j < v[i].size(); j++) {
			//printf("%d ", v[i][j]);
			if (v[i][j] != -1) {
				ans += v[i][j];
			}
		}
		//printf("\n");
	}
	printf("%d\n", ans);

}