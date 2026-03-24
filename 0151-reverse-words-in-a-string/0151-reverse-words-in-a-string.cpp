class Solution {
public:
    string reverseWords(string s) {
      vector<string>v;
      int n=s.size();
      int i=0;
       while (i < n) {
        while (i < n && s[i] == ' ') i++;

        if (i >= n) break;

        int j = i;

        // find word
        while (j < n && s[j] != ' ') j++;

        v.push_back(s.substr(i, j - i));

        i = j;
    }
    reverse(v.begin(), v.end());

    // build result
    string ans = "";
    for (int k = 0; k < v.size(); k++) {
        ans += v[k];
        if (k != v.size() - 1) ans += " ";
    }
    return ans;
    }
};