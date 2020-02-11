#include <string>
#include <vector>
#include <queue>
#include <stdio.h>
#include <algorithm>
using namespace std;
int map[301][301];
int visit[301][301];
int mapsize;
int height_;
int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
int cnt =1;
int landvisit[90001];
struct aa{
    int a,b,cost;
    aa(int n1,int n2,int n3):a(n1),b(n2),cost(n3){
        
    }
};
struct cmp{
    bool operator()(aa a1, aa a2){
        return a1.cost > a2.cost;
    }
};
priority_queue<aa,vector<aa>,cmp> pq;
queue<pair<int,int>> q;
void bfs(){
    while(q.size()!=0){
        int x= q.front().first;
        int y= q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int dx= x+dir[i][0];
            int dy = y+dir[i][1];
            
            if(dx>=0 && dx<mapsize && dy>=0 && dy<mapsize){
                if(abs(map[dx][dy]-map[x][y])<=height_ && visit[dx][dy]!=cnt){
                    visit[dx][dy] = cnt;
                    q.push(make_pair(dx,dy));
                }
            }
        }
    }
}
int root(int index){
    if(landvisit[index]==index){
        return index;
    }
    return root(landvisit[index]);
}
void union_(int a,int b){
    int a_root = root(a);
    int b_root = root(b);
    landvisit[a_root] = b_root;
}
int solution(vector<vector<int>> land, int height) {
    mapsize= land.size();
    height_ = height;
    for(int i=0;i<land.size();i++){
        for(int j=0;j<mapsize;j++){
            map[i][j] = land[i][j];
        }
    }
    
    for(int x=0;x<land.size();x++){
        for(int y=0;y<land.size();y++){
            if(visit[x][y] ==0){
                visit[x][y] = cnt;
                q.push(make_pair(x,y));
                bfs();
                cnt++;
            }
        }
    }
    cnt --;//land 집합의 개수 
    
    for(int i=1;i<=cnt;i++){
        landvisit[i] =i;
    } 
    for(int x=0;x<land.size();x++){
        for(int y=0;y<land.size();y++){
            for(int d=0;d<4;d++){
                int dx =x+dir[d][0];
                int dy = y+dir[d][1];
                if(dx>=0 && dx<mapsize && dy>=0 && dy<mapsize){
                    if(visit[x][y] != visit[dx][dy]){
                        pq.push(aa(visit[x][y],visit[dx][dy],abs(map[x][y]-map[dx][dy])));
                    }
                }
            }
            //printf("%d ",visit[x][y]);
        }//printf("\n");
    }
    int answer = 0;
    while(pq.size()!=0){
        int from = pq.top().a;
        int to = pq.top().b;
        int cost = pq.top().cost;
        pq.pop();
        if(root(from)==root(to)){
            continue;
        }
        union_(from,to);
        answer += cost;
    }
    
    
    return answer;
}
