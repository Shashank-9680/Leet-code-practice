class Solution {
    static bool comp(pair<int,int>p1,pair<int,int>p2){
        if(p2.second==p1.second){
            return p1.first>p2.first;
        }
        else{
         return p2.second>p1.second;    
        }
       
    }
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n=nums.size();
        map<int,int>m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
       vector<pair<int,int>>v;
        for(auto it:m){
            v.push_back({it.first,it.second});
        }
        sort(v.begin(),v.end(),comp);
         vector<int>ans;
        for(auto it:v){
            for(int i=0;i<it.second;i++){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};