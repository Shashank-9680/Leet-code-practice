class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int i=0;
        int j=0;
        int length=0;
        int n=s.size();
        unordered_map<char,int>m;
        while(j<n){
           if(m.find(s[j])!=m.end()){
                i=max(m[s[j]]+1,i);
            }
            m[s[j]]=j;
           
            length=max(length,j-i+1);
            j++;
        }
        return length;
    }
};