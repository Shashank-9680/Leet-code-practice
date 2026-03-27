class Solution {
    static bool comp(pair<int,char>p1,pair<int,char>p2){
        return p1.first>p2.first;
    }
public:
    string frequencySort(string s) {
        unordered_map<char,int>m;
        for(auto it:s){
            m[it]++;
        }
        vector<pair<int,char>>v;
        for(auto it:m){
            v.push_back({it.second,it.first});
            sort(v.begin(),v.end(),comp);
        }
         string ans="";
    for(auto it:v){
        for(int i=0;i<it.first;i++){
           ans+=it.second;
        }
    }
    return ans;
    }
};
