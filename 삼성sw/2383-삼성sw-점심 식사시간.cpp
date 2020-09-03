#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n;
int map[11][11];
int peoplenum;
int stairnum;
int stair_info[11]; //계단이 걸리는 시간 저장
int pick_stair[11]; // 사람들이 어떤 계단 선택하는지 
vector <pair<int, int> > people,stair; // xy좌표 저장하기 위해 
queue<int> check_stair[11];
vector<int> in_stair[11]; // 각 계딴 도착 거리가 저장 되어 있다 
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
	} //각 계단 vector에 거리==도착시간 저장 

	for (int i = 1; i <= stairnum; i++) {
		sort(in_stair[i].begin(), in_stair[i].end());
	}//vecotr 소트하고 

	for (int i = 1; i <= stairnum; i++) {
		int stair_idx_size = in_stair[i].size();
		for (int j = 0; j < stair_idx_size; j++) { //각 계단별 queue에 걸리시간 넣기
			printf("i stair : %d size : %d ", i,stair_idx_size);
			if (check_stair[i].size() < 3) {
				check_stair[i].push(stair_info[i] + in_stair[i][j]+1);
				if (temp_ans < stair_info[i] + in_stair[i][j] + 1) {
					temp_ans = stair_info[i] + in_stair[i][j] + 1;
				}
				printf("  1넣는값 : %d\n", stair_info[i] + in_stair[i][j] + 1);
			} //내려갈수 있을 때 

			else {
				int front_time = check_stair[i].front(); //완전히 내려간 시간
				int come_time = in_stair[i][j];
				if (front_time <= come_time) {
					check_stair[i].pop();
					check_stair[i].push(come_time + stair_info[i] + 1);
					if (temp_ans < come_time + stair_info[i] + 1) {
						temp_ans = come_time + stair_info[i] + 1;
					}
					printf("  2넣는값 : %d\n", come_time + stair_info[i] + 1);
				} //내려간 시간 이 온 시간 보다 작으면 
				else if(front_time > come_time){
					check_stair[i].pop();
					check_stair[i].push(front_time + stair_info[i]);
					if (temp_ans < front_time + stair_info[i] ) {
						temp_ans = front_time + stair_info[i];
					}
					printf("  3넣는값 : %d\n", front_time + stair_info[i]);
				}//도착했는데도 아직 내려가는 중이면 
				
			}
		}
		int qsize = check_stair[i].size();
		for (int k = 0; k < qsize; k++) {
			check_stair[i].pop(); // queue초기화 한다잉 
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
				}// stair인 경우 
			}
		}
		peoplenum = people.size();
		dfs(1);

		printf("#%d %d\n", t, ans);
		clear();
	}
	return 0;
}