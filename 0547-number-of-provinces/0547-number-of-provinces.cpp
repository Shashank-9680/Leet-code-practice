class Solution {
    void dfs(int start,vector<int>list[],vector<int>&vis){
        vis[start]=1;
        for(auto it:list[start]){
            if(!vis[it]){
                dfs(it,list,vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& adj) {
        int n=adj.size();
        int m=adj[0].size();
      vector<int>list[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i!=j &&adj[i][j]==1){
                  list[i].push_back(j);
                    list[j].push_back(i);
                }
            }
        }
        vector<int>vis(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,list,vis);
                count++;
            }
        }
        return count;
        
    }
};