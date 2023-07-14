class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        vector<vector<int>>v;
        v.push_back(intervals[0]);
        int j=0;
        for(int i=1;i<n;i++){
            if(v[j][1]>=intervals[i][0]){
                v[j][1]=max(v[j][1],intervals[i][1]);
            }
            else{
                v.push_back(intervals[i]);
                j++;
            }
        }
        return v;
    }
};