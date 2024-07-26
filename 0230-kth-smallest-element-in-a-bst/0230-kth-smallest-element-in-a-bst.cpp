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
    int count=0;
    int result=-1;
    void inorder(TreeNode* root, int k) {
        if (root == NULL) {
            return;
        }

        // Traverse the left subtree
        inorder(root->left, k);

        // Visit the current node
        count++;
        if (count == k) {
            result = root->val;
            return;
        }

        // Traverse the right subtree
        inorder(root->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
     inorder(root,k);
        return result;
    }
};