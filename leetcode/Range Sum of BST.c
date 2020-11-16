/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    void dfs(TreeNode * root,vector<int>& nums){
        if(!root){return;}
        dfs(root->left,nums); //왼쪽 쭉 깊게 가고 
        nums.push_back(root->val);
        dfs(root->right,nums); //그다음 오른쪽 쭉쭉쭉 
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        //low <= val <=high 인 모든 val의 합 구하기 
        vector<int> nums;
        dfs(root,nums);
        for(auto e : nums){
            if(e>=low && e<=high) ans +=e;
        }
        return ans ;
    }
};