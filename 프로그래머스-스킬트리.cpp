#include <string>
#include <vector>
#include <stdio.h>
using namespace std;
bool is_ok(string skill, string skill_tree){
    int order[27] = {0,};
    for(int i=0;i<skill_tree.size();i++){
        for(int j=0;j<skill.size();j++){
            if(skill[j]==skill_tree[i]){
                order[j+1] = i+1;
            }
        }
    }
    int temp = order[1];
     // for(int i=1;i<=skill.size();i++){
     //    printf("%d ",order[i]);
     // }printf("\n");
    for(int i=1;i<=skill.size();i++){
        if(order[i]==0){
            for(int j=i+1;j<=skill.size();j++){
               if(order[j]!=0){return false;} 
            }
        }
        else if(temp <= order[i]){temp = order[i];}
        else{return false;}
    }
    return true;
}
int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(int i=0;i< skill_trees.size();i++){
        if(is_ok(skill,skill_trees[i])){
           // printf("i : %d\n",i);
            answer ++;
        }
    }
    
    return answer;
}
