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
   
   TreeNode*fxn(int ub,vector<int>v,int &i){
       if(i==v.size()||v[i]>ub){
           return NULL;
       }
       TreeNode*root=new TreeNode(v[i++]);
       root->left=fxn(root->val,v,i);
       root->right=fxn(ub,v,i);
       return root;
   }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
    return fxn(INT_MAX,preorder,i);
        
    }
};