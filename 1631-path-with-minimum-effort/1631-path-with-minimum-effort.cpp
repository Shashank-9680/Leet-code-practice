class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        pq.push({0,{0,0}});

        vector<pair<int,int>> neig = {
            {-1,0},{1,0},{0,-1},{0,1}
        };

        while(!pq.empty()){

            int dis = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            for(auto it: neig){

                int nrow = row + it.first;
                int ncol = col + it.second;

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){

                    int diff = abs(heights[nrow][ncol] - heights[row][col]);

                    int newEffort = max(dis, diff);

                    if(newEffort < dist[nrow][ncol]){

                        dist[nrow][ncol] = newEffort;

                        pq.push({newEffort,{nrow,ncol}});
                    }
                }
            }
        }

        return dist[n-1][m-1];
    }
};