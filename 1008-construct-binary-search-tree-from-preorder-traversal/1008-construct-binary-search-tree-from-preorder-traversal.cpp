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
    TreeNode*treemaking(int max,int &i,vector<int>&A){
        if(i==A.size()||A[i]>max){
            return NULL;
        }
        TreeNode*newNode=new TreeNode(A[i++]);
        newNode->left=treemaking(newNode->val,i,A);
        newNode->right=treemaking(max,i,A);
        return newNode;
        
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
       TreeNode*root= treemaking(INT_MAX,i,preorder);
    return root;
    }     
};