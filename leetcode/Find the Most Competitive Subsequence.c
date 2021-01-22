class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int> s;
        for(int i=0;i<nums.size();i++){
            int check = nums[i];
            while(1){
                if(s.size()!=0 && s.top()> check && s.size()+nums.size()-i >k){
                    s.pop();
                }
                else{break;}
            } 
            if(s.size()<k){
                    s.push(check);
            }
        }
        stack<int> copy_s;
        while(!s.empty()){
           // printf("%d ",s.top());
            copy_s.push(s.top());
            s.pop();
        }
        vector<int> answer;    
        while(!copy_s.empty()){
            answer.push_back(copy_s.top());
            copy_s.pop();
        }
        
        
        return answer;
        
    }
};