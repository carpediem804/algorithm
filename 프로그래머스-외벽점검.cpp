#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;
vector<int> friend_can_go;
vector<int> temp_weak;
int total_length;

bool calc(int pick_people_num, int start_weak_point){
    //start_weak_point를 기준으로 다시 weak를 정렬해야한다 
    vector <int> standard_weak;
    for(int i=0;i<start_weak_point-1;i++){
        standard_weak.push_back(temp_weak[i]+total_length);
    }
    for(int i=start_weak_point-1;i<temp_weak.size();i++){
        standard_weak.push_back(temp_weak[i]);
    }
    sort(standard_weak.begin(),standard_weak.end());
    
  //  for(int i=0;i<standard_weak.size();i++){
  //      cout << standard_weak[i] <<" " ;
  //  }
  //  cout << "\n";
    //start_weak_point 기준으로 weak 위치 다시 조절 
    int can_go[17] = {0,};
    
    for(int i=1;i<=pick_people_num;i++){
        int friend_can = friend_can_go[i-1];
        int check_point=-1;
        for(int i=0;i<standard_weak.size();i++){
            if(can_go[i]==0 && check_point == -1){ //처음 방문 한 점이면 
                check_point = standard_weak[i];
                can_go[i]=1; //시작 하는 점은 바로 검사를 했다라고 침
               // continue;
            }
            else if(can_go[i]==0 && check_point !=-1){ //그 다음점
                if(standard_weak[i] - check_point <= friend_can){ //체크할수 있으면 체크햇다고 하고
                    can_go[i] = 1;
                }
                else{ //체크할수없으면 다음 친구부터 다시 본다잉 
                    break;
                }
            }
        }
    }
    
   // for(int i=0;i<standard_weak.size();i++){
    //    printf("%d ",can_go[i]);
    //}printf("\n");
    for(int i=0;i<standard_weak.size();i++){
        if(can_go[i]==0){
            return false;
        }
    }
    return true;
}
int solution(int n, vector<int> weak, vector<int> dist) {
    total_length = n;
    int answer = 0;
    sort(dist.begin(),dist.end(),greater<int>());
    friend_can_go  = dist;
    temp_weak = weak;
 //   for(int i=0;i<dist.size();i++){
  //      cout << dist[i] <<" ";
   // }
    answer = -1;
    for(int i=1;i<=dist.size();i++){
        for(int j=1;j<=weak.size();j++){
            if(calc(i,j)){
                answer = i;
                return answer;
            }
       //         printf("friend_pick_num : %d pick_weak_point : %d , %d\n",i,j ,calc(i,j));
            }
    }
    return answer;
}
