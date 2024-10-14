class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<pair<long long int,int>>q;
        for(int i=0;i<nums.size();i++){
            q.push({nums[i],i});
        }
        int count=0;
        long long int score=0;
        while(!q.empty()&&count!=k){
            auto it=q.top();
            score+=it.first;
            q.pop();
            long long val=ceil((it.first)/3.0);
           
            q.push({val,it.second});
            count++;
        }
        return score;
    }
};