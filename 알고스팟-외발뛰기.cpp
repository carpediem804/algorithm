#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int map[101][101];
int check[101][101];
int n;
int jump(int x, int y) {
//	printf("x : %d y : %d\n", x, y);
	if (x > n || x<1 || y>n || y < 1) {
		return 0; //�ȵǴ� ���� 0���� ~ 
	}//�������
	if (x == n && y == n) {
		return 1;
	}//������ ���̸� 
	
	int jumpsize = map[x][y];
	int ret = check[x][y];
	if (ret != -1) { //�ѹ� ���� ģ���� 
		return ret;
	}
	//�ѹ� �غ� ��� ~ 
	ret = max(jump(x + jumpsize, y), jump(x, y + jumpsize));
	check[x][y] = ret;
	return ret;

}
int main(void) {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d", &n);

		memset(check, -1, sizeof(check));
		
		//check�� �� -1�� �ʱ�ȭ 
		for (int x = 1; x <= n; x++) {
			for (int y = 1; y <= n; y++) {
				scanf("%d", &map[x][y]);
			}
		}
		
		if (jump(1, 1) == 1) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}

	}

	return 0;
}