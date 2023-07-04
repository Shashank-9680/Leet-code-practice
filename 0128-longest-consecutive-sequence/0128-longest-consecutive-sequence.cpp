class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int c=0;
       
        vector<int>v;
        vector<int>k;
        sort(nums.begin(),nums.end());
        if(n>0){
        k.push_back(nums[0]);
        }
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                k.push_back(nums[i]);
            }
        }
       v.push_back(0);
      int m=k.size();
        for(int i=0;i<m-1;i++){
            if(k[i]+1==k[i+1]){
              
                c++;
                v.push_back(c);
            }
            else{
               
                c=0;
            }
        }
        if(n==0){
            return  *max_element(v.begin(), v.end());
        }
        else{
        return  *max_element(v.begin(), v.end())+1;
        }
    }
};