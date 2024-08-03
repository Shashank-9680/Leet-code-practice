class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n=arr.size();
        int maxElement1=*max_element(arr.begin(),arr.end());
        int maxElement2=*max_element(target.begin(),target.end());
        int maxi=max(maxElement1,maxElement2);
        vector<int>hash1(maxi+1,0);
        vector<int>hash2(maxi+1,0);
        for(int i=0;i<n;i++){
           hash1[arr[i]]++; 
        }
        for(int i=0;i<n;i++){
           hash2[target[i]]++;  
        }
        for(int i=0;i<n;i++){
            if(hash2[target[i]]!=hash1[target[i]]){
                return false;
            }
        }
        return true;
    }
};