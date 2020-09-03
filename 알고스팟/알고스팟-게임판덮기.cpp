#include <iostream>
#include <stdio.h>

using namespace std;
int h, w;
char map[21][21];
char temp_map[21][21];
int white_num;
int ans;
void dfs(int x, int y, int block_num) {
	if (block_num == 0) {
		
		for (int _x = 1; _x <= h; _x++) {
			for (int _y = 1; _y <= w; _y++) {
				if (temp_map[_x][_y] == '.') {
					return;
				}
			}
		}
		ans++;
		return ;
	}
	//printf("x : %d y : %d block_num : %d\n", x, y, block_num);
	
	int dx=1, dy=1;
	int check = 0;
	for (int _x = 1; _x <= h; _x++) {
		for (int _y = 1; _y <= w; _y++) {
			if (temp_map[_x][_y] == '.') {
				dx = _x;
				dy = _y;
				check = 1;
				break;
			}
		}
		if (check == 1) {
			break;
		}
	}
	//printf("dx : %d dy : %d\n", dx, dy);
	
	//1번 오른쪽+아래 으로 넣기
	if (dy + 1 <= w && dx + 1 <= h &&temp_map[dx+1][dy]=='.'&&temp_map[dx][dy+1]=='.') {
		temp_map[dx][dy] = '#';
		temp_map[dx + 1][dy] = '#';
		temp_map[dx][dy + 1] = '#';
		//printf("1번\n");
		dfs(dx, dy, block_num-1);
		//printf("in 1 dx : %d dy : %d\n", dx, dy);
		
		temp_map[dx][dy] = '.';
		temp_map[dx + 1][dy] = '.';
		temp_map[dx][dy + 1] = '.';
		
	}//되는 경우 
	
	//2번 ㄱ 으로 넣기 
	if (dy + 1 <= w && dx + 1 <= h && temp_map[dx + 1][dy+1] == '.'&&temp_map[dx][dy + 1] == '.') {
		temp_map[dx][dy] = '#';
		temp_map[dx + 1][dy+1] = '#';
		temp_map[dx][dy + 1] = '#';
		//printf("2번\n");
		dfs(dx, dy, block_num - 1);
		temp_map[dx][dy] = '.';
		temp_map[dx + 1][dy+1] = '.';
		temp_map[dx][dy + 1] = '.';
	}
	//3번 ㄴ 으로 넣기
	if (dy + 1 <= w && dx + 1 <= h && temp_map[dx + 1][dy] == '.'&&temp_map[dx+1][dy + 1] == '.') {
		temp_map[dx + 1][dy] = '#';
		temp_map[dx+1][dy + 1] = '#';
		temp_map[dx][dy] = '#';
		//printf("3번\n");
		dfs(dx, dy, block_num - 1);
		//printf("in 3 : dx : %d dy : %d\n", dx, dy);
		temp_map[dx][dy] = '.';
		temp_map[dx + 1][dy] = '.';
		temp_map[dx+1][dy + 1] = '.';
		
	}
	//4번 아래 + 아래 왼쪽 넣기 
	if (dy - 1 >= 1 && dx + 1 <= h && temp_map[dx + 1][dy] == '.'&&temp_map[dx+1][dy - 1] == '.') {
		temp_map[dx + 1][dy] = '#';
		temp_map[dx+1][dy - 1] = '#';
		temp_map[dx][dy] = '#';
	//	printf("4번\n");
		dfs(dx, dy, block_num - 1);
		temp_map[dx][dy] = '.';
		temp_map[dx + 1][dy] = '.';
		temp_map[dx+1][dy - 1] = '.';
	}

}
int main(void) {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		//scanf("%d %d", &h, &w);
		cin >> h >> w;
		//printf("%d %d\n", h, w);
		white_num = 0;
		ans = 0;
		for (int x = 1; x <= h; x++) {
			for (int y = 1; y <= w; y++) {
				//printf("X : %d y : %d ", x, y);
				char temp;
				cin >> temp;
				
				temp_map[x][y] = temp;
				if (temp == '.') {
					white_num++;
				}
			}
		}//map입력받고
		
		if (white_num % 3 != 0) {
			printf("0\n");
			continue;
		}
		int can_num = white_num / 3;//놓을수있는 블록개수
	
		dfs(1, 1, can_num);
		printf("%d\n", ans);
	

	}
	return 0;
}