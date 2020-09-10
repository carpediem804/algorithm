using namespace std; 
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector <string> v1,v2;
        v1 = split(version1,'.');
        v2 = split(version2,'.');
    
        int v1size = v1.size();
        int v2size = v2.size();
        int maxsize = max(v1size,v2size);
        for(int i=0;i<maxsize;i++){
            int v1num =0;
            int v2num =0;
            if(i<v1size){v1num = stoi(v1[i]);}
            if(i<v2size){v2num = stoi(v2[i]);}
            if(v1num > v2num){return 1;}
            else if (v1num < v2num){return -1;}
        }
        
        return 0;
    }
    
    vector<string> split(string str, char delimiter) {
    vector<string> internal;
    stringstream ss(str);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        internal.push_back(temp);
    }
 
    return internal;
}



};