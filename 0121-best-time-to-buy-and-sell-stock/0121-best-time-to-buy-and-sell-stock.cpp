class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=INT_MAX;
        int supermax=0;
        int n=prices.size();
        for(int i=0;i<n;i++){
            minPrice= min(minPrice,prices[i]);
            if(prices[i]>minPrice){
                supermax=max(supermax,prices[i]-minPrice);
            }
        }
        return supermax;
    }
};