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
              queue<pair<TreeNode*,int>>q;
       q.push({root,0});
      map<int,TreeNode*>m;
      if(root==NULL) return {};
       while(!q.empty()){
          int size=q.size();
          for(int i=0;i<size;i++){
               TreeNode*temp=q.front().first;
           int row=q.front().second;
           q.pop();
           m[row]=temp;
           if(temp->left) q.push({temp->left,row+1});
           if(temp->right) q.push({temp->right,row+1});
          }
           
       }
       vector<int>ans;
       for(auto it:m){
           ans.push_back(it.second->val);
       }
       return ans;
    }
};