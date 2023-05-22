class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
         
      
       int c=0,b;
     
        vector<int> v;
    vector<int> k;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
        {
            v.push_back(nums[i]);
        }
    }
    // cout << v.size() << "\n";
        
    if(v.size()>0){
        sort(v.begin(),v.end());
    k.push_back(v[0]);
    for (int i = 1; i < v.size(); i++)
    {

        if (v[i] != v[i - 1])
        {
            k.push_back(v[i]);
        }
    }
    }
    else{
        return 1;
    }
    int e = k.size();
    sort(k.begin(), k.end());
    for (int i = 0; i < e; i++)
    {

        if (k[i] == i + 1)
        {
            c++;
        }
        else
        {
            b = i + 1;
            break;
        }
    }
   
     if (k[0]>1)
    {
        return 1;
    }
    else if (c == e)
    {
        return k[e - 1] + 1;
    }
    else
    {
        return b;
    }

    }
};