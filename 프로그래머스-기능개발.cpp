#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int cnt[101];
    for(int i=0;i<progresses.size();i++){
        if((100 - progresses[i])%speeds[i]==0){
            cnt[i] = (100 - progresses[i])/speeds[i];
        }else{
        cnt[i] = ((100 - progresses[i])/speeds[i])+1;
        }
    }
    for(int i=0;i<progresses.size();i++){
        cout << cnt[i] << "  ";
    }cout <<"\n";
    int check[101] = {0,};
    int temp_ans =0;
    int num =0;
    int standard = 0;
    for(int i=0;i<progresses.size();i++){
        if(check[i]==0){
            
            num = cnt[i];
            temp_ans =1;
            check[i]=1;
            if(i==progresses.size()-1){answer.push_back(temp_ans);}
            for(int j=i+1;j<progresses.size();j++){
                
                if(num >= cnt[j]){  temp_ans ++;  check[j]=1;}
                else{ answer.push_back(temp_ans);break;}
                if(j == progresses.size()-1){
                    answer.push_back(temp_ans);
                }    
            
            }
                
            }
        
    }
    return answer;
}
