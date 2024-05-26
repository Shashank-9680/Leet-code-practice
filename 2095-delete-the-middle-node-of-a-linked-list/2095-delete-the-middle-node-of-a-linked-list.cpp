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
     ListNode* middleNode(ListNode* head) {
       ListNode*fast=head;
        ListNode*slow=head;
         
        while(fast!=NULL&&fast->next!=NULL){
           
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode*Middle=middleNode(head);
        ListNode*temp=head;
        ListNode*prev=NULL;
        
      
        while(temp!=Middle){
            prev=temp;
            temp=temp->next;
        }
        if(prev==NULL){
            return NULL;
        }
            if(temp==Middle){
                prev->next=temp->next;
                delete temp;
            }
        return head;
    }
};