/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
   int mini=-1;
  void dfs(Node*root,int x){
      if(root==NULL) return;
      if(root->data<=x){
          mini=max(mini,root->data);
          dfs(root->right,x);
      }
      else{
          dfs(root->left,x);
      }
      
  }
    int findFloor(Node* root, int x) {
        // code here
         dfs(root,x);
        if(mini==INT_MAX) return -1;
        return mini;
    }
};