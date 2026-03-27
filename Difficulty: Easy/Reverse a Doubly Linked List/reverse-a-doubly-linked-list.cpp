/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        Node*temp=head;
       while(temp->next){
           temp=temp->next;
       }
       Node*newHead=temp;
       while(temp!=NULL){
           Node*prevNode=temp->prev;
           Node*nextNode=temp->next;
           temp->next=prevNode;
           temp->prev=nextNode;
           temp=prevNode;
       }
       return newHead;
        
    }
};