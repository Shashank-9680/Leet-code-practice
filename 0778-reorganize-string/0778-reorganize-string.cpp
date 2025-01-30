class Solution {
public:
    string reorganizeString(string s) {
        // Step 1: Count frequencies
        unordered_map<char, int> freqMap;
        for (char c : s) {
            freqMap[c]++;
        }

        // Step 2: Find the character with the highest frequency
        int maxFreq = 0;
        char maxChar;
        for (auto& [c, freq] : freqMap) {
            if (freq > maxFreq) {
                maxFreq = freq;
                maxChar = c;
            }
        }

        // Step 3: Check if reorganization is possible
        if (maxFreq > (s.size() + 1) / 2) return "";

        // Step 4: Fill the result string
        string res(s.size(), '\0');
        int idx = 0;

        // Step 4.1: Place the most frequent character first
        while (freqMap[maxChar]-- > 0) {
            res[idx] = maxChar;
            idx += 2;
        }

        // Step 4.2: Place remaining characters
        for (auto& [c, freq] : freqMap) {
            while (freq-- > 0) {
                if (idx >= res.size()) idx = 1;
                res[idx] = c;
                idx += 2;
            }
        }

        return res;
    }
};