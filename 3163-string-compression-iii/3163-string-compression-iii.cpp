class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        char c = word[0];
        int count = 1;

        for (int i = 1; i < word.size(); i++) {
            if (word[i] == c) {
                count++;
            } else {
                int value = count / 9;
                int rem = count % 9;
                for (int j = 0; j < value; j++) {
                    ans += '9';
                    ans += c;
                }
                if (rem > 0) {
                    ans += rem + '0';
                    ans += c;
                }
                c = word[i];
                count = 1;
            }
        }

        // Add the last sequence
        int value = count / 9;
        int rem = count % 9;
        for (int j = 0; j < value; j++) {
            ans += '9';
            ans += c;
        }
        if (rem > 0) {
            ans += rem + '0';
            ans += c;
        }

        return ans;
    }
};
