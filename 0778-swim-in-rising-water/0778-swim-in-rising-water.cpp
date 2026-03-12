class Solution {
public:

    bool dfs(int i, int j, int t, vector<vector<int>>& grid, vector<vector<int>>& vis){
        int n = grid.size();

        if(i<0 || j<0 || i>=n || j>=n) return false;
        if(vis[i][j] || grid[i][j] > t) return false;

        if(i == n-1 && j == n-1) return true;

        vis[i][j] = 1;

        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};

        for(int k=0;k<4;k++){
            int ni = i + dx[k];
            int nj = j + dy[k];

            if(dfs(ni,nj,t,grid,vis)) return true;
        }

        return false;
    }

    bool canReach(int t, vector<vector<int>>& grid){
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n,0));
        return dfs(0,0,t,grid,vis);
    }

    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();
        int low = grid[0][0];
        int high = n*n - 1;
        int ans = high;

        while(low <= high){
            int mid = (low + high) / 2;

            if(canReach(mid, grid)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return ans;
    }
};