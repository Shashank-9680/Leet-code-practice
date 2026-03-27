// User function Template for C++

/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/
Node *deleteHead(Node *head) {
    
    Node*nextNode=head->next;
    nextNode->prev=NULL;
    head->next=NULL;
    delete head;
    return nextNode;
    
}
