class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,int>m1,m2;
        for(auto it:s){
            m1[it]++;
        }
        for(auto it:t){
            m2[it]++;
        }
        for(int i=0;i<s.size();i++){
            if(m2.count(s[i])==0||m2[s[i]]!=m1[s[i]]){
                cout<<"shashank";
                return false;
            }
        }
        // for(int i=0;i<t.size();i++){
        //     if(m1.count(t[i])==0||m1[t[i]]!=m2[t[i]]){
        //         cout<<"hey";
        //         return false;
        //     }
        // }
        return true;
    }
};