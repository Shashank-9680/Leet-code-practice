class Solution {
    int SumofArray(vector<int>v){
         int sum=0;
        int n=v.size();
        for(int i=0;i<n;i++){
           
            sum=sum+v[i];
        }
        return sum;
    }
    int answer(vector<int>v,int mid){
        int n=v.size();
        int count=0;
        int sum=0;
        for(int i=0;i<n;i++){ 
            sum=sum+v[i];
            if(sum>mid){
                count++;
                sum=v[i];     
            }
        }
        count++;
        return count;
    }
public:
    
    int shipWithinDays(vector<int>& nums, int days) {
        int low=*max_element(nums.begin(),nums.end());
        int high=SumofArray(nums);
        while(low<=high){
            int mid=(low+high)/2;
          
            if(answer(nums,mid)<=days){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};