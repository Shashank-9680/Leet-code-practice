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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*>left;
        queue<TreeNode*>right;
        left.push(root->left);
        right.push(root->right);
         if (root == nullptr) return true;
       
        while(!left.empty()&&!right.empty()){
            TreeNode*temp1=left.front();
             TreeNode*temp2=right.front();
            left.pop();
            right.pop();
              if (temp1 == nullptr && temp2 == nullptr) continue;
            if (temp1 == nullptr || temp2 == nullptr) return false;
           
             if (temp1->val != temp2->val) return false;
            
            left.push(temp1->left);
            left.push(temp1->right);
            right.push(temp2->right);
            right.push(temp2->left);
        }
        return true;
    }
};