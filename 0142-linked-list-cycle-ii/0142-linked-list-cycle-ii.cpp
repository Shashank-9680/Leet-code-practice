/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode*find(ListNode*slow,ListNode*fast,ListNode*head){
       fast=head;
       while(fast!=slow){
        fast=fast->next;
        slow=slow->next;
       }
       return fast;
    }
public:
    ListNode *detectCycle(ListNode *head) {
           ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL&&fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                return find(slow,fast,head);
            }
        }
        return NULL;
    }
};