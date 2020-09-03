#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n;
int map[11][11];
int peoplenum;
int stairnum;
int stair_info[11]; //����� �ɸ��� �ð� ����
int pick_stair[11]; // ������� � ��� �����ϴ��� 
vector <pair<int, int> > people,stair; // xy��ǥ �����ϱ� ���� 
queue<int> check_stair[11];
vector<int> in_stair[11]; // �� ��� ���� �Ÿ��� ���� �Ǿ� �ִ� 
int ans=987654321;
void calc() {
	for (int i = 0; i < 11; i++) {
		in_stair[i].clear();
	}
	int temp_ans = 0;
	for (int i = 1; i <= peoplenum; i++) {
		int go_stair_index = pick_stair[i];
		int distance = abs(stair[go_stair_index-1].first - people[i-1].first) + abs(stair[go_stair_index-1].second - people[i-1].second);;
		in_stair[go_stair_index].push_back(distance);
	} //�� ��� vector�� �Ÿ�==�����ð� ���� 

	for (int i = 1; i <= stairnum; i++) {
		sort(in_stair[i].begin(), in_stair[i].end());
	}//vecotr ��Ʈ�ϰ� 

	for (int i = 1; i <= stairnum; i++) {
		int stair_idx_size = in_stair[i].size();
		for (int j = 0; j < stair_idx_size; j++) { //�� ��ܺ� queue�� �ɸ��ð� �ֱ�
			printf("i stair : %d size : %d ", i,stair_idx_size);
			if (check_stair[i].size() < 3) {
				check_stair[i].push(stair_info[i] + in_stair[i][j]+1);
				if (temp_ans < stair_info[i] + in_stair[i][j] + 1) {
					temp_ans = stair_info[i] + in_stair[i][j] + 1;
				}
				printf("  1�ִ°� : %d\n", stair_info[i] + in_stair[i][j] + 1);
			} //�������� ���� �� 

			else {
				int front_time = check_stair[i].front(); //������ ������ �ð�
				int come_time = in_stair[i][j];
				if (front_time <= come_time) {
					check_stair[i].pop();
					check_stair[i].push(come_time + stair_info[i] + 1);
					if (temp_ans < come_time + stair_info[i] + 1) {
						temp_ans = come_time + stair_info[i] + 1;
					}
					printf("  2�ִ°� : %d\n", come_time + stair_info[i] + 1);
				} //������ �ð� �� �� �ð� ���� ������ 
				else if(front_time > come_time){
					check_stair[i].pop();
					check_stair[i].push(front_time + stair_info[i]);
					if (temp_ans < front_time + stair_info[i] ) {
						temp_ans = front_time + stair_info[i];
					}
					printf("  3�ִ°� : %d\n", front_time + stair_info[i]);
				}//�����ߴµ��� ���� �������� ���̸� 
				
			}
		}
		int qsize = check_stair[i].size();
		for (int k = 0; k < qsize; k++) {
			check_stair[i].pop(); // queue�ʱ�ȭ �Ѵ��� 
		}
	}
	//printf("temp :%d\n", temp_ans);
	if (ans > temp_ans) {
		ans = temp_ans;
	}
}
void dfs(int index) {
	if (index == peoplenum+1) {
		
		calc();
		for (int i = 1; i <= peoplenum; i++) {
			printf("%d ", pick_stair[i]);
		}printf(" ans : %d \n",ans);
		return;
	}
	for (int i = 1; i <= stairnum; i++) {
		pick_stair[index] = i;
		dfs(index + 1);
	}
}
void clear() {
	people.clear();
	stair.clear();
	peoplenum = 0;
	stairnum = 0;
	
	ans = 987654321;
	for (int i = 0; i < 11; i++) {
		stair_info[i] = 0;
		pick_stair[i] = 0;
	}
}
int main(void) {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d", &n);
		
		for (int x = 1; x <= n; x++) {
			for (int y = 1; y <= n; y++) {
				int temp;
				scanf(" %d", &temp);
				if (temp == 1) {
					people.push_back(make_pair(x, y));
				}
				else if (temp != 0 && temp != 1) {
					stairnum++;
					stair_info[stairnum] = temp;
					stair.push_back(make_pair(x, y));
				}// stair�� ��� 
			}
		}
		peoplenum = people.size();
		dfs(1);

		printf("#%d %d\n", t, ans);
		clear();
	}
	return 0;
}