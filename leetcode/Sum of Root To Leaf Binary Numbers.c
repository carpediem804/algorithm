using namespace std ;
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
    vector <string> s;
    int sumRootToLeaf(TreeNode* root) {
        return maketwo(root,0);
    }
    long long maketwo(TreeNode* another,long long  num){
        if(another==NULL){return 0;}
        num = num <<1;
        num += another->val;
        if(another->left ==NULL && another->right ==NULL){
            return num;
        }
        return maketwo(another->left,num) + maketwo(another->right,num);
    }
};