#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> patternCount;
        int maxRows = 0;

        for (const auto& row : matrix) {
            string pattern = "", complement = "";
            for (int val : row) {
                pattern += to_string(val);      
                complement += to_string(1 - val);
            }
            patternCount[pattern]++;
            maxRows = max(maxRows, patternCount[pattern]);
            patternCount[complement]++;
            maxRows = max(maxRows, patternCount[complement]);
        }

        return maxRows;
    }
};
