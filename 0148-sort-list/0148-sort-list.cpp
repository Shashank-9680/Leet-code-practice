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
    ListNode* sortList(ListNode* head) {
        if(head==NULL) return head;
        vector<int>ans;
        while(head!=NULL){
            ans.push_back(head->val);
            head=head->next;
        }
        sort(ans.begin(),ans.end());
        int a=ans.size();
        ListNode*newHead=new ListNode(ans[0]);
        ListNode*temp=newHead;
       for(int i=1;i<a;i++){
         ListNode*newNode=new ListNode(ans[i]);
          temp->next=newNode;
          temp=newNode;
       }
       return newHead;
    }
};