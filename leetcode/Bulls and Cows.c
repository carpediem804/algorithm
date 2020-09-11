#include <string>

using namespace std;
class Solution {
public:
    string getHint(string secret, string guess) {
        int secret_num[10] = {0,};
        int guess_num[10] = {0,};
        int strike_num =0;
        for(int i=0;i<secret.size();i++){
        
             secret_num[secret[i]-'0'] +=1;
             guess_num[guess[i]-'0']+=1;
            if(secret[i]==guess[i]){strike_num++;}
        }
        int ball_num = 0;
        for(int i=0;i<10;i++){
            ball_num += min(secret_num[i],guess_num[i]);
        }
        
        
        
        string ans ="";
        ans +=to_string(strike_num);
        ans += "A";
        ans += to_string(ball_num-strike_num);
        ans += "B";
        return ans ;
    }
};