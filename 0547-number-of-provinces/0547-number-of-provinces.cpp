class Solution {
     void dfs(int start,vector<int>&list,vector<vector<int>>adj){
        list[start]=1;
       
        for(auto it:adj[start]){
            if(!list[it]){
                dfs(it,list,adj);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& adj) {
       
        int V=adj.size();
         vector<vector<int>>adjList(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1&&i!=j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        vector<int>list(V,0);
       
     int count=0;
        for(int i=0;i<V;i++){
            if(list[i]==0){
                count++;
                dfs(i,list,adjList);
            }
        }
       
       return count; 
    }
};