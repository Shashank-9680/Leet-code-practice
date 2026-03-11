class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<pair<int,int>>adj[V];
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int
        >>>,greater<pair<int,pair<int,int>>>>pq;
        
        pq.push({0,{0,-1}});
        vector<int>vis(V,0);
        int sum=0;
        vector<pair<int,int>>ans;
        while(!pq.empty()){
            auto it=pq.top();
            int weight=it.first;
            int node=it.second.first;
            int parent=it.second.second;
            pq.pop();
            if(!vis[node]){
                vis[node]=1;
                sum=sum+weight;
                ans.push_back({parent,node});
            }
            else{
                continue;
            }
            
            for(auto it:adj[node]){
                if(!vis[it.first]){
                    pq.push({it.second,{it.first,node}});
                }
            }
            
        }
        return sum;
        
    }
};