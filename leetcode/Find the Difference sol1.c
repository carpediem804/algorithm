class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char, int> m ;
        for(int i=0;i<s.size();i++){
                m[s[i]] +=1;
        }
        char ans ;
        for(int i=0;i<t.size();i++){
            if(m.find(t[i])!=m.end()){ //
                m[t[i]]-=1;
           
                if(m[t[i]]==0){
                    m.erase(t[i]);
                }
            }else{
                ans = t[i];
                return ans;
            }
        }
        return ans;
    }
};