/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

    
public:

  void markParent(TreeNode*root,unordered_map<TreeNode*,TreeNode*>&m,queue<TreeNode*>&q){
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            TreeNode*node=q.front();
            q.pop();
            if(node->left){
                m[node->left]=node;
                q.push(node->left);
            }
             if(node->right){
                m[node->right]=node;
                q.push(node->right);
            }
        }
    }
  }
 
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       unordered_map<TreeNode*,TreeNode*>m;
       queue<TreeNode*>q;
       markParent(root,m,q);
       unordered_map<TreeNode*,bool>visited;
       m[root]=NULL;
       queue<TreeNode*>a;
       a.push(target);

       visited[target]=true;
       int dis=0;
       while(true){
        int size=a.size();
        if(dis==k) break;
        dis++;
        for(int i=0;i<size;i++){
            TreeNode*node=a.front();
            a.pop();
            if(node->left&& !visited[node->left]){
                a.push(node->left);
                 visited[node->left]=true;
            }
            if(node->right&&!visited[node->right]){
                a.push(node->right);
                visited[node->right]=true;
            }
            if(m[node]!=NULL&&!visited[m[node]]){
                a.push(m[node]);
                visited[m[node]]=true;
            }
        }
       }
       vector<int>ans;
       while(!a.empty()){
        ans.push_back(a.front()->val);
        a.pop();
       }
       return ans;
    }
};