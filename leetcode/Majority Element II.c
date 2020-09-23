class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int size = nums.size();
        int pick = size/3;
        map<int,int> m;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            m[nums[i]] +=1;
        }
        for(auto iter = m.begin();iter!=m.end();iter++){
            if(iter->second >pick ){
                ans.push_back(iter->first);
            }
        }
        return ans;
    }
};