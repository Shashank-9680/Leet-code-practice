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
public:
    ListNode* rotateRight(ListNode* head, int k) {
       ListNode*newHead=reverse(head);
    //    cout<<newHead->val;
       int n=Length(newHead);
       if(head==NULL) return head;
       cout<<n;
       k=k%n;
       cout<<k;
       if(k==0) return reverse(newHead);
       cout<<k;
       ListNode*temp=newHead;
       int count=1;
       while(count!=k){
        count++;
        temp=temp->next;
       }

       ListNode*node=temp->next;
       temp->next=NULL;
       ListNode*newwHead=reverse(newHead);
       ListNode*newNode=reverse(node);
       
       newHead->next=newNode;
       return newwHead;
    }
};