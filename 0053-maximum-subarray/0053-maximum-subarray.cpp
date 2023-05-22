class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int n=nums.size();
       
        vector<int>k;
        int sum=0;
        for(int i=0;i<n;i++){
          
               sum=sum+nums[i];
               if(sum>=0){
                   k.push_back(sum);
                   continue;
                   
               }
               else{
                   sum=0;
               }
           }
            
        
   
  if (!k.empty()) {
  return *max_element(k.begin(), k.end());
} else {
 return *max_element(nums.begin(),nums.end());
      }    
    }

};