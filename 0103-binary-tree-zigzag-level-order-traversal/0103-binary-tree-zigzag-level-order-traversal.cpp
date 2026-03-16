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
       vector<vector<int>>ans;
       queue<pair<TreeNode*,int>>q;
       q.push({root,0});
       if(root==NULL){
        return {};
       }
       while(!q.empty()){
        int size=q.size();
        vector<int>tempo;
        bool c=false;
        for(int i=0;i<size;i++){
            TreeNode*temp=q.front().first;
            int val=q.front().second;
            tempo.push_back(temp->val);
            if(val) c=true;
            q.pop();
            if(temp->left) q.push({temp->left,!val});
            if(temp->right) q.push({temp->right,!val});
        }
          if(!c) ans.push_back(tempo);
          else{
            reverse(tempo.begin(),tempo.end());
            ans.push_back(tempo);
          }
        }
        return ans;
    }
};