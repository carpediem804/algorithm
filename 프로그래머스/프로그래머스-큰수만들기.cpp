#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;


string solution(string number, int k) {
    string answer = "";
    int stand_index=0;
    int max_num = number[0]-'0';
    int rest = number.size()-k;
    int next_start_point=0;
    while(rest != 0){
        for(int i=next_start_point+1;i<=number.size()-rest;i++){
            if(max_num < number[i]-'0'){
                stand_index = i;
                max_num = number[i]-'0';
            }
        }
    //   cout << max_num << " " << stand_index  << "\n"; 
        next_start_point = stand_index;
        answer += to_string(max_num);
        rest --;
        max_num =0;
    }
    return answer;
}
