class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
      int time = 0;
        int freq[26] = {0};

        // Count the frequency of each task
        for (char task : tasks) {
            freq[task - 'A']++;
        }

        // Max-heap (priority queue) to store task frequencies
        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.push(freq[i]);
            }
        }

        // Queue to store tasks in the cooldown period
        queue<pair<int, int>> cooldownQueue;

        while (!pq.empty() || !cooldownQueue.empty()) {
            

            // Check if any task in cooldown can be added back to the priority queue
            if (!cooldownQueue.empty() && cooldownQueue.front().second + n < time) {
                pq.push(cooldownQueue.front().first);
                cooldownQueue.pop();
            }

            // Execute the most frequent task
            if (!pq.empty()) {
                int currentTaskFreq = pq.top();
                pq.pop();

                if (currentTaskFreq > 1) {
                    cooldownQueue.push({currentTaskFreq - 1, time});
                }
            }
            time++;
        }

        return time;
    }
};