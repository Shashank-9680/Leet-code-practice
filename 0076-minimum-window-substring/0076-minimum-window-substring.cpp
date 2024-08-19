class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (m > n) return ""; // If t is longer than s, it's impossible to find the window

        unordered_map<char, int> map;
        for (char c : t) {
            map[c]++;
        }

        int i = 0, j = 0, count = 0;
        int minLen = INT_MAX, startIndex = -1;

        while (j < n) {
            if (map[s[j]] > 0) count++;
            map[s[j]]--;

            // When we have a valid window (contains all characters of t)
            while (count == m) {
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    startIndex = i;
                }

                map[s[i]]++;
                if (map[s[i]] > 0) count--;
                i++;
            }
            j++;
        }

        return startIndex == -1 ? "" : s.substr(startIndex, minLen);
    }
};
