//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
      sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        priority_queue<pair<int, pair<int, int>>> pq;
        set<pair<int, int>> visited;
        vector<int> ans;

        // Push the largest combination (last elements from both arrays)
        pq.push({A[N-1] + B[N-1], {N-1, N-1}});
        visited.insert({N-1, N-1});

        while (K-- && !pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int sum = top.first;
            int i = top.second.first;
            int j = top.second.second;

            ans.push_back(sum);

          
            if (i > 0 && visited.find({i-1, j}) == visited.end()) {
                pq.push({A[i-1] + B[j], {i-1, j}});
                visited.insert({i-1, j});
            }

            
            if (j > 0 && visited.find({i, j-1}) == visited.end()) {
                pq.push({A[i] + B[j-1], {i, j-1}});
                visited.insert({i, j-1});
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends