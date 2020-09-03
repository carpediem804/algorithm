#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int n, k;
int map[14][14];
stack<int> s_map[13][13];
struct node {
	int x, y, dir;
	node(int n1, int n2, int n3) :x(n1), y(n2), dir(n3) {

	}
};

vector <node> v;
int main(void) {
	scanf("%d %d",&n,&k);
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			scanf("%d", &map[x][y]);
		}
	}
	for (int x = 0; x <= n+1; x++) {
		for (int y = 0; y <= n+1; y++) {
			if (x == n + 1 || y == n + 1 || x == 0 || y == 0) {
				map[x][y] = 2;
			}
		}
	}
	for (int i = 0; i < k; i++) {
		int x, y, dir;
		scanf("%d %d %d", &x, &y, &dir);
		v.push_back(node(x,y,dir));
		s_map[x][y].push(i);
	}//queue에 각 말 정보 넣기 
	int turn = 0;
	while (turn <= 1000) {
		turn++;
		//printf("-----------------------%d번째--------\n", turn);
		for (int i = 0; i < v.size(); i++) {
			int x = v[i].x;
			int y = v[i].y;
			int dir = v[i].dir;
			vector <int> up_index;
			int s_map_size = s_map[x][y].size();
			
		//	printf("index : %d  x: %d y : %d dir : %d s_map_size : %d\n",i,x,y,dir,s_map_size);
			for (int ii = 0; ii < s_map_size; ii++) {
			//	printf("ii : %d\n", ii);
			//	printf("inddex : %d\n", s_map[x][y].top());
				up_index.push_back(s_map[x][y].top());
				if (s_map[x][y].top() == i) { //내 index와 같을때
					s_map[x][y].pop();
					break;
				}
				s_map[x][y].pop();
			}//내 index까지 up_index vector에 넣고 
		//	printf("inin\n");
			if (dir == 1) { // 오른쪽  
				y += 1;
			//	printf("x : %d y : %d \n", x, y);
				if (map[x][y] == 0) {
					//printf("map[x][y] = %d\n", map[x][y]);
						for (int in = up_index.size() - 1; in >= 0; in--) {
							int index = up_index[in];
							v[index].x = x;
							v[index].y = y;
							s_map[x][y].push(index);
							if (s_map[x][y].size() >= 4) {
								printf("%d\n", turn);
								return 0;
							}
						} //위에 쌓인 친구들 좌표 바꿔주고 s_map에 스택으로 쌓고
					}
				else if (map[x][y] == 1) {
					
						for (int in = 0; in < up_index.size(); in++) {
							int index = up_index[in];
							v[index].x = x;
							v[index].y = y;
							s_map[x][y].push(index);
							if (s_map[x][y].size() >= 4) {
								printf("%d\n", turn);
								return 0;
							}
						} //위에 쌓인 친구들 좌표 바꿔주고 s_map에 스택으로 쌓고
					}
				else if (map[x][y] == 2) {//가는 점이 파랑일 때 
					y -= 2;
					v[i].dir = 2;
					if (map[x][y] == 2) {
						y += 1;
						for (int in = up_index.size() - 1; in >= 0; in--) {
							int index = up_index[in];
							v[index].x = x;
							v[index].y = y;
							s_map[x][y].push(index);
							if (s_map[x][y].size() >= 4) {
								printf("%d\n", turn);
								return 0;
							}
						}
					}//이동하려는 점이 파랑이면 !! 좌표 그대로 방향만 바꾸기
					else if (map[x][y] == 1) { //빨강이면
						for (int in = 0; in < up_index.size(); in++) {
							int index = up_index[in];
							v[index].x = x;
							v[index].y = y;
							s_map[x][y].push(index);
							if (s_map[x][y].size() >= 4) {
								printf("%d\n", turn);
								return 0;
							}
						}
					}
					else if (map[x][y] == 0) {
						for (int in = up_index.size() - 1; in >= 0; in--) {
							int index = up_index[in];
							v[index].x = x;
							v[index].y = y;
							s_map[x][y].push(index);
							if (s_map[x][y].size() >= 4) {
								printf("%d\n", turn);
								return 0;
							}
						} //위에 쌓인 친구들 좌표 바꿔주고 s_map에 스택으로 쌓고
					}
				}
			}
			else if (dir == 2) { //왼쪽
				y -= 1;
				if (map[x][y] == 0) {
					for (int in = up_index.size() - 1; in >= 0; in--) {
						int index = up_index[in];
						v[index].x = x;
						v[index].y = y;
						s_map[x][y].push(index);
						if (s_map[x][y].size() >= 4) {
							printf("%d\n", turn);
							return 0;
						}
					} //위에 쌓인 친구들 좌표 바꿔주고 s_map에 스택으로 쌓고
				}
				else if (map[x][y] == 1) {
					for (int in = 0; in < up_index.size(); in++) {
						int index = up_index[in];
						v[index].x = x;
						v[index].y = y;
						s_map[x][y].push(index);
						if (s_map[x][y].size() >= 4) {
							printf("%d\n", turn);
							return 0;
						}
					} //위에 쌓인 친구들 좌표 바꿔주고 s_map에 스택으로 쌓고
				}
				else if (map[x][y] == 2) {//가는 점이 파랑일 때 
					y += 2;
					v[i].dir = 1;
					if (map[x][y] == 2) {
						y -= 1;
						for (int in = up_index.size() - 1; in >= 0; in--) {
							int index = up_index[in];
							v[index].x = x;
							v[index].y = y;
							s_map[x][y].push(index);
							if (s_map[x][y].size() >= 4) {
								printf("%d\n", turn);
								return 0;
							}
						}
					}//이동하려는 점이 파랑이면 !! 좌표 그대로 방향만 바꾸기
					else if (map[x][y] == 1) { //빨강이면
						for (int in = 0; in < up_index.size(); in++) {
							int index = up_index[in];
							v[index].x = x;
							v[index].y = y;
							s_map[x][y].push(index);
							if (s_map[x][y].size() >= 4) {
								printf("%d\n", turn);
								return 0;
							}
						}
					}
					else if (map[x][y] == 0) {
						for (int in = up_index.size() - 1; in >= 0; in--) {
							int index = up_index[in];
							v[index].x = x;
							v[index].y = y;
							s_map[x][y].push(index);
							if (s_map[x][y].size() >= 4) {
								printf("%d\n", turn);
								return 0;
							}
						} //위에 쌓인 친구들 좌표 바꿔주고 s_map에 스택으로 쌓고
					}
				}
			}
			else if (dir == 3) { //위로갈때 
				x -= 1;
				if (map[x][y] == 0) {
					for (int in = up_index.size() - 1; in >= 0; in--) {
						int index = up_index[in];
						v[index].x = x;
						v[index].y = y;
						s_map[x][y].push(index);
						if (s_map[x][y].size() >= 4) {
							printf("%d\n", turn);
							return 0;
						}
					} //위에 쌓인 친구들 좌표 바꿔주고 s_map에 스택으로 쌓고
				}
				else if (map[x][y] == 1) {
					for (int in = 0; in < up_index.size(); in++) {
						int index = up_index[in];
						v[index].x = x;
						v[index].y = y;
						s_map[x][y].push(index);
						if (s_map[x][y].size() >= 4) {
							printf("%d\n", turn);
							return 0;
						}
					} //위에 쌓인 친구들 좌표 바꿔주고 s_map에 스택으로 쌓고
				}
				else if (map[x][y] == 2) {//가는 점이 파랑일 때 
					x += 2;
					v[i].dir = 4;
					if (map[x][y] == 2) {
						x -= 1;
						for (int in = up_index.size() - 1; in >= 0; in--) {
							int index = up_index[in];
							v[index].x = x;
							v[index].y = y;
							s_map[x][y].push(index);
							if (s_map[x][y].size() >= 4) {
								printf("%d\n", turn);
								return 0;
							}
						}
					}//이동하려는 점이 파랑이면 !! 좌표 그대로 방향만 바꾸기
					else if (map[x][y] == 1) { //빨강이면
						for (int in = 0; in < up_index.size(); in++) {
							int index = up_index[in];
							v[index].x = x;
							v[index].y = y;
							s_map[x][y].push(index);
							if (s_map[x][y].size() >= 4) {
								printf("%d\n", turn);
								return 0;
							}
						}
					}
					else if (map[x][y] == 0) {
						for (int in = up_index.size() - 1; in >= 0; in--) {
							int index = up_index[in];
							v[index].x = x;
							v[index].y = y;
							s_map[x][y].push(index);
							if (s_map[x][y].size() >= 4) {
								printf("%d\n", turn);
								return 0;
							}
						} //위에 쌓인 친구들 좌표 바꿔주고 s_map에 스택으로 쌓고
					}
				}
			}
			else if (dir == 4) {
				x += 1;
				if (map[x][y] == 0) {
					for (int in = up_index.size() - 1; in >= 0; in--) {
						int index = up_index[in];
						v[index].x = x;
						v[index].y = y;
						s_map[x][y].push(index);
						if (s_map[x][y].size() >= 4) {
							printf("%d\n", turn);
							return 0;
						}
					} //위에 쌓인 친구들 좌표 바꿔주고 s_map에 스택으로 쌓고
				}
				else if (map[x][y] == 1) {
					for (int in = 0; in < up_index.size(); in++) {
						int index = up_index[in];
						v[index].x = x;
						v[index].y = y;
						s_map[x][y].push(index);
						if (s_map[x][y].size() >= 4) {
							printf("%d\n", turn);
							return 0;
						}
					} //위에 쌓인 친구들 좌표 바꿔주고 s_map에 스택으로 쌓고
				}
				else if (map[x][y] == 2) {//가는 점이 파랑일 때 
					x -= 2;
					v[i].dir = 3;
					if (map[x][y] == 2) {
						x += 1;
						for (int in = up_index.size() - 1; in >= 0; in--) {
							int index = up_index[in];
							v[index].x = x;
							v[index].y = y;
							s_map[x][y].push(index);
							if (s_map[x][y].size() >= 4) {
								printf("%d\n", turn);
								return 0;
							}
						}
					}//이동하려는 점이 파랑이면 !! 좌표 그대로 방향만 바꾸기
					else if (map[x][y] == 1) { //빨강이면
						for (int in = 0; in < up_index.size(); in++) {
							int index = up_index[in];
							v[index].x = x;
							v[index].y = y;
							s_map[x][y].push(index);
							if (s_map[x][y].size() >= 4) {
								printf("%d\n", turn);
								return 0;
							}
						}
					}
					else if (map[x][y] == 0) {
						for (int in = up_index.size() - 1; in >= 0; in--) {
							int index = up_index[in];
							v[index].x = x;
							v[index].y = y;
							s_map[x][y].push(index);
							if (s_map[x][y].size() >= 4) {
								printf("%d\n", turn);
								return 0;
							}
						} //위에 쌓인 친구들 좌표 바꿔주고 s_map에 스택으로 쌓고
					}
				}
			}



		}//vector에 저장된 말들 하나하나 이동 다 해야됨
	}

	printf("-1\n");
	return 0;
}