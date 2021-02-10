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
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        travel(root, sum);
        return root;        
    }
    void travel(TreeNode* root, int& sum){
        
        if(!root) return;
       // printf("val : %d sum : %d\n",root->val,sum);
        travel(root->right, sum);
      //  printf("after right : val : %d sum : %d\n",root->val,sum);
        root->val += sum;
        sum = root->val;
        travel(root->left, sum);
     //   printf("after left : val : %d sum : %d\n",root->val,sum);
    }
};