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
    ListNode*reverse(ListNode*head){
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
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // ListNode*temp=head;
         if(head==NULL||head->next==NULL){
           return NULL;
       }
        ListNode*newHead=reverse(head);
      
        if(n==1){
            
            ListNode*temp=newHead;
            newHead=newHead->next;
            delete temp;
           
            reverse(newHead);
            return head;
        }
        int count=0;
        ListNode*temp=newHead;
        ListNode *prev = NULL;
        while(temp){
            count++;
            if(count==n){
                prev->next=temp->next;
                  delete temp;
              break;
            }
            prev = temp;
         temp = temp->next;
        }
        head=reverse(newHead);
        return head;
    }
};