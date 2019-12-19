#include <iostream>
#include <stdio.h>
#include <stack>
#include <vector>
using namespace std; 
stack <int> s;
vector <string> v;
int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		if (s.size() == 0) {
			s.push(temp);
			v.push_back("+");
		}
		if (s.top() > temp) {
			while (s.top() > temp || s.size()!=0) {
				s.pop();
				v.push_back("-");
			}
			
		}
	}

	return 0;
}