#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

int main(void) {
	int n;
	stack <int> s1, s2;
	stack<int> ans;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		s1.push(temp);
	}
	while (s1.size() != 0) {
		int s1_num = s1.top();
		s1.pop();
		if (s2.size() == 0) {
			ans.push(-1);
			s2.push(s1_num);
		}
		else {
			while (s2.size() != 0) { //s2 ���� ��ü�� �ٺ��µ�
				int s2_top = s2.top();
				if (s2_top > s1_num) { //s2���� ����� ���� �������� ũ�� s2������ �� 
					ans.push(s2_top);
					s2.push(s1_num);
					break;
				}
				else { //s2 ���� ����� ���� ���� ��
					s2.pop();
				}
			}
			if (s2.size() == 0) {
				ans.push(-1);
				s2.push(s1_num);
			}
		}
	}
	while (ans.size() != 0) {
		printf("%d ", ans.top());
		ans.pop();
	}
	return 0;
}