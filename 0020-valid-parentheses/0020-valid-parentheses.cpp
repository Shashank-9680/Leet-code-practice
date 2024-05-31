class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, int> m;
        m.insert({'(', 1});
        m.insert({')', -1});
        m.insert({'{', 2});
        m.insert({'}', -2});
        m.insert({'[', 3});
        m.insert({']', -3});

        stack<char> stk;

        for (char c : s) {
            auto it = m.find(c);
        

            int value = it->second;

            if (value > 0) {
              
                stk.push(c);
            } else {
               
                if (stk.empty()) {
                    return false;
                }
                char top = stk.top();
                auto top_it = m.find(top);
                if (top_it == m.end() || (top_it->second + value) != 0) {
                    return false;
                }
                stk.pop();
            }
        }

        // If stack is empty, all brackets matched correctly
        return stk.empty();
    }
};