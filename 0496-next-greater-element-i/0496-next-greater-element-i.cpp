class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
         int k=nums1.size();
                                                             
       unordered_map<int,int>m;                                              
       vector<int>v;
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&st.top()<=nums2[i]){
                st.pop();       
           } 
               if(!st.empty()){
                    
                     m.insert({nums2[i],st.top()});
               }
            else{
                m.insert({nums2[i],-1});
            }
            
        st.push(nums2[i]); 
        }
         for(int i=0;i<k;i++){
          auto it=m.find(nums1[i]); 
             v.push_back(it->second);
         }  
       return v;                                                                     
    }
};