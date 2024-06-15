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
       TreeNode*curr=root;
        if(root==NULL){
           TreeNode*newNode=new TreeNode(val);
            root=newNode;
            return root;
        }
        while(true){
            if(curr->val>val){
                 if(curr->left==NULL){
                  TreeNode*newNode=new TreeNode(val);
                     curr->left=newNode;
                    break;
                    
                }
               curr=curr->left;
               
                
            }
            else{
                 if(curr->right==NULL){
                    TreeNode*newNode=new TreeNode(val);
                     curr->right=newNode;
                    break;
                }
                curr=curr->right;
               
            }
        }
        return root;
    }
};