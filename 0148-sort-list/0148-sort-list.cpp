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
    ListNode *findMiddle(ListNode *head){
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
        
    }
    ListNode* merge(ListNode* first, ListNode* second)
{
 ListNode*t1=first;
 ListNode*t2=second;
 ListNode*dummyNode=new ListNode(-1);
 ListNode*t=dummyNode;
 while(t1!=NULL&&t2!=NULL){
     if(t1->val<t2->val){
        t->next=t1;
        t=t1;
        t1=t1->next;
     }
     else{
         t->next=t2;
         t=t2;
         t2=t2->next;
     }
 }
 if(t1){
  t->next=t1;
 }
 else{
     t->next=t2;
 }
 return dummyNode->next;
}
public:
       ListNode* sortList(ListNode* head) {
           if(head==NULL||head->next==NULL){
               return head;
           }
        ListNode*leftNode=head;
        
        ListNode*Middle=findMiddle(head);
        ListNode*RightNode=Middle->next;
      Middle->next=nullptr;
        leftNode= sortList(leftNode);
        
        RightNode=sortList(RightNode);
           
        return merge(leftNode,RightNode);
        
    }
};