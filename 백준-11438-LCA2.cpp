#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
int p[100001][17]; // p[v][d] == v정점의 2의d승째의 부모정점 번호 
int level[100001];
vector <int> v[100001];
queue<int> q;
int main(void) {
	int n, m;
	int a, b;
	int temp;
	int next;

	scanf("%d", &n);
	q.push(1);
	level[1] = 1;
	for (int i = 0; i < n - 1; i++) {
		scanf(" %d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}// 입력 for 문
	while (!q.empty()) {
		temp = q.front();
		//printf("temp : %d\n", temp);
		q.pop();
		for (int i = 0; i < v[temp].size(); i++) {
			next = v[temp][i];  //temp노드와 연결되어 있는 다른 노드가 next
			if (level[next] == 0) { //연결된 노드의 level ==0이면 
				q.push(next);
				level[next] = level[temp] + 1; //temp노드의 level+1이 연결된 점의 level
			//	printf("next : %d temp : %d\n", next,temp);
				p[next][0] = temp; // p 처음값 초기화 햇다 
			}
		}
	}// queue사용해서 level이랑 q [][0]초기화 햇음 //level ==depth 이다 level의 시작값 ==1 
	for (int i = 1; i < 17; i++) {
		for (int j = 1; j <= n; j++) {
			p[j][i] = p[p[j][i - 1]][i - 1];
		}
	} // p배열 초기화 했다 


	scanf("%d", &m);
	int temp3;
	int high;
	int low;
	for (int i = 0; i < m; i++) {
		scanf(" %d %d", &a, &b);
		high = level[a];
		low = level[b];
		//	printf("high : %d low : %d\n", a, b);
		if (low > high) {
			temp3 = a;
			a = b;
			b = temp3;
		}// high가 항상 크게
		high = a;
		low = b;
		//	printf("high : %d low : %d\n", high, low);

		for (int j = 16; j >= 0; j--) {
			if (level[low] <= level[p[high][j]]) {
				high = p[high][j];
			}
		}// 높이 맞춰 주는거 

		//printf("높이 맞춘 후 high : %d low : %d\n", high, low);
		int answer = low;
		if (low != high) { //같은 높이가됫는데 두개가 다르면 위에를봐야한다 
			for (int j = 16; j >= 0; j--) {
				if (p[low][j] != p[high][j]) {
					//다르기시작하면 거기로 이동해야한다.
					low = p[low][j];
					high = p[high][j];
				}
				else {
					answer = p[low][j];
				}
			}//for
			//printf("마지막 highh : %d low : %d\n", high, low);
		}// if
		printf("%d\n", answer);


	}//입력받고 출력하는거 


	return 0;
}