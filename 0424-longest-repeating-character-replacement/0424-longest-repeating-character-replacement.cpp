class Solution {
public:
    int characterReplacement(string s, int k) {
         int length=0;
        int i=0;
        int j=0;
        int n=s.size();
        map<char,int>m;
        int maximum=-1;
   
        while(j<n){
            m[s[j]]++;
            maximum=max(maximum,m[s[j]]);
                int value=j-i+1-maximum;
  
            
           if(value>k){
            //   while(m.size()>2){
               m[s[i]]--; 
              if(m[s[i]]==0){
                  m.erase(s[i]);
              }
              i++;
                   
           }
            
           if(value<=k){
               length=max(length,j-i+1);
           }
           j++;
        }
        return length;
     
    }
};