class Solution {
public:
    bool isPalin(string &s ,int start,int end){
        
        while(start < end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }
    
    void dfs(vector<vector<string>> &result, string &s, int start, vector<string> &currentList) {
        if (start >= s.length()) result.push_back(currentList);
        for (int end = start; end < s.length(); end++) {
            if (isPalin(s, start, end)) {
                // add current substring in the currentList
                currentList.push_back(s.substr(start, end - start + 1));
                dfs(result, s, end + 1, currentList);
                // backtrack and remove the current substring from currentList
                currentList.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector <vector<string>> ans ;
        vector<string> temp;
        dfs(ans, s, 0, temp);
        return ans;
    }
};