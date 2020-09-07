using namespace std ;
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string pattern = s.substr(1) + s.substr(0,s.length()-1);
        return pattern.find(s) !=string ::npos;
    }
};