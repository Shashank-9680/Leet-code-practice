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
   bool dfs(TreeNode*node1,TreeNode*node2){
    if(node1==NULL&&node2==NULL) return true;

    if(node1==NULL||node2==NULL) return false;
      if(node1->val!=node2->val){
        return false;
      }
      bool val1=dfs(node1->left,node2->right);
      if(!val1) return false;
      bool val2=dfs(node1->right,node2->left);
      if(!val2) return false;
      return true;
   }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        if(root->left&&root->right==NULL){
            return false;
        }
        // if(root->right&&root->left==NULL){
        //     return false;
        // }
        TreeNode*temp1=root->left;
        TreeNode*temp2=root->right;
        if(!dfs(temp1,temp2)){
            return false;
        }
        return true;
    }
};