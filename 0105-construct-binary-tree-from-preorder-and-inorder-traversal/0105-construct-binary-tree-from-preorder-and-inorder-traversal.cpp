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
  TreeNode* dfs(vector<int>& preorder, vector<int>& inorder,
              int inStart, int inEnd,
              int preStart, int preEnd,
              unordered_map<int,int>& m) {

    if (inStart > inEnd || preStart > preEnd) return NULL;

    TreeNode* node = new TreeNode(preorder[preStart]);

    int index = m[node->val];              // root index in inorder
    int leftSize = index - inStart;        // number of nodes in left subtree

    // LEFT subtree
    node->left = dfs(preorder, inorder,
                     inStart, index - 1,
                     preStart + 1, preStart + leftSize,
                     m);

    // RIGHT subtree
    node->right = dfs(preorder, inorder,
                      index + 1, inEnd,
                      preStart + leftSize + 1, preEnd,
                      m);

    return node;
}
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int inStart=0;
        int inEnd=inorder.size()-1;
        int preStart=0;
        int preEnd=preorder.size()-1;
        unordered_map<int,int>m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        return dfs(preorder,inorder,inStart,inEnd,preStart,preEnd,m);
    }
};