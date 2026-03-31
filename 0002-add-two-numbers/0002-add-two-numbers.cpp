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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*temp1=l1;
        ListNode*temp2=l2;
        ListNode*newHead=new ListNode(-1);
        ListNode*temp=newHead;
        int carry=0;
        while(temp1&&temp2){
             
             int sum=temp1->val+temp2->val+carry;
            carry=sum/10;
            ListNode* newNode=new ListNode(sum%10);
            temp->next=newNode;
            temp=newNode;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1){
            int sum=temp1->val+carry;
            carry=sum/10;
            ListNode* newNode=new ListNode(sum%10);
            temp->next=newNode;
            temp=newNode;
            temp1=temp1->next;
        }
        while(temp2){
            int sum=temp2->val+carry;
            carry=sum/10;
            ListNode* newNode=new ListNode(sum%10);
            temp->next=newNode;
            temp=newNode;
            temp2=temp2->next;
        }
        if(carry){
           ListNode*newNode=new ListNode(carry);
           temp->next=newNode;
           temp=newNode;
           return newHead->next;
        }
        return newHead->next;
    }
};