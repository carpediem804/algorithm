#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
struct _node {
	int x, y, r;
	vector<_node*> child;
};

bool is_in(_node* a1, _node* a2) {
	int distance = abs(a1->x - a2->x)*abs(a1->x - a2->x) + abs(a1->y - a2->y)*abs(a1->y - a2->y);
	if (distance > (a1->r + a2->r)*(a1->r + a2->r)) {
		return false;
	}
	else { return true; }
}
void make_tree(_node* parent_node, _node* temp_node) {
	int parent_node_child_size = parent_node->child.size();
	int flag = 0;
	for (int i = 0; i < parent_node_child_size; i++) { //자식들중 temp_node 포함할수 있는 애들 찾기 
		if (is_in(parent_node->child[i], temp_node)) {
			flag = 1;
			make_tree(parent_node->child[i], temp_node);
		}
	}
	if (flag == 0) {
	//	printf("%d %d %d 에  %d %d %d 들어감 \n", parent_node->x, parent_node->y, parent_node->r, temp_node->x, temp_node->y, temp_node->r);
		parent_node->child.push_back(temp_node);
	}
}
struct aa {
	int x, y, r;
	aa(int n1, int n2, int n3) :x(n1), y(n2), r(n3) {

	}
};
bool cmp(aa a1, aa a2){
	return a1.r > a2.r;
};
vector <int> ans_v;
int root_r;
int find_max(_node* root) {
	
	int child_size = root->child.size();
	//printf(" x: %d y: %d r :%d  chiildsize : %d\n", root->x, root->y, root->r, child_size);
	if (child_size == 0) {
		return 0;
	}
	int dept = 0;
	for (int i = 0; i < child_size; i++) {
		if(root->r == root_r){
			ans_v.push_back(find_max(root->child[i]) + 1);
		}
		else {
			dept = max(dept, find_max(root->child[i]) + 1);
		}
	}
	//printf("%d %d %d 에서 dept : %d\n", root->x, root->y, root->r, dept);
	return dept;
}
int main(void) {
	int C;
	scanf("%d", &C);
	for (int t = 1; t <= C; t++) {
		int n;
		scanf("%d", &n);
		vector <aa> v;
		_node* root_node = new _node();
		for (int i = 1; i <= n; i++) {
			int x, y, r;
			scanf("%d %d %d", &x, &y, &r);
			v.push_back(aa(x, y, r));
		}
		sort(v.begin(), v.end(), cmp);
		
		root_node->x = v[0].x;
		root_node->y = v[0].y;
		root_node->r = v[0].r;
		for (int i = 1; i < v.size(); i++) {
			_node* temp = new _node();
			temp->x = v[i].x;
			temp->y = v[i].y;
			temp->r = v[i].r;
			make_tree(root_node, temp);
		}
		root_r = v[0].r;
		find_max(root_node);
//		printf("dept : %d\n", find_max(root_node));
		if (ans_v.size() == 1) {
			printf("%d\n", ans_v[0]);
		}
		else {
			sort(ans_v.begin(), ans_v.end(),greater<int>());
			printf("%d\n", ans_v[0] + ans_v[1]);
		}
		
		ans_v.clear();
	}

	return 0;
}