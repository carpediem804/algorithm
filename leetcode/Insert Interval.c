class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        
        if (n == 0) // edge case #1: no intervals in original list
            return {newInterval};
        
        if (intervals[n-1][1] < newInterval[0]) { // edge case #2: new interval goes in the end of the list with no overlap
            intervals.push_back(newInterval);
            return intervals;
        }
        vector<vector<int>> res;
        int i = 0;
        for(; i<n; i++) {
            
            if (intervals[i][1] < newInterval[0]) // new interval doesn't overlap
                res.push_back(intervals[i]);
            else {
                int first = min(intervals[i][0], newInterval[0]);
                int last = newInterval[1];
                
                while (i < n && last >= intervals[i][0]) { // while new interval overlaps:
                    last = max(intervals[i][1], newInterval[1]);
                    i++;
                }
                res.push_back({first, last});
                break;
            }
        }
        
        while (i < n) { // add the rest
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};