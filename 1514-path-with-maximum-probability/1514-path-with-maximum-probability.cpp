class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
      vector<pair<int,double>>adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
             adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<double>prob(n,0.0);
        prob[start_node]=1.0;
        priority_queue<pair<double,int>>pq;
        pq.push({1.0,start_node});
        while(!pq.empty()){
            int node=pq.top().second;
            double pro=pq.top().first;
            pq.pop();
             if (node == end_node) return pro;
            for(auto it:adj[node]){
                if(it.second*pro>prob[it.first]){
                    prob[it.first]=it.second*pro;
                    pq.push({prob[it.first],it.first});
                }
            }
        }
        return 0.0;
    }
};