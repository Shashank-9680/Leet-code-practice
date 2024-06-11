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
    vector<int> rightSideView(TreeNode* root) {
       vector<int>v;
     queue<pair<TreeNode*,int>>q;
        map<int,int>m;
        if(root==NULL){
            return v;
        }
     
      q.push({root,0});
      while(!q.empty()){
         auto p=q.front();
          TreeNode*temp=p.first;
          q.pop();
          int y=p.second;
          m.insert({y,temp->val});
          if(temp->right!=NULL) q.push({temp->right,y+1});
            if(temp->left!=NULL) q.push({temp->left,y+1});
            
          
          
      
      }
       for(auto &value:m){
            v.push_back(value.second);
        } 
      return v;   
    }
};