class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& edges) {

        int V = edges.size();

        vector<int> adj[V];

        // reverse graph
        for(int i = 0; i < V; i++){
            for(auto it : edges[i]){
                adj[it].push_back(i);
            }
        }

        vector<int> inDegree(V,0);

        for(int i = 0; i < V; i++){
            for(auto it : adj[i]){
                inDegree[it]++;
            }
        }

        queue<int> q;

        for(int i = 0; i < V; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()){
 
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node]){
                inDegree[it]--;
                if(inDegree[it] == 0){
                    q.push(it);
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};