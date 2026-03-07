class Solution {
      void DFS(int i,vector<int>adj[], vector<int>&vis){
        vis[i]=1;
        for(auto it:adj[i]){
            if(!vis[it]){
                DFS(it,adj,vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
       int n=isConnected.size();
       int m = isConnected[0].size();
       vector<int>adj[n];
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           if(i!=j&&isConnected[i][j]==1){
              adj[i].push_back(j);
           }
        }
       }
       vector<int>vis(n,0);
       int count =0;
       for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                DFS(i,adj,vis);
            }
        }
        return count;
    }
};