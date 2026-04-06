class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
          priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;
        pq.push({0,{0,0}});
        dist[0][0]=0;

        vector<pair<int,int>>dir={{-1,0},{0,-1},{1,0},{0,1}};

        while(!pq.empty()){
            int rootEffort=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            for(auto it:dir){
                int nrow=it.first+row;
                int ncol=it.second+col;
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m){
                    int val=max(rootEffort,abs(heights[nrow][ncol]-heights[row]
                    [col]));

                    if(dist[nrow][ncol]>val){
                        dist[nrow][ncol]=val;
                        pq.push({val,{nrow,ncol}});
                    }
                }
            }
        }

    return dist[n-1][m-1];
    }
};