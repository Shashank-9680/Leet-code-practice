class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& interval, vector<int>& newInterval) {
        int n=interval.size();
      vector<vector<int>>v;
      int i=0;
        while(i<n &&interval[i][1]<newInterval[0]){
          v.push_back(interval[i]);
            i=i+1;
        }
        while(i<n&&interval[i][0]<=newInterval[1]){
            newInterval[0]=min(newInterval[0],interval[i][0]);
            newInterval[1]=max(newInterval[1],interval[i][1]);
            i=i+1;
        }
        v.push_back(newInterval);
        while(i<n){
            v.push_back(interval[i]);
            i=i+1;
        }
        return v;
    }
};