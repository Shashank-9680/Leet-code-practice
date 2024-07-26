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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
       
      TreeNode*temp=root;
        if(root==NULL){
            TreeNode*newNode=new TreeNode(val);
            return newNode;
        }
        TreeNode* temp1=NULL;
        while(temp!=NULL){
            if(temp->val>val){
                temp=temp->left;
            }
            else{
                 temp1=temp;
                 temp=temp->right;
            }
        }
        
        TreeNode*temp2=NULL;
        TreeNode*newNode=new TreeNode(val);
        if(temp1==NULL){
         TreeNode*newNode=new TreeNode(val);
            newNode->right=root;
            return newNode;
        }
        if(temp1->right==NULL){
            temp1->right=newNode;
            return root;
        }
        temp2=temp1->right;
        temp1->right=newNode;
        newNode->right=temp2;
        return root;
        
    }
};