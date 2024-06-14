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
    TreeNode*buildTree(vector<int>&preorder,int preStart,int preEnd,vector<int>&inorder,int inStart,int inEnd,unordered_map<int, int>& m){
         if (preStart > preEnd || inStart > inEnd) return NULL;
        
        TreeNode* newNode = new TreeNode(preorder[preStart]);
        int inRoot = m[newNode->val];
        int numsLeft = inRoot - inStart;
        
        newNode->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, m);
        newNode->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, m);
        
        return newNode;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      unordered_map<int,int>m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;      
        }
        TreeNode*root=buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,m);
            return root;
    }
    
    
};