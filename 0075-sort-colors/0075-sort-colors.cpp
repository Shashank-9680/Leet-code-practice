class Solution {
public:
    void sortColors(vector<int>& nums) {
        
         int a = count(nums.begin(), nums.end(), 0);
           int b = count(nums.begin(), nums.end(), 1);
           int c = count(nums.begin(), nums.end(), 2);
     nums.clear();
        for(int i=0;i<a;i++){
            nums.push_back(0);
        }
        for(int i=a;i<a+b;i++){
            nums.push_back(1);
        }
        for(int i=a+b;i<a+b+c;i++){
            nums.push_back(2);
        }
        
    }
    
};