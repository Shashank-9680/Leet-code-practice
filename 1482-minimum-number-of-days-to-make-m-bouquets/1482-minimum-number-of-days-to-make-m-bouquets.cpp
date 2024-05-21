class Solution {
public:
    int bloomedFlower(vector<int>bloomDay,int m,int k,int mid){
        int count=0;
        int total=0;
        int n=bloomDay.size();
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=mid){
                count++;
              
            }
            else{
                 total+=count/k;
                count=0;
            }
           
        }
          total+=count/k;
        return total;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m * 1ll * k * 1ll;
    int n = bloomDay.size(); //size of the array
    if (val > n) return -1;
        int low = INT_MAX, high = INT_MIN;
    for (int i = 0; i < n; i++) {
        low = min(low, bloomDay[i]);
        high = max(high, bloomDay[i]);
    }
        while(low<=high){
            int mid=(low+high)/2;
           
         if(bloomedFlower(bloomDay,m,k,mid)>=m){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
        
    }
};