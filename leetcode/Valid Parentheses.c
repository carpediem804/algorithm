class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            char check = s[i];
            if(check == ')' || check =='}' || check ==']'){
                if(st.size()==0){return false;}
                int st_out = st.top();
                st.pop();
                if(check ==')' && st_out =='(' ){continue;}
                if(check == '}' && st_out =='{'){continue;}
                if(check == ']' && st_out =='['){continue;}
                return false;
            }
            else{
                st.push(check);
            }
        }
        if(st.size()!=0){return false;}
        return true;
    }
};