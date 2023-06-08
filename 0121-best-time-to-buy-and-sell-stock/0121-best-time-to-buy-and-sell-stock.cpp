class Solution {
public:
    int maxProfit(vector<int>& prices) {
         vector<int> v1;
    int n = prices.size();

    vector<int> v2;
    v1.push_back(prices[n - 1]);
    for (int i = n - 1; i > 0; i--)
    {
        if (prices[i - 1] > v1[n - 1 - i])
        {
            v1.push_back(prices[i - 1]);
        }
        else
        {
            v1.push_back(v1[n - 1 - i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        v2.push_back(v1[n - i - 1] - prices[i]);
    }
    int maxElement = *max_element(v2.begin(), v2.end());
    return maxElement;
    }
};