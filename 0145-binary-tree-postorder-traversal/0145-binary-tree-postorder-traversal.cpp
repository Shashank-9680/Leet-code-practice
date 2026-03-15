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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*>st1;
        stack<int>st2;
        if(root!=NULL) st1.push(root);
        else return {};
        while(!st1.empty()){
            TreeNode*temp=st1.top();
            st1.pop();
            st2.push(temp->val);
            if(temp->left!=nullptr) st1.push(temp->left);
            if(temp->right!=nullptr) st1.push(temp->right);
        }
        vector<int>ans;
        while(!st2.empty()){
            ans.push_back(st2.top());
            st2.pop();
        }
        return ans;
    }
};