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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
      int count=2;
        vector<int>v;
        ListNode*prev=head;
        ListNode*temp=head->next;
        while(temp->next!=NULL){
            if(prev->val<temp->val&&temp->val>temp->next->val){
                v.push_back(count);
            }
            else if(prev->val>temp->val&&temp->val<temp->next->val){
                v.push_back(count);
            }
            prev=prev->next;
            temp=temp->next;
            count++;
        }
        if(v.size()<=1){
            return {-1,-1};
        }
        sort(v.begin(),v.end());
        int n=v.size();
        int max=v[n-1]-v[0];
        int mini=INT_MAX;
        for(int i=1;i<n;i++){
            mini=min(mini,v[i]-v[i-1]);
        }
        return {mini,max};
    }
};