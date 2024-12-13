class Solution {
public:
    long long findScore(vector<int>& nums) {
         int n = nums.size();
        long long score = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(n, 0);

        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int value = it.first;
            int index = it.second;

            if (!vis[index]) {
                score += value;
                vis[index] = 1;
                if (index + 1 < n && !vis[index + 1]) {
                    vis[index + 1] = 1; 
                }
                if (index - 1 >= 0 && !vis[index - 1]) {
                    vis[index - 1] = 1;
                }
            }
        }
        return score;
    }
};