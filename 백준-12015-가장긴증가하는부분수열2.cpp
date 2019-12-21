#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>


using namespace std;

int main(void) {
	vector <int> v;
	int n;
	scanf("%d", &n);
	int ans = 1;
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		if (i == 0) {
			v.push_back(temp);
			continue;
		}
		if (v.back() < temp) {
			v.push_back(temp);
			ans++;
		}
		else { //받은 temp 값이 마지막 값보다 작거나 같을경우 
			int index = lower_bound(v.begin(), v.end(), temp) - v.begin() ;
			//cout << "index : " << index << "\n";
			v[index] = temp;
		}
	}
	printf("%d\n", ans);
	return 0;
}