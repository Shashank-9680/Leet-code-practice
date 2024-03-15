class Solution {
public:
    bool check(vector<int>& arr) {
      int n=arr.size();
        int flag=0;
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]){
                flag++;
            }
        }
        if(flag==0){
            return true;
        }
        else if(flag==1&&arr[n-1]<=arr[0]){
            return true;
        }
        else{
            return false;
        }
    }
};
