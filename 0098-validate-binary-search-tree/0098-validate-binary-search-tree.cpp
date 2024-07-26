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
    bool isValid(TreeNode* root, long long int min, long long int max) {
        if (root == NULL) {
            return true;
        }
        if (root->val <= min || root->val >= max) {
            return false;
        }
        bool left = isValid(root->left, min, root->val);
        bool right = isValid(root->right, root->val, max);
        return left && right;
    }
public:
   bool isValidBST(TreeNode* root) {
        return isValid(root, LLONG_MIN, LLONG_MAX);
    }
};