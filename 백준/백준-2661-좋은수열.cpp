#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int n;

bool check(string s) {
	int len = s.length();
	int start = len - 1; //string은 0부터 시작이니까
	for (int i = 1; i <= len / 2; i++) {
		string check1 = s.substr(start - i, i);
		string check2 = s.substr(start, i);
		if (check1.compare(check2) == 0) {
			return false;
		}
		start--;
	}
	return true;
}
int isok;
void dfs(int len, string s) {
	if (isok == 1) { return; }
	if (!check(s)) { return; }
	if (len == n) {
		isok = 1;
		for (int i = 0; i < n; i++) {
			printf("%c", s[i]);
		}
		//printf("\n");
		return;
	}
	dfs(len + 1, s + "1");
	dfs(len + 1, s + "2");
	dfs(len + 1, s + "3");
}
int main(void) {
	scanf("%d", &n);
	dfs(1,"1");
	
	return 0;
}