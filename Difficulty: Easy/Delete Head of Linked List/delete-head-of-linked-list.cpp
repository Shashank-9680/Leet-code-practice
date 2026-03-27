/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    Node *deleteHead(Node *head) {
        // code here
        Node*temp=head->next;
        head->next=NULL;
        delete head;
        return temp;
    }
};
