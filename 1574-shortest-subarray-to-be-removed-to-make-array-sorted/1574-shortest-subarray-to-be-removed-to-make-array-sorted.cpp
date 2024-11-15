class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        
      
        int left = 0;
        while (left < n - 1 && arr[left] <= arr[left + 1]) {
            left++;
        }
        if (left == n - 1) {
            return 0; 
        }
        
       
        int right = n - 1;
        while (right > 0 && arr[right - 1] <= arr[right]) {
            right--;
        }
        
       
        int minRemoval = min(n - left - 1, right); 
        
      
        int i = 0, j = right;
        cout<<j;
        while (i <= left && j < n) {
            if (arr[i] <= arr[j]) {
                minRemoval = min(minRemoval, j - i - 1);
                i++;
            } else {
                j++;
            }
        }
        
        return minRemoval;
    }
};