#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
struct aa {
	int x, y;
	aa(int n1, int n2) :x(n1), y(n2) {
	}
};
bool cmp1(aa a1, aa a2) {
	return a1.x < a2.x;
}
bool cmp2(aa a1, aa a2) {
	return a1.y < a2.y;
}
vector <aa> v;
int dist(int a_index, int b_index) {
	int x_ = v[a_index].x - v[b_index].x;
	int y_ = v[a_index].y - v[b_index].y;
	return (x_ * x_) + (y_ * y_);
}

int calc(int start, int end) { //start, end 는 index 
	if (start == end) {
		return 0;
	}
	if (end-start == 1) {
		//printf("start:  %d end : %d\n", start, end);
		return dist(start, end);
	} //두점밖에없는경우 
	
	if (end-start == 2) {
		return min(min(dist(start, start+1), dist(start, start+2)), dist(start+1, start+2));
	}//세점 밖에 없는경우 

	int mid_index = (start + end) / 2;
	int left = calc(start, mid_index);
	int right = calc(mid_index + 1, end);
	int d = min(left,right);
	//이분탐색으로 좌 우 중 최소 거리 찾기 
	//printf("left : %d right : %d mid_indx : %d , d : %d start : %d end : %d \n",left,right, mid_index, d,start,end);
	
	vector <aa> hubo;
	hubo.reserve(end);
	for (int i = start; i <= end; i++) {
		int t = v[i].x - v[mid_index].x;
		//mid index기준으로 부터 거리 
		if (t*t < d) {
			hubo.push_back(v[i]);
		} //거리가 루트d 보다 작은애들만 후보로 넣기 
	} // 후보들을 넣는다 
	
	sort(hubo.begin(), hubo.end(), cmp2); 
	//y 좌표 기준으로 소트 
	
	for (int i = 0; i < hubo.size(); i++) {
		for (int j = i + 1; j < hubo.size(); j++) {
			int temp_dist = hubo[j].y - hubo[i].y; //y좌표의 차들이 
			
			if (temp_dist*temp_dist < d) {
				int y_dist = hubo[i].y - hubo[j].y;
				int x_dist = hubo[i].x - hubo[j].x;
				//printf("hubo %d %d  %d %d 임 ", hubo[i].x, hubo[i].y, hubo[j].x, hubo[j].y);
				d = min(d, y_dist * y_dist + x_dist * x_dist);
				//printf("d : %d\n", d);
			}
			else {
					break;
			}	
		}
	}
	return d;
}
int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		v.push_back(aa(x, y));
	}

	sort(v.begin(), v.end(), cmp1);
	
	int ans = calc(0,n-1);
	printf("%d", ans);
	return 0;
}