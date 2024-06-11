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
    int widthOfBinaryTree(TreeNode* root) {
      if (!root) return 0;

        queue<pair<TreeNode*,  long long>> q;
        q.push({root, 0});
        int maximum = 0;

        while (!q.empty()) {
            int size = q.size();
            long long min = q.front().second;
            long long first = 0, last = 0;

            for (int i = 0; i < size; ++i) {
                TreeNode* temp = q.front().first;
                long long currid = q.front().second - min;
                q.pop();

                if (i == 0) first = currid;
                if (i == size - 1) last = currid;

                if (temp->left) q.push({temp->left, 2 * currid + 1});
                if (temp->right) q.push({temp->right, 2 * currid + 2});
            }

            maximum = max(maximum, static_cast<int>(last - first + 1));
        }

        return maximum;
    }
};