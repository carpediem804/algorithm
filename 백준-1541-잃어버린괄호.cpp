#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
using namespace std;
queue <string> q;
int main(void) {
	string s;
	cin >> s;
	string temp = "";
	string add_temp = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			temp += s[i];
		}//숫자인경우 
		else if (s[i] == '-') {
			add_temp = to_string(atoi(add_temp.c_str()) + atoi(temp.c_str()));
			q.push(add_temp);
			temp = "";
			add_temp = "";
			q.push("-");
		}
		else if (s[i] == '+') {
			
			add_temp = to_string(atoi(add_temp.c_str()) + atoi(temp.c_str()));
			
			temp = "";
		}
	}
	add_temp = to_string(atoi(add_temp.c_str()) + atoi(temp.c_str()));
	q.push(add_temp);
	
	int ans = 0;
	int temp_num = 0;
	string oper = "";
	int num = 0;

	while (q.size() != 0) {
		string in_q = q.front();
		q.pop();
		if (in_q == "+") {
			string next_q = q.front();
			q.pop();
			ans += atoi(next_q.c_str());
		}
		else if (in_q == "-") {
			string next_q = q.front();
			q.pop();
			ans -= atoi(next_q.c_str());
		}
		else {
			ans = atoi(in_q.c_str());
		}
	}
	printf("%d\n", ans);
	return 0;
}