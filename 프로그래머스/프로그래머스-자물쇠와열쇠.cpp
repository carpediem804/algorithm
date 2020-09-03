#include <string>
#include <vector>

using namespace std;
int map[101][101];
int N,M;
vector <pair<int,int> > zero_lock;
bool can_check(int lock_x1,int lock_y1,vector<pair<int,int>>one_key,int j,int zero_size){
    int plus_x = lock_x1 - one_key[j].first;
    int plus_y = lock_y1 - one_key[j].second;
    int cnt =0;
    if(cnt == zero_size){
        return true;
    }
  //  printf("plusx : %d plusy : %d\n",plus_x,plus_y);
    for(int i=0;i<one_key.size();i++){
        int tempx = 40 + one_key[i].first + plus_x;
        int tempy = 40 + one_key[i].second + plus_y;
      //  printf("Tempx : %d tempy : %d i : %d\n",tempx,tempy,i);
        if(tempx>=40 && tempx <=40+N-1 &&tempy>=40 &&tempy <=40+N-1){
            if(map[tempx][tempy] == 1){
                 return false;
            }else{
          //      printf(" done tempx : %d tempy : %d\n",tempx,tempy);
               cnt++; 
            }
        }
    }
    if(cnt == zero_size){
        return true;
    }
    else{return false;}
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    vector <pair <int,int> > one_key;
    
    M = key.size();
    N = lock.size();
    for(int i=0;i<key.size();i++){
        for(int j=0;j<key[i].size();j++){
            if(key[i][j] == 1){
                one_key.push_back(make_pair(i,j));
            }
        }
    }
    for(int i=0;i<lock.size();i++){
        for(int j=0;j<lock[i].size();j++){
            map[i+40][j+40] = lock[i][j];
            if(lock[i][j] ==0){
                zero_lock.push_back(make_pair(i,j));
            }
        }
    }
    for(int rt=0;rt<=3;rt++){
        int zero_size = zero_lock.size();
        if(zero_size ==0){
            return true;
        }
        for(int i=0;i<zero_size;i++){
            int lock_x = zero_lock[i].first;
            int lock_y = zero_lock[i].second;
            for(int j=0;j<one_key.size();j++){ 
                bool check = can_check(lock_x,lock_y,one_key,j,zero_size);
                if(check == true){
                    printf("rt : %d\n",rt);
                    return true;
                }
            }
        }
        //이제 회전시키자잉 M이 키 사이즈이다잉
        for(int i=0;i<one_key.size();i++){
            int key_x = one_key[i].first;
            int key_y = one_key[i].second;
            one_key[i].first = key_y;
            one_key[i].second = M-1-key_x;
        }
    }

    return false;
}
