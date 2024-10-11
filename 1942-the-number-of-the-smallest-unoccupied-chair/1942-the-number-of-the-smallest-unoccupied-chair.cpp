class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
       int n=times.size();
        int arrTime=times[targetFriend][0];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq1;
        
        priority_queue<int,vector<int>,greater<int>>pq2;
        int chair=0;
       sort(times.begin(),times.end());
        for(auto it:times){
           while(!pq1.empty()&&pq1.top().first<=it[0]){
               auto ft=pq1.top();
               pq1.pop();
               pq2.push(ft.second);     
           }
            int currChair;
            if(pq2.empty()){
               currChair=chair;
                chair++;
            }
            else{
                currChair=pq2.top();
                pq2.pop();
            }
            if(it[0]==arrTime) return currChair;
            pq1.push({it[1],currChair});
        }
      return 0; 
    }
};