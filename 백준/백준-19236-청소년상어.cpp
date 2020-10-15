#include<iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int map[4][4];
//int copy_map[4][4];
struct aa {
	int x, y, dir;
	aa(int n1, int n2, int n3) :x(n1), y(n2), dir(n3) {

	}
};
vector<aa> fish[17];
//vector<aa> copy_fish[17];

int go_dir[9][2] = { {0,0},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1} };
void go_fish(int sx, int sy) {
	//	printf("before go fish \n");


	for (int i = 1; i <= 16; i++) { //���� ���ں��� 
		//printf("%d : \n", i);
		int x = fish[i].front().x;
		int y = fish[i].front().y;
		if (x == -1 && y == -1) { continue; }
		int dir = fish[i].front().dir;
		//	printf("x : %d y :%d dir : %d\n", x, y, dir);

		for (int k = dir; k < dir + 9; k++) {
			if (k > 8) { k -= 8; }
			int dx = x + go_dir[k][0];
			int dy = y + go_dir[k][1];
			//	printf("dx  : %d  dy : %d\n", dx, dy);
			if (dx >= 0 && dx < 4 && dy >= 0 && dy < 4) {

				if (!(dx == sx && dy == sy)) { //�� �� �ִٹ� ~ 
					//�� ����� ��ġ�� �ٲ�� �ȴ��� ~ 
					int ch_index = map[dx][dy];
					//printf("check_index : %d \n", ch_index);
					if (ch_index == 0) { //��ĭ�̸� 
						fish[i].front().x = dx;
						fish[i].front().y = dy;
						fish[i].front().dir = k;
						map[x][y] = 0;
						map[dx][dy] = i;
						break;
					}
					//					int ch_x = fish[ch_index].front().x;
					//					int ch_y = fish[ch_index].front().y;
					int ch_dir = fish[ch_index].front().dir;

					map[dx][dy] = i;
					map[x][y] = ch_index;

					fish[i].front().x = dx;
					fish[i].front().y = dy;
					fish[i].front().dir = k;

					fish[ch_index].front().x = x;
					fish[ch_index].front().y = y;
					fish[ch_index].front().dir = ch_dir;
					break;
				}
			}

		}//break �ɸ� // ���� for�� 



	}
}
int temp_ans;
void dfs(int s_x, int s_y, int s_dir, int cnt) {
	temp_ans = max(temp_ans, cnt);
	//printf("dfs : %d %d %d %d\n", s_x, s_y, s_dir, cnt);

	//����� ��ȣ ������ ���� �̵� 
	go_fish(s_x, s_y);


	vector<aa> copy_fish[17];
	int copy_map[4][4];

	//�� ���� ģ���� �ĺ� ���ϱ� 
	int go_sx = s_x;
	int go_sy = s_y;

	for (int x = 1; x <= 16; x++) {
		//printf("%d \n", x);
		copy_fish[x].clear();
		copy_fish[x].push_back(fish[x].front());
	}
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			copy_map[x][y] = map[x][y];
		}
	}

	for (int i = 0; i < 4; i++) { //max 4ĭ 
		go_sx += go_dir[s_dir][0];
		go_sy += go_dir[s_dir][1];
		//	 printf("go_sx : %d go_sy : %d\n", go_sx, go_sy);

		if (go_sx < 0 || go_sx>3 || go_sy < 0 || go_sy>3) {

			break;
		}
		if (map[go_sx][go_sy] == 0) { continue; }

		//��ģ�� �Ա� ~ 
		int eated_index = map[go_sx][go_sy];
		int eated_dir = fish[eated_index].front().dir;
		fish[eated_index].front().x = -1;
		fish[eated_index].front().y = -1;
		//	 printf("eated index : %d eated_dir : %d\n", eated_index,eated_dir);

		map[go_sx][go_sy] = 0;


		dfs(go_sx, go_sy, eated_dir, cnt + eated_index);
		//	 printf("roll back\n");

			 //�ٽ� �ѹ� ~ (map�ȿ� �ִ� index , ����� �̵� �̰͵� �ؾߵǴµ� .... )
		for (int x = 1; x <= 16; x++) {
			if (fish[x].size() != 0) {
				fish[x].clear();
			}
			fish[x].push_back(copy_fish[x].front());
			//copy_fish[x].clear();
		}
		for (int x = 0; x < 4; x++) {
			for (int y = 0; y < 4; y++) {
				map[x][y] = copy_map[x][y];
				//copy_map[x][y] = 0;
			}
		}
		//map[go_sx][go_sy] = eated_index;


	}

	//temp_ans = max(temp_ans, cnt);

	return;


}
int main(void) {
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			int index, dir;
			scanf("%d %d", &index, &dir);
			map[x][y] = index;
			fish[index].push_back(aa(x, y, dir));
		}
	}


	int eated_index = map[0][0];
	map[0][0] = 0;
	fish[eated_index].front().x = -1;
	fish[eated_index].front().y = -1;
	int shark_dir = fish[eated_index].front().dir;
	fish[eated_index].front().dir = 0;
	//	printf("test!");
	dfs(0, 0, shark_dir, eated_index);

	printf("%d\n", temp_ans);
	return 0;
}
