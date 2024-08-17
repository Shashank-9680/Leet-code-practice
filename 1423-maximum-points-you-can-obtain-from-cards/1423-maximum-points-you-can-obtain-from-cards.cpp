class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum=sum+arr[i];
        }
       int size=arr.size()-k;
        int sum1=0;
        for(int i=0;i<size;i++){
            sum1=sum1+arr[i];
        }
        int ans=sum-sum1;
        int i=0;
        int j=size;
        while(j<arr.size()){
            sum1=sum1-arr[i]+arr[j];
            i++;
            ans=max(ans,sum-sum1);
            j++;
        }
        return ans;
    }
};