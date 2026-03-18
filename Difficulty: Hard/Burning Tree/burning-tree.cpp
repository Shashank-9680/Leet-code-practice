/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
   void markParent(Node*root,unordered_map<Node*,Node*>&m,queue<Node*>&q){
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            Node*node=q.front();
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
  
  Node* findTarget(Node*root,int val){
      if(root==NULL){
          return NULL;
      }
      if(root->data==val){
          return root;
      }
      Node* Left=findTarget(root->left,val);
      Node* Right=findTarget(root->right,val);
      if(Left==NULL&&Right==NULL) return NULL;
      if(Left==NULL&&Right!=NULL) return Right;
      return Left;
  }
  
    int minTime(Node* root, int target) {
       unordered_map<Node*,Node*>m;
       queue<Node*>q;
       markParent(root,m,q);
       Node*tar=findTarget(root,target);
       unordered_map<Node*,bool>visited;
       m[root]=NULL;
       queue<Node*>a;
       a.push(tar);
       visited[tar]=true;
       int dis=0;
       while(!a.empty()){
        int size=a.size();
        bool burnt=false;
        for(int i=0;i<size;i++){
            Node*node=a.front();
            a.pop();
            if(node->left&& !visited[node->left]){
                 a.push(node->left);
                 visited[node->left]=true;
                 burnt=true;
            }
            if(node->right&&!visited[node->right]){
                a.push(node->right);
                visited[node->right]=true;
                 burnt=true;
            }
            if(m[node]!=NULL&&!visited[m[node]]){
                a.push(m[node]);
                visited[m[node]]=true;
                 burnt=true;
            }
        }
        if(burnt) dis++;
       }
       return dis;
        
    }
};