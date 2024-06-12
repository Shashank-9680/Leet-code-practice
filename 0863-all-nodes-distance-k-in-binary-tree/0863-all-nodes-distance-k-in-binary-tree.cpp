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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*>m;
        queue<TreeNode*>q;
        
        vector<int>result;
        unordered_map<TreeNode*,bool>visited;
        q.push(root);
        while(!q.empty()){
            TreeNode*temp=q.front();
            q.pop();
            if(temp->left!=NULL){
                q.push(temp->left);
                m[temp->left]=temp;
            }
            if(temp->right!=NULL){
                 q.push(temp->right);
                m[temp->right]=temp;
            }
        }
        q.push(target);
         visited[target] = true;
        int distance=0;
        while(!q.empty()){
            if (distance == k) {
                while(!q.empty()) {
                    result.push_back(q.front()->val);
                    q.pop();
                }
                return result;
            }
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode*temp=q.front();
                q.pop();
                if (temp->left && !visited[temp->left]) {
                    q.push(temp->left);
                    visited[temp->left] = true;
                }
                 if (temp->right && !visited[temp->right]) {
                    q.push(temp->right);
                    visited[temp->right] = true;
                }
                 if (m.find(temp) != m.end() && !visited[m[temp]]) {
                    q.push(m[temp]);
                    visited[m[temp]] = true;
                }
            }
            distance++;
        }
        
        
        return result;
    }
    
};