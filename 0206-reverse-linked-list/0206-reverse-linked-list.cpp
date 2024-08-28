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
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
      ListNode*temp=head;
        ListNode*curr=head;
        ListNode*prev=NULL;
        while(temp!=NULL){
            curr=curr->next;
            temp->next=prev;
            prev=temp;
            temp=curr;
        }
        return prev;
    }
};