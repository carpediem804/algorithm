#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(int n) {
    //몫이 ==0 이면 
    string answer = "";
    while(n != 0){    
        int share = n/3;
        int rest = n%3;
        if(rest == 0){
            share -=1;
            answer = "4" + answer ;
        }
        else{
            if(rest ==1){
                answer = "1" + answer ;
            }
            else if(rest ==2){
                answer = "2" + answer ;
            }
        }
        n = share;
    }
    
    return answer;
}
