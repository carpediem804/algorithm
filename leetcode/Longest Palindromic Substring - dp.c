class Solution {
public:
    bool dp[1001][1001];
    string longestPalindrome(string s) {
        string ans = "";
        int maxlen = 0;
        for(int i=s.size()-1;i>=0;i--){ //시작점이 거꾸로 부터 임 
            for(int j=i ; j<s.size();j++ ){ //
               if(i==j){
                   dp[i][j]= true;
               }
               else if (s[i]==s[j]){
                    if(j-i==1){dp[i][j]=true;}
                    else{
                        dp[i][j] = dp[i+1][j-1];
                    }
               }
               
               if(dp[i][j] && j-i>= maxlen){
                   maxlen = j-i;
                   ans = s.substr(i,j-i+1);
               }
                
                
            }
        }
        return ans ;
    }
};