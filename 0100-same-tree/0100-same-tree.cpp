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
    bool dfs(TreeNode* p, TreeNode* q){
        if(p==NULL&&q==NULL){
            return true;
        }
        if(q==NULL||p==NULL){
            return false;
        }
        
        if(p->val!=q->val){
            return false;
        }
        bool val1= isSameTree(p->left,q->left);
        if(!val1) return false;
         bool val2= isSameTree(p->right,q->right);
        if(!val2) return false;
        return val1&&val2;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!dfs(p,q)){
            return false; 
        }
        return true;
    }
};