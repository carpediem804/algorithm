#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int map[101];
vector <int> ans;
int gcd(int a, int b) {
	if (a%b == 0) {
		return b;
	}
	return gcd(b, a%b);
}
int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int temp;
		scanf("%d", &temp);
		map[i] = temp;
	}
	sort(map, map + n+1);

	int temp_gcd = map[2] - map[1];
	for (int i = 3; i <= n; i++) {
		temp_gcd = gcd(temp_gcd, map[i] - map[i - 1]);
	} //차이들으 ㅣ최대 공약수 찾는것 
	//printf("temp_gcd : %d\n", temp_gcd);

	for (int i = 2; i*i <= temp_gcd; i++) {
		if (temp_gcd %i == 0) {
			ans.push_back(i);
			ans.push_back(temp_gcd / i);
		}
	}
	ans.push_back(temp_gcd);
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}