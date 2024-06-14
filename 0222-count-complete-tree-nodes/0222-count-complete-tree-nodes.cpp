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
    int findleftheight(TreeNode*root){
        int count=0;
        while(root){
            count++;
            root=root->left;
        }
        return count;
    }
    int findrightheight(TreeNode*root){
         int count=0;
        while(root){
            count++;
            root=root->right;
        }
        return count;
    }
    
public:
    int countNodes(TreeNode* root) {
//         if(root==NULL) return 0;
//         queue<TreeNode*>q;
//         q.push(root);
//         int count=0;
//         while(!q.empty()){
//             TreeNode*temp=q.front();
//             q.pop();
//             if(temp->left!=NULL){
//                 count++;
//                 q.push(temp->left);
                
//             }
//             if(temp->right!=NULL){
//                  count++;
//                 q.push(temp->right);
               
//             }
            
//         }
//         return count+1;
        if(root==NULL) return 0;
        int lf=findleftheight(root);
        int rt=findrightheight(root);
        if(lf==rt) return (1<<lf)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};