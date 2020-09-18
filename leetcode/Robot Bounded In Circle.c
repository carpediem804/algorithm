using namespace std;
class Solution {
public:
     bool check_origin(unordered_map<char,int> map){
        
        if(map['N'] == map['S'] && map['E'] == map['W']) //방향 움직인 횟수가 다 같아야 된다 !!!!!! 
            return true;
        return false;
    }
    bool isRobotBounded(string instructions) {
         char curr_dir = 'N';
    
        unordered_map<char,int> map;
        
        for(int i=0;i<instructions.length();i++){ 
            if(instructions[i] == 'G'){
                map[curr_dir]++;
            }
            else{
                char incoming = instructions[i];
                if(curr_dir == 'N'){
                    curr_dir = incoming == 'L' ? 'W' : 'E';
                }
                else if(curr_dir == 'W'){
                    curr_dir = incoming == 'L' ? 'S' : 'N';
                }
                else if(curr_dir == 'S'){
                    curr_dir = incoming == 'L' ? 'E' : 'W';
                }
                else{
                    curr_dir = incoming == 'L' ? 'N' : 'S';
                }
            } 
            
        }
        if(check_origin(map) || curr_dir!='N')
            return true;
        
        return false;
    }
};