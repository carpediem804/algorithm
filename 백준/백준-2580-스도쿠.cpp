#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
vector <pair<int, int>> v;// 0인점 좌표 저장 
int map[10][10]; //map 그리는거 
int zerosize; // 0인점의 개수 
int check = 0; // 1인경우 중간에 실패한 경우 3= 완벽하게 끝난 경우 
bool rowcheck(int x, int y, int num) { //가로체크
	for (int i = 1; i <= 9; i++) {
		if (map[x][i] == num) {
			return false;
		}
	}
	return true;
}
bool columncheck(int x, int y, int num) {
	for (int i = 1; i <= 9; i++) {
		if (map[i][y] == num) {
			return false;
		}
	}
	return true;
}
bool boxcheck(int x, int y, int num) {
	int dx=0;
	if (x / 3 == 0 || x == 3) { //x가 1,2,3인경우 
		dx = 3;
	}
	else if (x / 3 == 1 || x == 6) {//x가 4,5,6인경우
		dx = 6;
	}
	else { dx = 9; } //x가 789인경우
	int dy=0;
	if (y / 3 == 0 || y == 3) { //y가 123인경우
		dy = 3;
	}
	else if (y / 3 == 1 || y == 6) {//y가 456인경우
		dy = 6;
	}
	else {//y가 789인경우
		dy = 9;
	}
	for (int i = dx - 2; i <= dx; i++) {
		for (int j = dy - 2; j <= dy; j++) {
			if (map[i][j] == num) {
				return false;
			}
		}
	}
	return true;
}
void dfs(int cnt) {
	if (cnt == zerosize) { check = 3;  return; } //모든 0인점을 다 채웟으면 check 를 3으로 바꾸고 return ;
	int x = v[cnt].first;
	int y = v[cnt].second;
	for (int i = 1; i <= 9; i++) {
		if (rowcheck(x, y, i) && columncheck(x, y, i) && boxcheck(x, y, i)) {//들어갈수 있는 숫자라면 
			check = 0; //이번엔 잘된다고 check 는 0으로 바꿈 ! 
			map[x][y] = i; //map에 그 숫자 넣고 
			dfs(cnt + 1);//다음경우꺼본다
			if (check == 3) { return; } //check ==3 즉 잘 끝났을 경우 바로 return 시킨다 
			if (check == 1) { map[x][y] = 0;  } //안되는 경우 0으로 다시 바꾼다 }
		}//세 경우 다 된다면 
	}
	if (map[x][y] == 0) {
		check = 1;
	}//다돌았는데 안되는 경우~ 
	
}
int main(void) {
	for (int x = 1; x <= 9; x++) {
		for (int y = 1; y <= 9; y++) {
			int temp;
			scanf(" %d", &temp);
			map[x][y] = temp;
			if (temp == 0) {
				v.push_back(make_pair(x, y));
			}//빈칸인 경우 v에 다 넣기 ~ 
		}
	}// map저장했다 
	zerosize = v.size();//0인 갯수 
	dfs(0);
	for (int x = 1; x <= 9; x++) {
		for (int y = 1; y <= 9; y++) {
			printf("%d ", map[x][y]);
		}printf("\n");
	}
	return 0;
}