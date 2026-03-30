/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        int count0s=0;
        int count1s=0;
        int count2s=0;
        while(head!=NULL){
            if(head->data==0) count0s++;
            if(head->data==1) count1s++;
            if(head->data==2) count2s++;
            head=head->next;
        }
      Node*newHead=new Node(-1);
        Node*temp=newHead;
        while(count0s>0){
            temp->next=new Node(0);
            temp=temp->next;
            count0s--;
        }
         while(count1s>0){
            temp->next=new Node(1);
            temp=temp->next;
             count1s--;
        }
         while(count2s>0){
            temp->next=new Node(2);
            temp=temp->next;
             count2s--;
        }
        return newHead->next;
    }
};