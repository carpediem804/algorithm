#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>

using namespace std;
int n, d, p;
double cache[51][101];
int map[50][50];
vector <int> connect_town[50]; //0���������� 49�� �������� 
vector <int> want_to_calc;
double calc(int town_index, int done_day) {
	//���� ���
	if (done_day == 1) { //�����ҿ��� Ż�� �� �� 
		int connect_size = connect_town[p].size();
		if (map[p][town_index] == 1) { //����Ǿ�������
			return (double)1 / (double)connect_size;
		}
		return 0;
	}

	double& ret = cache[town_index][done_day];
	if (ret != -1) {
		return ret;
	}
	ret = 0;
	for (int i = 0; i < connect_town[town_index].size(); i++) {
		int previous_town = connect_town[town_index][i];
		double add = calc(previous_town, done_day - 1);
		//previous_town���� ���� town_index�� �� Ȯ���� ���ؾ��Ѵ� 
		double connect_size = connect_town[previous_town].size();
		add *= (1 / connect_size);
		ret += add;
	}
	return ret;

}
int main(void) {
	int C;
	scanf("%d", &C);
	for (int t = 1; t <= C; t++) {
		scanf("%d %d %d", &n, &d, &p);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= d; j++) {
				cache[i][j] = -1; //ĳ�� �ʱ�ȭ 
			}
		}
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) {
				int temp;
				scanf("%d", &temp);
				map[x][y] = temp;
				if (temp == 1) {
					connect_town[x].push_back(y);
					//connect_town[y].push_back(x);
				}
			}
		} //map�׸��� 
		int T;
		scanf("%d", &T);
		for (int i = 0; i < T; i++) {
			int show_town;
			scanf("%d", &show_town);
			want_to_calc.push_back(show_town);
		}
		for (int i = 0; i < want_to_calc.size(); i++) {
			printf("%.8f ",calc(want_to_calc[i], d));
		}printf("\n");

		
		
		want_to_calc.clear();
		for (int i = 0; i < n; i++) {
			connect_town[i].clear();
		}
	}
	return 0;
}