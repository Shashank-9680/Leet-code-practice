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
    ListNode* mergeNodes(ListNode* head) {
        int sum=0;
        ListNode*temp=head;;
        ListNode*ptr=head->next;
        while(ptr!=NULL){
            sum=sum+ptr->val;
            if(ptr->val==0){
                ListNode*node=new ListNode(sum);
                temp->next=node;
                temp=node;
                // ptr=ptr->next;
                node->next=ptr->next;
                sum=0;
            }
            if(ptr!=NULL){
            ptr=ptr->next;     
            }
           
        }
        return head->next;
    }
};