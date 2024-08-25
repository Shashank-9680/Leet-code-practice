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
    void fxn(TreeNode* root,vector<int>&postorder){
        if(root==NULL){
            return;
        }
        fxn(root->left,postorder);
        fxn(root->right,postorder);
        postorder.push_back(root->val);
        
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>postorder;
        fxn(root,postorder);
        return postorder;
    }
};