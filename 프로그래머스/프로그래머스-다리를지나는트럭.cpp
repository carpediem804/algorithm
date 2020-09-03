#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<pair<int,int>> during; 
    int answer = 0;
    int rest_weight = weight;
    int next_truck = 0;
    int time = 0;
    while(1){
        time ++;
        if(during.front().second == time && during.size()!=0){
            rest_weight += during.front().first; //다리 가능 무게 증가시키고 
            during.pop();
        }
        if(next_truck <truck_weights.size() && truck_weights[next_truck] <= rest_weight){
            //printf("%d %d \n",truck_weights[next_truck],time+bridge_length);
            during.push(make_pair(truck_weights[next_truck],time+bridge_length));
            rest_weight -= truck_weights[next_truck];
            next_truck ++;
        }
        
        if(during.size()==0 && next_truck ==truck_weights.size()){return time;}
        
    }
    
    //return answer;
}
