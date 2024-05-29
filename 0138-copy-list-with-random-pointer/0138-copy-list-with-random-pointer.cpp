/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
          if (!head) return nullptr;
       Node*temp=head;
        while(temp){
            Node*newNode=new Node(temp->val);
            newNode->next=temp->next;
            temp->next=newNode;
            temp=newNode->next;
            
        }
        temp=head;
        while(temp){
           if (temp->random) {
                temp->next->random = temp->random->next;
            } else {
                temp->next->random = nullptr;
            }
            temp=temp->next->next;
        }
        Node*dummy=new Node(-1);
        Node*curr=dummy;
        temp=head;
        while(temp){
            curr->next=temp->next;
            temp->next=temp->next->next;
            curr=curr->next;
            temp=temp->next;
        }
        return dummy->next;
    }
};