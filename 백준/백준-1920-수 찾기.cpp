#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> v;
int n, m;
void find(int findnum,int minindex,int maxindex) {
	
	int mid = (minindex + maxindex) / 2;
	//printf("findnum : %d min : %d max : %d mid : %d\n",findnum, minindex, maxindex,mid);
	if (minindex > maxindex ) {
		printf("0\n");
		return;
	}
	if (v[mid] > findnum) {
		find(findnum, minindex, mid-1);
	}
	else if (v[mid] < findnum) {
		find(findnum, mid+1, maxindex);
	}
	else { printf("1\n"); return; }
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
		scanf("%d", &findnum);
		find(findnum,0,n-1);
	}
	return 0;
}