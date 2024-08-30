//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

//{ Driver Code Starts
// Initial Template for C++



class Solution{
    vector<vector<int>> result;
    
    // Function to check if a queen can be placed on board[row][col]
    bool isSafe(int row, int col, vector<int>& board, int n) {
        for (int i = 0; i < row; i++) {
            // Check if there is a queen in the same column or diagonals
            if (board[i] == col || abs(board[i] - col) == abs(i - row))
                return false;
        }
        return true;
    }
    
    // Function to solve the N-Queens problem using backtracking
    void solve(int row, vector<int>& board, int n) {
        if (row == n) {
            // All queens are placed successfully, store the board configuration
            vector<int> currentSolution;
            for (int i = 0; i < n; i++) {
                currentSolution.push_back(board[i] + 1); // +1 for 1-based indexing
            }
            result.push_back(currentSolution);
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, board, n)) {
                board[row] = col; 
                solve(row + 1, board, n); // Recur to place rest of the queens
                // Backtrack by removing the queen from current position
                board[row] = -1;
            }
        }
    }
    
public:
    vector<vector<int>> nQueen(int n) {
        vector<int> board(n, -1); // Initialize the board
        solve(0, board, n); // Start placing queens from the first row
        return result; // Return all possible solutions
    }
};

//{ Driver Code Starts.



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends