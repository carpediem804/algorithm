class Solution {
public:
    int dp[101];
    int rob(vector<int>& nums) {
        int numsize = nums.size();
        int answer =0;
        for(int i=0;i<nums.size();i++){
            if(i==0){dp[i]=nums[i]; answer = dp[i];continue;}
            if(i==1){dp[i] = max(dp[0],nums[i]); answer = max(answer,dp[i]);continue;}
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
            answer = max(answer,dp[i]);
        }
         
        return answer;
    }
};