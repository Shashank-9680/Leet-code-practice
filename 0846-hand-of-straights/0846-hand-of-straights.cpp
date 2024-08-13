class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) {
            return false;
        }

        sort(hand.begin(), hand.end());
        unordered_map<int, int> m;
        for (auto it : hand) {
            m[it]++;
        }

        for (int i = 0; i < n; i++) {
            if (m[hand[i]] > 0) {
                // Try to form a group starting from hand[i]
                for (int j = 0; j < groupSize; j++) {
                    int current = hand[i] + j;
                    if (m[current] > 0) {
                        m[current]--;  // Use one card from the current group
                    } else {
                        return false;  // Can't form a group starting from hand[i]
                    }
                }
            }
        }
        return true;
    }
};
