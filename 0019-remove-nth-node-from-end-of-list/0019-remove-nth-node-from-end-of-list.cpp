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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length=0;
        ListNode*curr=head;
        while(curr){
            length++;
            curr=curr->next;
        }
        int index=length-n;
        if(length==1) return NULL;
        curr=head;
        int count=0;
        ListNode*prev=NULL;
        while(count!=index){
            prev=curr;
            curr=curr->next;
            count++;
        }
        if(curr==head){
            head=head->next;
            curr->next=NULL;
            delete curr;
            return head;
        }
        ListNode*nextNode=curr->next;
        if(prev){
          prev->next=nextNode;
        }
        delete curr;
        return head;
    }
};