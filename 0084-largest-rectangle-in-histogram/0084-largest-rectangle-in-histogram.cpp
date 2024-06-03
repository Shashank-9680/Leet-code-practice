class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
         long long int sum=0;
        int n=arr.size();
    stack<int>s1,s2;
        vector<int>v1(n),v2(n);
        for(int i=n-1;i>=0;i--){
            while(!s1.empty()&&arr[s1.top()]>=arr[i]){
                s1.pop();
            }
            if(!s1.empty()){
                  v1[i] = s1.top() ;
            }
            else{
                v1[i] =n;
            }
            s1.push(i);
        }
        
         for(int i=0;i<n;i++){
             
       while(!s2.empty()&&arr[s2.top()]>arr[i])
        {
           s2.pop();
        };
  
   if(!s2.empty()){
      v2[i] = s2.top();
   }
   else{
      v2[i]=-1;
   }
   s2.push(i);
         }
       int maxArea = 0;
        for (int i = 0; i < n; ++i) {
            int width = v1[i] - v2[i] - 1;
            int area = arr[i] * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};