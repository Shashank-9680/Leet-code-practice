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
//     void preOrderTraversal(TreeNode*root,vector<int>&v){
   
//     if(root==nullptr){
//         return;
//     }
//      v.push_back(root->val);
//     preOrderTraversal(root->left,v);
//     preOrderTraversal(root->right,v);


// }
public:
    vector<int> preorderTraversal(TreeNode* root) {
//    vector<int>v;
//         preOrderTraversal(root,v);
// return v;
        stack<TreeNode*>st;
        vector<int>v;
        if(root==nullptr){
            return v;
        }
         st.push(root);
        while(!st.empty()){
            root=st.top();
            v.push_back(root->val);
            st.pop();
            if(root->right!=NULL) st.push(root->right);
            if(root->left!=NULL) st.push(root->left);
        }
        return v;
    }
};