class Solution {
    int count = 0;

    void merge(int arr[], int l, int m, int r) {
        vector<int> temp;
        int left = l;
        int right = m + 1;
        
        while (left <= m && right <= r) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                right++;
            }
        }
        
        while (left <= m) {
            temp.push_back(arr[left]);
            left++;
        }
        
        while (right <= r) {
            temp.push_back(arr[right]);
            right++;
        }
        
        for (int i = l; i <= r; i++) {
            arr[i] = temp[i - l];
        }
    }

    void countPairs(int arr[], int l, int m, int r) {
        int right = m + 1;
        for (int i = l; i <= m; i++) {
            while (right <= r && arr[i] > 2LL * arr[right]) {
                right++;
            }
            count += (right - (m + 1));
        }
    }

public:
    void mergeSort(int arr[], int l, int r) {
        if (l >= r) return;
        int m = (l + r) / 2;
        
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        countPairs(arr, l, m, r);
        merge(arr, l, m, r);
    }

    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        if (nums.empty()) return 0;
        
       
        int arr[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = nums[i];
        }
        
        mergeSort(arr, 0, n - 1);
        
        return count;
    }
};
