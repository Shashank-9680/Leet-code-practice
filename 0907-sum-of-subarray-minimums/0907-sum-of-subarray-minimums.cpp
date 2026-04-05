class Solution {
     void nextSmaller(vector<int>&arr,vector<int>&next){
         int n=arr.size();
        stack<int>st;
        for(int i=n-1;i>=0;i--){
           while(!st.empty()&&arr[st.top()]>=arr[i]){
            st.pop();
           }
           if(st.empty()) next[i]=n;
           else next[i]= st.top();
           st.push(i);
        }
     }

     void prevSmaller(vector<int>&arr,vector<int>&prev){
          int n=arr.size();
          stack<int>st;
        for(int i=0;i<n;i++){
           while(!st.empty()&&arr[st.top()]>arr[i]){
            st.pop();
           }
           if(st.empty()) prev[i]=-1;
           else prev[i]= st.top();
           st.push(i);
        }
     }

public:
    const int MOD=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>next(n);
        vector<int>prev(n);
        nextSmaller(arr,next);
        prevSmaller(arr,prev);
        int sum=0;
        for(int i=0;i<arr.size();i++){
         int total= ((i-next[i])*(prev[i]-i))%MOD;
       sum = (sum + (1LL * total * arr[i]) % MOD) % MOD;

        }
        return sum;
    }
};