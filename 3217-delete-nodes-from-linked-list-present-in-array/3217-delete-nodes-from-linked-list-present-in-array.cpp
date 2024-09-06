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
    ListNode*convert(vector<int>&v){
        ListNode*head=new ListNode(v[0]);
        ListNode*temp=head;
        for(int i=1;i<v.size();i++){
            ListNode*newNode=new ListNode(v[i]);
            temp->next=newNode;
            temp=temp->next;
        }
        return head;
    }
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        vector<int>v;
        ListNode*temp=head;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp=temp->next;
        }
        // sort(v.begin(),v.end());
        // sort(nums.begin(),nums.end());
        vector<int>result;
        // int i=0;
        // int j=0;
//         while(j<v.size()){
//             if(nums[i]!=v[j]){
//                 result.push_back(v[j]);
//                 j++;
//             }
//             else{
//                 if(i!=nums.size()-1){
//                  i++;    
//                 }
               
//                 j++;
//             }
            
//         }
        unordered_map<int,int>m;
        for(auto it:nums){
            m[it]++;
        }
        for(int i=0;i<v.size();i++){
            if(m.find(v[i])==m.end()){
                result.push_back(v[i]);
            }
           
        }
        for(int i=0;i<result.size();i++){
            cout<<result[i];
        }
        return convert(result);
    }
};