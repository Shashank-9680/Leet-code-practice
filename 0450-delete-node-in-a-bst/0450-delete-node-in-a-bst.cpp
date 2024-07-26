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
     TreeNode*helper(TreeNode*root){
            if(root->left==NULL){
                return root->right;
            }
            else if(root->right==NULL){
                return root->left;
            }
            TreeNode*temp=root->right;
            TreeNode*lastNode=findLastNode(root->left);
            lastNode->right=temp;
            return root->left;
            
        }
        TreeNode*findLastNode(TreeNode*root){
            if(root->right==NULL){
                return root;
            }
            return findLastNode(root->right);
        }
    
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode*curr=root;
        if(root==NULL){
            return NULL;
        }
        if(root->val==key){
            return helper(root);
        }
        while(root!=NULL){
            if(root->val<key){
                if(root->right!=NULL&&root->right->val==key){
                    root->right=helper(root->right);
                }
                else{
                    root=root->right;
                }
            }
            else{
                if(root->left!=NULL&&root->left->val==key){
                    root->left=helper(root->left);
                }
                else{
                    root=root->left;
                }
            }
        }
       
        return curr;
    }
};