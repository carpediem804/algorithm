class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int i=0;
        while(i<seats.size() && seats[i]!=0){
            i++;
        } // i == 사람이 앉아있는 의자 수  
        
        int maxdistance = 0;
        int seated=-1;
        int count =0;
        while(i<seats.size()){
           // printf("i : %d maxdis : %d\n",i,maxdistance);
            seated = i;
           
            
            while(i<seats.size()&& seats[i]==0){ //지금 보는 점이 빈 점이면 
              
                i++;
            }//내 index보다 오른쪽으로 max 값 찾기 
            
            int empty = i-seated;//오른쪽 최대 distance 
            
            if(seated==0 || i==seats.size()){
                maxdistance=max(maxdistance,empty);
            }
            
            maxdistance = max(maxdistance,(empty+1)/2);
            
            while(i<seats.size() && seats[i]!=0){//앉아 있는 만큼 i 증가 
                i++;
            }
            
        }
        return maxdistance;
        
        
    }
};