#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

string solution(string s) {
    string answer = "";
    int cnt=0;
    for(int i=0;i<s.size();i++){
        printf("%d\n",s[i]);
        if(s[i]==32){
            answer += " ";
            cnt =0;
            continue;
        }
        if(cnt%2==0){ //대문자로 바꿔야댐
            if(s[i]<'a'){//대문자라면
                answer += s[i];
            }
            else{ //소문자라면 대문자로 바꿔야댐
                answer += (s[i]-32);
            }
            cnt ++;
        }
        else if (cnt%2==1){ //소문자로 바꿔야댐
            if(s[i]<'a'){//대문자라면
                answer += (s[i]+32);
            }
            else{ //소문자라면 대문자로 바꿔야댐
                answer += s[i];
            }
            cnt ++;
        }
    }
    return answer;
}
