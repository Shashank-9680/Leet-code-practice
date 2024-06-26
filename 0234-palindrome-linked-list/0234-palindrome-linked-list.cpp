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
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return true;
        }
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            
            slow=slow->next;
            fast=fast->next->next;
           
        }
        ListNode*newHead=reverse(slow->next);
         ListNode*low=head;
            ListNode*high=newHead;
           while(high!=NULL){
               if(low->val!=high->val){
                   reverse(newHead);
                   return false;
               }
                low=low->next;
        high=high->next;
           }
       
        
            reverse(newHead);
               
        
     return true;
    }

};