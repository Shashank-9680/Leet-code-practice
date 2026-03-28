/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
    int find(Node*slow,Node*fast){
        int count=1;
        slow=slow->next;
        while(fast!=slow){
             count++;
            slow=slow->next;
        }
        return count;
    }
    
  public:
    int lengthOfLoop(Node *head) {
        // code here
         Node*slow=head;
        Node*fast=head;
        while(fast!=NULL&&fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                return find(slow,fast);
            }
        }
        return 0;
    }
};