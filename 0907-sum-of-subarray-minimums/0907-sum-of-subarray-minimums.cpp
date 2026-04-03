class Solution {
    void findNextSmaller(vector<int>&arr,vector<int>&nextSmaller,int n){
     stack<pair<int,int>>st;
     for(int i=n-1;i>=0;i--){
        while(!st.empty()&&st.top().first>=arr[i]){
            st.pop();
        }

        if(st.empty()) nextSmaller[i]=n;
        else nextSmaller[i]= st.top().second;
        st.push({arr[i],i});
     }
    }

    void findPrevSmaller(vector<int>&arr,vector<int>&prevSmaller,int n){
         stack<pair<int,int>>st;

     for(int i=0;i<n;i++){
        while(!st.empty()&&st.top().first>arr[i]){
            st.pop();
        }

        if(st.empty()) prevSmaller[i]=-1;
        else prevSmaller[i]= st.top().second;
        st.push({arr[i],i});
     }
    }

public:
    const int MOD=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
       int n=arr.size();
        vector<int>nextSmaller(n);
        vector<int>prevSmaller(n);
            findNextSmaller(arr,nextSmaller,n);
            findPrevSmaller(arr,prevSmaller,n);
        for(auto it:nextSmaller){
            cout<<it;
        }
         int sum=0;
            for(int i=n-1;i>=0;i--){
                int leftSubarray=(i-prevSmaller[i]);
                int rightSubarray=(nextSmaller[i]-i);
                int total=leftSubarray*rightSubarray;
                cout<<total;
                sum = (sum + (1LL * total * arr[i]) % MOD) % MOD;
            }

            return sum;
    }
        
};