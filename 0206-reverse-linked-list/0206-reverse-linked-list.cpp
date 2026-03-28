class Solution {

    ListNode* reverse(ListNode* head) {
        if (head == NULL||head->next==NULL) {
            return head;
        }
        ListNode*newHead=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return newHead;
    }

public:
    ListNode* reverseList(ListNode* head) {
        ListNode*newHead=reverse(head);
        return newHead;
    }
};