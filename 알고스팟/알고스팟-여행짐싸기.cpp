#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, w;
struct aa {
	string name;
	int weight;
	int want_num;
	aa(string s1, int n1, int n2) :name(s1), weight(n1), want_num(n2) {

	}
};
vector <aa> v;
vector <string> ans;

int cache[101][1001]; //n번째 물건 선택 시 남은 w경우 최대절박도
//물건이 선택했을 경우 안했을 경우 
int pick(int index,int remain_weight) {//index가 선택했을 경우 안했을 경우 최대 절박도 
	//printf("index : %d remian_weight : %d\n", index, remain_weight);
	
	if (index >= n) {
		return 0;
	}
	int& ret = cache[index][remain_weight];
	if (ret != -1) {
		return ret;
	}//이미 계싼 됫으면 
	//선택 안했을 때 

	ret = pick(index + 1, remain_weight);
	//일단 선택 안했을 때의 ret 값 

	if (remain_weight - v[index].weight >= 0) {
		if (ret > pick(index + 1, remain_weight - v[index].weight) + v[index].want_num) {
		}
		else{
			ret = pick(index + 1, remain_weight - v[index].weight) + v[index].want_num;
		}
	}//선택할 수 있을 때 
	return ret;
}
void which_one_pick(int index, int weight) {
	if (index == n) {
		return ;
	}
	if (pick(index, weight) == pick(index + 1, weight)) {
		which_one_pick(index + 1, weight);
	}// 선택 안했을 경우는 그대로 넘어가고 
	else { //선택했을 경우 
		ans.push_back(v[index].name);
		which_one_pick(index + 1, weight - v[index].weight);
	}
}
int main(void) {
	int C;
	scanf("%d", &C);
	for (int t = 1; t <= C; t++) {
		scanf("%d %d", &n, &w);
		for (int i = 1; i <= n; i++) {
			string s;
			int n1, n2;
			cin >> s >> n1 >> n2;
			v.push_back(aa(s, n1, n2));
		}
		memset(cache, -1, sizeof(cache));
		//vector에 다 넣고 
		printf("%d ",pick(0,w));

		which_one_pick(0, w);

		printf("%d\n", ans.size());
		
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << "\n";
		}
		v.clear();
		ans.clear();
	}
	return 0;
}