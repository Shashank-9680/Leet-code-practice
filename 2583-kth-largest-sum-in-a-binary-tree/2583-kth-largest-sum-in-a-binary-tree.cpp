class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        // if(k==1) return root->val;
        queue<pair<TreeNode*,int>>q;
        vector<pair<TreeNode*,int>>v;
        vector<long long int>ans;
     
        q.push({root,0});
       
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            TreeNode*temp=it.first;
            int count=it.second;
            v.push_back({temp,count});
            if(temp->left!=NULL) q.push({temp->left,count+1});
            if(temp->right!=NULL) q.push({temp->right,count+1});
        }
      int count=0;
        long long int sum=v[0].first->val;
      
       for(int i=1;i<v.size();i++){
           if(v[i].second==count){
               sum=sum+v[i].first->val;
           }
           else{
            ans.push_back(sum);
               count++;
             sum=v[i].first->val;
           }
       }
        ans.push_back(sum);
         
       
         if(k>ans.size()){
            return -1;
        }
         for(auto it:ans){
             cout<<it;
         }
       priority_queue<long long int,vector<long long int>,greater<long long int>>pq;
       for(auto it:ans){ 
               pq.push(it);
            if(pq.size()>k){
                pq.pop();
            }
       }  
      
    
       
        return pq.top();
    }
};