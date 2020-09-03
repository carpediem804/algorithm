using namespace std;
class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        int max_time = -1;
        sort(A.begin(),A.end());
        do{
            int hour = A[0]*10 + A[1];
            int minute = A[2]*10 +A[3];
            
            if(hour < 24 && minute < 60){
                int next_time = hour*60 +minute;
                max_time = next_time >max_time ? next_time : max_time;
            }
            
        }while(next_permutation(A.begin(),A.end()));
        
        if(max_time ==-1){
            return "";
        }
        string ans = "";
        ans += to_string(max_time/60);
        if(max_time/60<10){
            ans = "0" + ans ;
        }
        ans = ans + ":";
       
        if(max_time%60 < 10){
            ans = ans + "0" +to_string(max_time%60);
        }
        else{
             ans = ans + to_string(max_time%60);
        }
        return ans ;
        
    }
};