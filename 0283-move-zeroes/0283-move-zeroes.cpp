class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      int n=nums.size();
        int c=-1;
      for(int i=0;i<n;i++){
          if(nums[i]==0){
              c=i;
              break;
          }
      }
        if(c==-1) return;
        int k=c;
        for(int j=c+1;j<n;j++){
            if(nums[j]!=0){
             swap(nums[k],nums[j]);
                k++;
            }
        }
        
    }
};