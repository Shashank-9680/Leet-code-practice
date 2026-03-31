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
ListNode*reverse(ListNode*head){
        ListNode*prev=NULL;
        ListNode*temp=head;
        while(temp){
            ListNode*nextNode=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nextNode;
        }
        return prev;
    }
    int Length(ListNode*head){
        ListNode*temp=head;
        int count=0;
        while(temp){
            count++;
            temp=temp->next;
        }
        return count;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
    int n = Length(head);

    ListNode* dummy = new ListNode(-1);
    ListNode* curr = dummy;
    ListNode* temp = head;

    for(int i = 0; i < n/k; i++){
        ListNode* groupStart = temp;

        int count = 1;
        while(count != k){
            temp = temp->next;
            count++;
        }

        ListNode* nextNode = temp->next;
        temp->next = NULL;

        curr->next = reverse(groupStart);

        while(curr->next){
            curr = curr->next;
        }

        temp = nextNode;
    }

    curr->next = temp;
    return dummy->next;
}
};