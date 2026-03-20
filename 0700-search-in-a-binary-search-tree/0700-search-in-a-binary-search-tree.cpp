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
    TreeNode*value=NULL;
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL) return NULL;
        if(root->val==val){
            value=root;
            cout<<value;
            return root;
        }
        if(root->val>val){
            TreeNode*node=searchBST(root->left,val);
        }
        else if(root->val<val){
          TreeNode*node=searchBST(root->right,val);
        }

       if(value!=NULL){
        return value; 
       }
       return NULL;
    }
};