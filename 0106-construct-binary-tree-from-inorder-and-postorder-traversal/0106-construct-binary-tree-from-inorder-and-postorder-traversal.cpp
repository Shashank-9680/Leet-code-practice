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
//       TreeNode*buildTree(vector<int>&postorder,int postStart,int postEnd,vector<int>&inorder,int inStart,int inEnd,unordered_map<int, int>& m){
//         if (postStart > postEnd || inStart > inEnd) return NULL;
        
//         TreeNode* newNode = new TreeNode(inorder[postStart]);
//         int inRoot = m[newNode->val];
//         int numsLeft = inRoot - inStart;
        
//         // newNode->left = buildTree(postorder, postEnd , postEnd +numsLeft-1, inorder, inStart, inRoot - 1, m);
//         // newNode->right = buildTree(postorder, postEnd +numsLeft, postStart-1, inorder, inRoot + 1, inEnd, m);
//           newNode->left = buildTree(postorder, postStart - numsLeft - 1, postEnd, inorder, inStart, inRoot - 1, m);
//         newNode->right = buildTree(postorder, postStart - 1, postStart - numsLeft, inorder, inRoot + 1, inEnd, m);
        
//         return newNode;
//     }
     TreeNode* buildTree(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& m) {
         if (postStart < postEnd || inStart > inEnd) return NULL;
        
        TreeNode* newNode = new TreeNode(postorder[postStart]);
        int inRoot = m[newNode->val];
        int numsLeft = inRoot - inStart;
         newNode->left = buildTree(postorder, postStart - (inEnd - inRoot) - 1, postEnd, inorder, inStart, inRoot - 1, m);
        newNode->right = buildTree(postorder, postStart - 1, postStart - (inEnd - inRoot), inorder, inRoot + 1, inEnd, m);
        
        
        return newNode;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> m;
        for (int i = 0; i < inorder.size(); i++) {
            m[inorder[i]] = i;      
        }
       
        return buildTree(postorder, postorder.size() - 1, 0, inorder, 0, inorder.size() - 1, m);
    }
    
};