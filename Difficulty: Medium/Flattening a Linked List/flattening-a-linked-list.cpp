/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
    
    Node* merge(Node* a, Node* b){
        Node* dummy = new Node(-1);
        Node* curr = dummy;

        while(a && b){
            if(a->data <= b->data){
                curr->bottom = a;
                a = a->bottom;
            } else {
                curr->bottom = b;
                b = b->bottom;
            }
            curr = curr->bottom;
        }

        if(a) curr->bottom = a;
        if(b) curr->bottom = b;

        return dummy->bottom;
    }
  public:
  
    Node*dfs(Node*temp){
        if(temp->next&&temp->next->next==NULL){
            return merge(temp,temp->next);
        }
        Node*node=dfs(temp->next);
        return merge(temp,node);
    }
    Node *flatten(Node *root) {
        Node*temp=root;
        if(temp->next==NULL){
            return root;
        }
        return dfs(temp);
        
    }
};