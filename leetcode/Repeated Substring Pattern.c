using namespace std ;
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int i=1,j=0,n=s.size();
        vector<int> dp(n+1,0);
        while(i<n){
            
            if(s[i]==s[j]){ //같은 문자열이 있을 때 
                dp[++i] = ++j; //i와 j를 증가시키고 dp의 값에 그전 i의 값보다 +1한다 
            }
            else{
                if(j==0){//j는 접두사 == 시작점일때 
                    i++; //접미사 비교 그걸 늘린다 ?? 왜 늘려 ?? 
                } //j가 접두사 
                else{
                    j = dp[j];
                }
            }
        }
        bool result = dp[n] && (dp[n]%(n-dp[n])== 0);
        return result ;
                                }
};