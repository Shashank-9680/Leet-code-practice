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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>>v;
        queue<TreeNode*>q;
        if(root==nullptr){
           return v;
        }
         bool leftToRight = true;
        
        q.push(root);
        while(!q.empty()){
               int size=q.size();
            vector<int>level(size);
           
         
          
            for(int i=0;i<size;i++){
                TreeNode*temp=q.front();
                q.pop();
               if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
                int index = leftToRight ? i : size - 1 - i;
                level[index] = temp->val;
              
            }
           leftToRight = !leftToRight;
            v.push_back(level);
        }
        return v;
    }
    
};