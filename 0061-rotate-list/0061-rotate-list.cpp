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
int totalElements(ListNode*head){
    int count=0;
    ListNode*temp=head;
    while(temp){
        count++;
        temp=temp->next;
    }
    return count;
}
ListNode*findNminusk(ListNode*head,int k,int n){
    int count=0;
    ListNode*temp=head;
    while(temp){
        count++;
        if(count==n-k){
           return temp; 
        }
        temp=temp->next;
    }
    return temp;
}
public:
    ListNode* rotateRight(ListNode* head, int k) {
    
  int n=totalElements(head);
        if(head==NULL){
            return NULL;
        }
        if(k%n==0){
            return head;
        }
        else{
            k=k%n;
        }
        ListNode*findNMinusk=findNminusk(head,k,n);
        ListNode*temp=head;
        while(temp->next){
            temp=temp->next;
        }
      temp->next=head;
        head=findNMinusk->next;
            
        findNMinusk->next=nullptr;
         return head;
    }
   
};