#include <iostream>
#include <stdio.h>;
#include <vector>
#include <algorithm>

using namespace std;
vector <int> v;
int n, m;
int cnt;
int findmax;
int findmin;
void find(int findnum, int minindex, int maxindex) {
	int mid = (minindex + maxindex) / 2;
	if (minindex > maxindex) {
		return;
	}
	if (v[mid] < findnum) {
		find(findnum, mid + 1, maxindex);
	}
	else if (v[mid] > findnum) {
		find(findnum, minindex, mid - 1);
	}
	else {
		if (findmax < mid) {
			findmax = mid;
			find(findnum, mid + 1, maxindex);
		}
		if (findmin > mid) {
			findmin = mid;
			find(findnum, minindex, mid - 1);
		}
	}//°°À»¶§!! 
}
int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf(" %d", &temp);
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int findnum;
		findmax = 0;
		findmin = 987654321;
		scanf(" %d", &findnum);
		find(findnum, 0, n - 1);
		if (findmax == 0 && findmin == 987654321) {
			printf("0 ");
		}
		else {
			printf("%d ", findmax - findmin +1);
		}
	}
	return 0;
}