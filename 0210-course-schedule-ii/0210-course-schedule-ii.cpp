class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& edges) {
          vector<int>adj[V];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
        }
        
        vector<int>inDegree(V,0);
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                inDegree[it]++;
            }
        }
        
        queue<int>q;
        for(auto i=0;i<V;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                inDegree[it]--;
                if(inDegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(ans.size()!=V){
            return {};
        }
        reverse(ans.begin(),ans.end());
         
        return ans;
    }
};