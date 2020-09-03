#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    map <string, int> mp;
    for(int i=0;i<clothes.size();i++){
        string name = clothes[i][0];
        string kind = clothes[i][1];
        mp[kind] +=1;
    }
    int answer = 1;
    for(auto iter = mp.begin();iter !=mp.end();iter++){
        int multiple_num = iter->second;
        answer *= (multiple_num+1);
        cout << multiple_num;
    }
    //cout << mp.size() << "\n";
    
    return answer-1;
}
