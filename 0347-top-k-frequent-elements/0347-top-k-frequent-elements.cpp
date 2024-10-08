class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
      unordered_map<int,int>m;
        for(auto it:nums){
            m[it]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        for(auto it:m){
           q.push({it.second,it.first});
            if(q.size()>k){
                q.pop();
            }
        }
        while(k--){
            
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};