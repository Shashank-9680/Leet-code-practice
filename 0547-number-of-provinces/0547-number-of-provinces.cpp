class Solution {
     void dfs(int start,vector<int>&vis,vector<int>adj[]){
         vis[start]=1;
         for(auto it:adj[start]){
             if(!vis[it]){
                 dfs(it,vis,adj);
             }
         }
     }
public:
    int findCircleNum(vector<vector<int>>& adj) {
        int v=adj.size();
        vector<int>list[v];
       for(int i=0;i<v;i++){
         for(int j=0;j<v;j++){
             if(adj[i][j]==1&&i!=j){
                 list[i].push_back(j);
                  list[j].push_back(i);
             }
         }
       }
        vector<int>vis(v,0);
        int count=0;
        for(int i=0;i<v;i++){
            if(!vis[i]){
               count++;
                dfs(i,vis,list);
            }
        }
        return count;
    }
};