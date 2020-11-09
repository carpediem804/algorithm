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
    int dfs(TreeNode* root){
        int left = 0;
        if (root->left ){
            left = dfs(root->left);
        }
        int right = 0;
        if(root->right){
            right = dfs(root->right);
        }
        
        ans += abs(left-right);
        
        
        return left+ right + root->val;
    }
    int findTilt(TreeNode* root) {
        if(!root){return 0;}
        dfs(root);
        return ans;
    }
};