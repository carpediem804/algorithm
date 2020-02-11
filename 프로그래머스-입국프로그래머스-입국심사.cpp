#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long min_time = 0;
    long long max_time = (long long)times.back() * n;
    long long mid_time = (min_time + max_time) /2;
    while(min_time <= max_time){
        mid_time = (min_time + max_time) /2;
        long long can_num=0;
        for(int i=0;i<times.size();i++){
            can_num += (mid_time / times[i]);
        }
        cout << min_time << " "  << mid_time <<" "<< max_time << " " << can_num   << "\n";
        if(can_num >= n){
            max_time = mid_time-1;
        }else{
            min_time = mid_time+1;
        }
    }
    
    return min_time;
}
