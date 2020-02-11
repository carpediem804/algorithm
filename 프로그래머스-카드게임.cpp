#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
int cache[2001][2001];
vector <int> left_num,right_num;
int calc(int left_index, int right_index){
  //  printf("left : %d right : %d\n",left_index,right_index);
    if(left_index >= left_num.size() ||right_index>=right_num.size()){
        return 0;
    }
    int& ret = cache[left_index][right_index];
    if(ret !=0){
        return ret;
    }
    if(left_num[left_index] > right_num[right_index]){
        ret = calc(left_index,right_index+1) + right_num[right_index];
    }
    else{
        ret = max(calc(left_index+1,right_index+1),calc(left_index+1,right_index));
    }
    return ret;
}
int solution(vector<int> left, vector<int> right) {
    left_num = left;
    right_num = right;
    
    int answer = calc(0,0);
    return answer;
}
