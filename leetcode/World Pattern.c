#include <sstream>
#include <map>
using namespace std ;
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        stringstream ss(str);
        
        string token;
        vector <string> vs;
        while(ss >> token){
            vs.push_back(token);
            //cout << token <<" \n";
        }
    //    cout << vs.size() << "\n";
   //     cout << pattern.size() << "\n";
        map<int,string> m;
        map<string,int> n;
        if(pattern.size()!=vs.size()){return false;}
        
        for(int i=0;i<pattern.size();i++){
            int pt = pattern[i];
      //      cout << pt << "\n\n\n\n";
       //     cout << "i : "<<i << "\n";
            if(m.count(pt)==0){ //처음 발견했을 때 
                if(n.count(vs[i])!=0){return false;}//n에 이미 들어가 있으면 바로 false 
                //printf("%d\n",pattern[i]);
                
                m.insert(make_pair(pt,vs[i]));
                
                n.insert(make_pair(vs[i],pt));  
            }else{
       //         cout << "in else \n" ;
                if(m.at(pt) != vs[i]){
       //             cout << m[pt] <<" /// " << vs[i] <<" / "<<i << " 33333\n";
                    return false;
                }
            }
            
        }
        
        return true;
    };
};