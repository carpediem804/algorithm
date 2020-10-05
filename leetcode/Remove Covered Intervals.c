class Solution {
public:
    static bool compare (vector<int>& a, vector<int>& b){
        if(a[0]==b[0]){
            return a[1] > b[1];
        }
        return a[0]< b[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        int ans =1;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i=0;i<intervals.size();i++){
            if(start <= intervals[i][0] && end >= intervals[i][1]){
                continue;
            }
            ans ++;
            start = min(start,intervals[i][0]);
            end = max(end,intervals[i][1]);
        }
        return ans ;
    }
    
};