class Solution {
public:
    char findTheDifference(string s, string t) {
        int n=s.size();
        int sum_s=0,sum_t=0;
		// Summing the characters to find the difference between strings.
        for(int i=0;i<n;i++){
            sum_s+=s[i];
            sum_t+=t[i];
        }
        sum_t+=t[n]; // Since the length of t is one more than s.
        return char(sum_t-sum_s);
    }
};