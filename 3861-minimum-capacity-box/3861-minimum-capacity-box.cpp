class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int ans=INT_MAX;
        for(int i=0;i<capacity.size();i++){
            if(capacity[i]>=itemSize){
                ans=min(ans,capacity[i]);
            }
        }
        for(int i=0;i<capacity.size();i++){
            if(capacity[i]==ans){
                return i;
            }
        }
        return -1;
    }
};