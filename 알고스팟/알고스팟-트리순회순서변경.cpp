#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
void post_order(vector<int>& pre_order, vector<int>& in_order) {

	if (pre_order.size() == 0) { return; }
	int root = pre_order[0];
	int left_size = find(in_order.begin(), in_order.end(), root) - in_order.begin();
	int right_size = in_order.size() - left_size - 1;
	//printf("root  : %d left_size : %d right_size : %d n : %d\n", root, left_size, right_size, in_order.size());
	vector<int> L_pre_order = vector<int>(pre_order.begin() + 1, pre_order.begin() + left_size + 1);
	vector<int> L_in_order = vector<int>(in_order.begin(), in_order.begin() + left_size);
	post_order(L_pre_order, L_in_order); 
	//왼쪽 먼저 출력 
	vector<int> R_pre_order = vector<int>(pre_order.begin() + left_size+1, pre_order.begin() + in_order.size());
	vector<int> R_in_order = vector<int>(in_order.begin()+left_size+1, in_order.begin() + in_order.size());
	post_order(R_pre_order, R_in_order);
	//오른쪽 먼저 출력 
	cout << root << " ";
	//root 출력 
}
int main(void) {
	int C;
	scanf("%d", &C);
	for (int t = 1; t <= C; t++) {
		vector <int> pre_order, in_order;
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			int temp;
			scanf("%d", &temp);
			pre_order.push_back(temp);
		}
		for (int i = 1; i <= n; i++) {
			int temp;
			scanf("%d", &temp);
			in_order.push_back(temp);
		}
		post_order(pre_order, in_order);
		cout << "\n";
	}

	return 0;
}