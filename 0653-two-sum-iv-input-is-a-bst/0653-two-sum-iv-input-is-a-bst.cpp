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
    bool inorder(TreeNode*root,int k,unordered_map<int,int>&m){
        if(root==NULL){
            return false;
        }
       if (inorder(root->left, k, m)) {
            return true;
        }
        int target=k-root->val;
        if(m.find(target)!=m.end()){
            return true;
        }
        m[root->val]=1;
          return inorder(root->right, k, m);
    }
public:
    bool findTarget(TreeNode* root, int k) {
      unordered_map<int, int> m;
        return inorder(root, k, m);
    }
};