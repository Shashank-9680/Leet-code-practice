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
    bool val=false;
    int dfs(TreeNode*root){
       if(root==NULL){
            return 0;
        }
        
            int val1= 1+dfs(root->left);
            int val2=1+dfs(root->right);
            if(abs(val1-val2)>1){
                val=true;
            }
            return max(val1,val2);
    }
public:
    bool isBalanced(TreeNode* root) {
        dfs(root);
        if(!val) return true;
        return false;
    }
};