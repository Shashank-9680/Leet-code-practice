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
    int maxDepth(TreeNode* root) {
       if(root==NULL) return 0;
        int lf=maxDepth(root->left);
        int rf=maxDepth(root->right);
        if(lf==-1) return -1;
        if(abs(lf-rf)>1) return -1;
        if(rf==-1) return -1;
        return 1+max(lf,rf);
    }
public:
    bool isBalanced(TreeNode* root) {
        
        int a=maxDepth(root);
        if(a==-1){
            return false;
        }
        else{
            return true;
        }
    }
    
};