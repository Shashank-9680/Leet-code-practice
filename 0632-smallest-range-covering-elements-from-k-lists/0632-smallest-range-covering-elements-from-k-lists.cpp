class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ans(2);
        
      
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        int maxi = INT_MIN;  
        
      
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i][0], {i, 0}});
            maxi = max(maxi, nums[i][0]); 
        }
        
        int mini = pq.top().first; 
        int start = mini, end = maxi;
        
        while (!pq.empty()) {
          
            auto it = pq.top();
            pq.pop();
            mini = it.first; 
            int i = it.second.first;  
            int j = it.second.second; 
            
         
            if (maxi - mini < end - start) {
                start = mini;
                end = maxi;
            }
            
          
            if (j + 1 < nums[i].size()) {
                pq.push({nums[i][j + 1], {i, j + 1}});  
                maxi = max(maxi, nums[i][j + 1]); 
            } else {
               
                break;
            }
        }
        
     
        return {start, end};
    }
};
