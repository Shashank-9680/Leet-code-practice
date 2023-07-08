class Solution {
public:
    int trap(vector<int>& height) {
      int n = height.size();
        int sum=0;
    vector<int> a;
    a.push_back(height[0]);
    vector<int> b;
    b.push_back(height[n - 1]);
    for (int i = 1; i < n; i++)
    {
        if (height[i] > a[i - 1])
        {
            a.push_back(height[i]);
        }
        else
        {
            a.push_back(a[i - 1]);
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (height[i] > b[n - i - 2])
        {
            b.push_back(height[i]);
        }
        else
        {
            b.push_back(b[n - i - 2]);
        }
    }
        reverse(b.begin(), b.end());
        for(int i=0;i<n;i++){
            sum=sum+abs(min(a[i],b[i])-height[i]);
        }
        return sum;
    }
};