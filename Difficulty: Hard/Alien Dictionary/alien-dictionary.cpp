//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    void dfs(int start,vector<int>&vis,stack<int>&st,vector<int> adj[]){
        vis[start]=1;
        for(auto it:adj[start]){
            if(!vis[it]){
                dfs(it,vis,st,adj);
            }
        }
        st.push(start);
        
    }
    public:
    string findOrder(string dict[], int N, int K){
        vector<int>adj[K];
        string ans="";
      for(int a=0;a<N-1;a++){
         int i=0;
         int j=0;
         while(i<dict[a].size()&&j<dict[a+1].size()){
             if(dict[a][i]!=dict[a+1][j]){
                 adj[dict[a][i]-'a'].push_back(dict[a+1][j]-'a');
                
                 break;
             }
              i++;
                 j++;
         }
      }
        stack<int>st;
        vector<int>vis(K,0);
        for(int i=0;i<K;i++){
	        if(!vis[i]){
	        dfs(i,vis,st,adj);     
	        }
	       
	    }
	 while (!st.empty()) {
    ans += (st.top() + 'a');
    st.pop();
}
      
      return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends