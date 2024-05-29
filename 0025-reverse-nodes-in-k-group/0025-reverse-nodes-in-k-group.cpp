/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode *current=head;
        ListNode*newHead=NULL;
        ListNode* prev=NULL;
         ListNode*nextNode=NULL;
        while(current!=NULL){
            nextNode=current->next;
            current->next=prev;
            
             prev = current;
            current = nextNode;
           
        }
        newHead=prev;
        return newHead;
    }
    
    ListNode*findKthNode(ListNode*head,int k){
        int count=0;
        ListNode*temp=head;
        while(temp){
            count++;
           
            if(count==k){
                return temp;
            }
             temp=temp->next;
            
        }
        return head;
    }
    
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
         ListNode*temp=head;
        ListNode*(prevNode)=NULL;
    while(temp!=NULL){
         ListNode*kNode=findKthNode(temp,k);
        if(kNode==NULL){
            if(prevNode)  prevNode->next=temp;
            break;
        }
       ListNode*nextNode=kNode->next;  
       
        kNode->next=nullptr;
        ListNode*newHead=reverseList(temp);
        if(temp==head){
            head=newHead;
        }
        else{
             prevNode->next=kNode; 
          
        }
          prevNode=temp;
        temp=nextNode;
            
    }
        return head;
    }    
   
};