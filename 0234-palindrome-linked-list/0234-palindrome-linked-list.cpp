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
    ListNode*reverse(ListNode*temp){
        ListNode*prev=NULL;
        while(temp!=NULL){
        ListNode*nextNode=temp->next;
        temp->next=prev;
         prev=temp;
        temp=nextNode;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
       ListNode*slow=head;
       ListNode*fast=head;
       while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
       }
       ListNode*curr=reverse(slow);
       slow=head;
       while(curr!=NULL){
         if(slow->val!=curr->val){
            return false;
         }
        curr=curr->next;
        slow=slow->next;
       }
        return true;
    }
};