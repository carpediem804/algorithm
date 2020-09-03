#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
int map[31];//최대 의상가짓수가 30개 
vector <pair<string, int>> v;
int main(void) {

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			string s1, s2;
			cin >> s1 >> s2;
			//printf("i : %d\n", i);
			if (v.size() == 0) {
				v.push_back(make_pair(s2, 1));
				continue;
			}
			int check = 0;
			for (int i = 0; i < v.size(); i++) {
				
				if (v[i].first == s2) {
					//printf("i : %d\n", i);
					v[i].second++;
					check = 1;
				}
			}
			if (check == 0) {
				v.push_back(make_pair(s2, 1));
			}
		}
		//printf("V.size = %d\n", v.size());
		int ans = 1;
		for (int i = 0; i < v.size(); i++) {
			printf("num : %d\n", v[i].second);
			ans = ans * (v[i].second + 1);
		}
		ans -= 1;
		printf("%d\n", ans);
		v.clear();
	}
	return 0;
}