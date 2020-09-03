#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    sort(participant.begin(),participant.end());
    sort(completion.begin(),completion.end());
    string answer = "";
    for(int i=0;i<completion.size();i++){
        if(completion[i]!=participant[i]){
            answer = participant[i];
            return answer;
        }
    }
    answer = participant[participant.size()-1];
    return answer;
}
