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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1;
        
        queue<TreeNode*> q;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            long long levelSum = 0;
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                levelSum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            pq.push(levelSum);
            if (pq.size() > k) {
                pq.pop();  // Keep only the k largest sums in the priority queue
            }
        }

        return pq.size() == k ? pq.top() : -1;  
    }
};
