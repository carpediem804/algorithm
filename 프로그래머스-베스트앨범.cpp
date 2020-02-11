#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(pair<string ,int> a1,pair<string ,int>a2){
    return a1.second > a2.second;
}
bool cmp2(pair<int,int> a1,pair<int,int> a2){
    return a1.second > a2.second;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    map <string, int> mp;
    vector <pair<string,int>> genre_v;
    vector <pair <int,int>> plays_v[101]; //index와 재생순
    for(int i=0;i<genres.size();i++){
        mp[genres[i]] += plays[i];
    }
    for(auto iter = mp.begin();iter!=mp.end();iter++){
        genre_v.push_back(make_pair(iter->first,iter->second));
       // cout << iter->first << "  " << iter->second <<"\n";
    }
    sort(genre_v.begin(),genre_v.end(),cmp); //장르총 재생순으로 내림차순 sort
    for(int i =0 ; i<genre_v.size();i++){
        for(int j=0;j<plays.size();j++){
            if(genre_v[i].first == genres[j]){
                plays_v[i].push_back(make_pair(j,plays[j]));
            }
        }
    }
    vector<int> answer;
    for(int i=0;i<genre_v.size();i++){
    sort(plays_v[i].begin(),plays_v[i].end(),cmp2);
    }
    for(int i=0;i<genre_v.size();i++){
        for(int j=0;j<plays_v[i].size();j++){
            if(j==2){
                break;
            }
            answer.push_back(plays_v[i][j].first);
        }
    }
    
    return answer;
}
