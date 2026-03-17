/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
       queue<pair<Node*,int>>q;
       q.push({root,0});
      map<int,Node*>m;
       while(!q.empty()){
          int size=q.size();
          for(int i=0;i<size;i++){
               Node*temp=q.front().first;
           int col=q.front().second;
           q.pop();
           m.insert({col,temp});
           if(temp->left) q.push({temp->left,col-1});
           if(temp->right) q.push({temp->right,col+1});
          }
           
       }
       vector<int>ans;
       for(auto it:m){
           ans.push_back(it.second->data);
       }
       return ans;
       
        
    }
};