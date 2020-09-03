#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
map<int, int> nerds;
bool is_nerd(int x, int y) {
	map<int, int> ::iterator it = nerds.lower_bound(x);
	//x보다 바로큰 점 찾기

	if(it == nerds.end()){//그런점이 없으면 
		return false; //지배당하지 않음 
	}
	if (y < it->second) { //y가 더 작을 때 
		return true; //갠 nerd이다잉 ~ 
	}
	return false;
}
void remove_nerds(int x, int y) {
	map<int, int> ::iterator it = nerds.lower_bound(x);
	//x보다 큰애 중 가장 왼쪽 
	if (it == nerds.begin()) {//x,y보다 왼쪽에 있는 점이없다
		return; //그냥 끝내는겨~ 
	}
	it--;//왼쪽에 있는 점이 있따면 --한게 거기 가르키는것
	while (1) {
		if (it->second > y) {
			break;
		}//기저사례 
		
		if (it == nerds.begin()) { //이전점이 었으면 
			nerds.erase(it);
			break;
		}//기저사례2
		else { //있다면 
			map<int, int >::iterator temp_it = it;
			temp_it--;
			nerds.erase(it);
			it = temp_it;
		}
		
	}
}
int main(void) {
	int C;
	scanf("%d",&C);
	int answer = 0;
	for (int t = 1; t <= C; t++) {
		int n;
		scanf("%d", &n);
		answer = 0;
		for (int i = 0; i < n; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			if (is_nerd(x, y)) { //너드면 
				answer += nerds.size();
				continue;
			}
			remove_nerds(x, y);
			nerds[x] = y;
			answer += nerds.size();
		}
		printf("%d\n", answer);
		nerds.clear();
	}
	return 0;
}