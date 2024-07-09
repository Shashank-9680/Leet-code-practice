class Solution {
    static bool cmp(pair<char,int>a,pair<char,int>b){
        return a.second>b.second;
    }
public:
    string frequencySort(string s) {
         unordered_map<char, int> m;
        for (char c : s) {
            m[c]++;
        }

        vector<pair<char, int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), cmp);

        string result;
        for (const auto& p : v) {
            result.append(p.second, p.first);
        }
        return result;
    }
};