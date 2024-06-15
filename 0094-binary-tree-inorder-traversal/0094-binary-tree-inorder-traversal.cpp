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
//       void inOrderTraversal(TreeNode*root,vector<int>&v){
   
//     if(root==nullptr){
//         return;
//     }
   
//     inOrderTraversal(root->left,v);
//     v.push_back(root->val);
//     inOrderTraversal(root->right,v);


// }
public:
    vector<int> inorderTraversal(TreeNode* root) {
    //      vector<int>v;
    //     // inOrderTraversal(root,v);
    //     TreeNode*temp=root;
    //     stack<TreeNode*>st;
    //     if(root==NULL) return v;
    // while(true){
    //    if(temp!=NULL){     
    //        st.push(temp);
    //         temp=temp->left;
    //    }
    //     else{
    //         if(st.empty()) break;
    //         temp=st.top();
    //         st.pop();
    //         v.push_back(temp->val);
    //         temp=temp->right;
    //     }
    // }
// return v;
        vector<int>inorder;
        TreeNode*curr=root;
        while(curr!=NULL){
            if(curr->left==NULL){
                inorder.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode*prev=curr->left;
                while(prev->right&&prev->right!=curr){
                  prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    prev->right=NULL;
                    inorder.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return inorder;
    }
};