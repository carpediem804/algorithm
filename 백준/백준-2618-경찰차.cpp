#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int n,w;

int cache[1001][1001];
int question[1001][2];
vector <int> ans;
int dist(int a, int b, int a_, int b_) {
	return abs(a - a_) + abs(b - b_);
}
int calc(int recent_a_pick,int recent_b_pick) { //가장 최근에 선택한 문제번호  
	
	if (recent_a_pick >= w || recent_b_pick >= w) {
		return 0;
	}
	
	int& ret = cache[recent_a_pick][recent_b_pick];
	if (ret != -1) {
		return ret;
	}
	ret = 0;

	int next_go_index = max(recent_a_pick, recent_b_pick) + 1;
	//다음에 처리해야할 문제번호 
	int question_x = question[next_go_index][0];
	int question_y = question[next_go_index][1];

	int now_a_x = question[recent_a_pick][0];
	int now_a_y = question[recent_a_pick][1];
	int now_b_x = question[recent_b_pick][0];
	int now_b_y = question[recent_b_pick][1];

	if (recent_a_pick == 0) {
		now_a_x = 1;
		now_a_y = 1;
	}
	if (recent_b_pick == 0) {
		now_b_x = n;
		now_b_y = n;
	}
	int b_go = calc(recent_a_pick, next_go_index) + dist(now_b_x, now_b_y, question_x, question_y); //b 차가 다음문제를 해결하러 갔을 때
	int a_go = calc(next_go_index, recent_b_pick) + dist(now_a_x,now_a_y,question_x,question_y); // a차가 다음문제를 해결하러 갔을 때 
	ret = min(a_go, b_go);
	return ret;

}
void tracking(int recent_a_pick, int recent_b_pick) {
	if (recent_a_pick == w || recent_b_pick == w) {
		return;
	}

	int next_go = max(recent_a_pick, recent_b_pick) + 1;
	int question_x = question[next_go][0];
	int question_y = question[next_go][1];

	int now_a_x = question[recent_a_pick][0];
	int now_a_y = question[recent_a_pick][1];
	int now_b_x = question[recent_b_pick][0];
	int now_b_y = question[recent_b_pick][1];

	if (recent_a_pick == 0) {
		now_a_x = 1;
		now_a_y = 1;
	}
	if (recent_b_pick == 0) {
		now_b_x = n;
		now_b_y = n;
	}
	int a_pick = cache[next_go][recent_b_pick] + dist(now_a_x, now_a_y, question_x, question_y);
	int b_pick = cache[recent_a_pick][next_go] + dist(now_b_x, now_b_y, question_x, question_y);
	//printf("(%d , %d) a_pick : %d b_pick : %d\n", recent_a_pick, recent_b_pick, a_pick, b_pick);
	if ( a_pick > b_pick ){
		ans.push_back(2);
		tracking(recent_a_pick, next_go);
	} //b가 처리하는게 더 적다면 !!
	else {
		ans.push_back(1);
		
		tracking(next_go, recent_b_pick);
	}

}

int main(void) {
	scanf("%d", &n);
	scanf("%d", &w);
	for (int i = 1; i <= w; i++) {
		int temp_x, temp_y;
		scanf("%d %d", &temp_x, &temp_y);
		question[i][0] = temp_x;
		question[i][1] = temp_y;
	}
	memset(cache, -1, sizeof(cache));

	printf("%d\n", calc(0,0));

	tracking(0, 0);
	for (int i = 0; i <ans.size(); i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}