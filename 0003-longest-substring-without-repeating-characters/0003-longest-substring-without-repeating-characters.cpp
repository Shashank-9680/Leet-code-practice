class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     int n=s.size();
        int i=0;
        int j=0;
        int length=0;
        unordered_map<char,int>m;
        while(j<n){
            if(m.find(s[j])!=m.end()){
                i=max(m[s[j]]+1,i);
            }
            length=max(length,j-i+1);
            m[s[j]]=j;
            j++;  
        }
        return length;
    }
};