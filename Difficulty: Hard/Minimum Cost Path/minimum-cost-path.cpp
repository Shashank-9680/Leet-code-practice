//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        vector<pair<int,int>>dir={{-1,0},{0,-1},{1,0},{0,1}};
        dis[0][0]=grid[0][0];
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        q.push({grid[0][0],{0,0}});
        while(!q.empty()){
            int dist=q.top().first;
            int row=q.top().second.first;
            int col=q.top().second.second;
            q.pop();
            for(auto it:dir){
                int nrow=row+it.first;
                int ncol=col+it.second;
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m){
                    if(dist+grid[nrow][ncol]<dis[nrow][ncol]){
                        dis[nrow][ncol]=dist+grid[nrow][ncol];
                        q.push({dis[nrow][ncol],{nrow,ncol}});
                    }
                }
            }
        }
        return dis[n-1][m-1];
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends