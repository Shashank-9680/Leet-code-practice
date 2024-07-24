class Solution {
//     int reverse(int n){
//         int num=0;
//         while(n>0){
            
//             int a=n%10;
//              num=num*10+a;
//             n=n/10;
//         }
//         return num;
//     }
   
    void convert(vector<int>& arr, int n, vector<int>& mapping) {
        string mappedStr = "";

        if (n == 0) {
            mappedStr += to_string(mapping[0]);
        } else {
            while (n > 0) {
                int a = n % 10;
                mappedStr = to_string(mapping[a]) + mappedStr;
                n = n / 10;
            }
        }

        arr.push_back(stoi(mappedStr));
    }
    static bool comp(pair<int,int>p1,pair<int,int>p2){
        return p2.second>p1.second;
    }
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int> arr;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            convert(arr, nums[i], mapping);
        }

        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], arr[i]});
        }

        sort(v.begin(), v.end(), comp);

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back(v[i].first);
        }

        return ans;
    }
};