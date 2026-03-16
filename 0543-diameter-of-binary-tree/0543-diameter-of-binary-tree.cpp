class Solution {
public:
    int maxCount = 0;

    int dfs(TreeNode* root){
        if(root == NULL) return 0;

        int val1 = dfs(root->left);
        int val2 = dfs(root->right);

        maxCount = max(maxCount, val1 + val2);

        return 1 + max(val1, val2);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return maxCount;
    }
};