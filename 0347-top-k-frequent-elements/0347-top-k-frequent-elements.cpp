class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        vector<int>v;
        priority_queue<pair<int,int>>pq;
        for(auto &value:m){
            pq.push({value.second,value.first});
        }
        while(k>0){
           v.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return v;
    }
};