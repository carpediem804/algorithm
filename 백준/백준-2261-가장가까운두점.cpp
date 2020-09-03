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

int calc(int start, int end) { //start, end �� index 
	if (start == end) {
		return 0;
	}
	if (end-start == 1) {
		//printf("start:  %d end : %d\n", start, end);
		return dist(start, end);
	} //�����ۿ����°�� 
	
	if (end-start == 2) {
		return min(min(dist(start, start+1), dist(start, start+2)), dist(start+1, start+2));
	}//���� �ۿ� ���°�� 

	int mid_index = (start + end) / 2;
	int left = calc(start, mid_index);
	int right = calc(mid_index + 1, end);
	int d = min(left,right);
	//�̺�Ž������ �� �� �� �ּ� �Ÿ� ã�� 
	//printf("left : %d right : %d mid_indx : %d , d : %d start : %d end : %d \n",left,right, mid_index, d,start,end);
	
	vector <aa> hubo;
	hubo.reserve(end);
	for (int i = start; i <= end; i++) {
		int t = v[i].x - v[mid_index].x;
		//mid index�������� ���� �Ÿ� 
		if (t*t < d) {
			hubo.push_back(v[i]);
		} //�Ÿ��� ��Ʈd ���� �����ֵ鸸 �ĺ��� �ֱ� 
	} // �ĺ����� �ִ´� 
	
	sort(hubo.begin(), hubo.end(), cmp2); 
	//y ��ǥ �������� ��Ʈ 
	
	for (int i = 0; i < hubo.size(); i++) {
		for (int j = i + 1; j < hubo.size(); j++) {
			int temp_dist = hubo[j].y - hubo[i].y; //y��ǥ�� ������ 
			
			if (temp_dist*temp_dist < d) {
				int y_dist = hubo[i].y - hubo[j].y;
				int x_dist = hubo[i].x - hubo[j].x;
				//printf("hubo %d %d  %d %d �� ", hubo[i].x, hubo[i].y, hubo[j].x, hubo[j].y);
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