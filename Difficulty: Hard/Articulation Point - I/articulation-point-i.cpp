class Solution {
public:

    int timer=0;

    void dfs(int node,int parent,vector<int>adj[],int tim[], int low[],
             vector<int>&vis,vector<int>&mark){

        vis[node]=1;

        tim[node]=low[node]=timer++;

        int child=0;

        for(auto it:adj[node]){

            if(it==parent) continue;

            if(!vis[it]){

                child++;

                dfs(it,node,adj,tim,low,vis,mark);

                low[node]=min(low[node],low[it]);

                if(low[it]>=tim[node] && parent!=-1){
                    mark[node]=1;
                }
            }
            else{
                low[node]=min(low[node],tim[it]);
            }
        }

        if(child>1 && parent==-1){
            mark[node]=1;
        }
    }

    vector<int> articulationPoints(int V, vector<int> adj[]) {

        vector<int>vis(V,0);
        int tim[V], low[V];
        vector<int>mark(V,0);

        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,-1,adj,tim,low,vis,mark);
            }
        }

        vector<int>ans;

        for(int i=0;i<V;i++){
            if(mark[i]) ans.push_back(i);
        }

        if(ans.size()==0) return {-1};

        return ans;
    }
};