class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                adj[it].push_back(i);
            }
        }
        int V=adj.size();
        vector<int>indegree(V,0);
for(int i=0;i<V;i++){
    for(auto it:adj[i]){
        indegree[it]++;
    }
}
queue<int>q;
vector<int>result;

for(int i=0;i<V;i++){
    if(indegree[i]==0){
        q.push(i);
    }
}
while(!q.empty()){
   int value=q.front();
   q.pop();
   result.push_back(value);
   for(auto it:adj[value]){
       indegree[it]--;
       if(indegree[it]==0){
           q.push(it);
       }
   }
}
 sort(result.begin(), result.end());

        return result;
    }
};