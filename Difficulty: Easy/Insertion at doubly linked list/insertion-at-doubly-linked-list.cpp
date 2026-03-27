/*
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};
*/

class Solution {
  public:
    Node *insertAtPos(Node *head, int p, int x) {
        // code here
      if(head==NULL){
          Node*node=new Node(x);
          node->next=NULL;
          node->prev=NULL;
          return node;
      }
      Node*temp=head;
      int count=0;
      while(count!=p){
          temp=temp->next;
          count++;
      }
      Node*nextNode=temp->next;
      Node*newNode=new Node(x);
      if(nextNode){
          newNode->next=nextNode;
      }
      newNode->prev=temp;
      temp->next=newNode;
      if(nextNode){
          nextNode->prev=newNode;
      }
      return head;
    }
};