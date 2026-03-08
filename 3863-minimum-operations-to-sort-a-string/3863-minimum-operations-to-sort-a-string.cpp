class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        string sorted = s;
        sort(sorted.begin(), sorted.end());

        if (s == sorted) return 0;

        if (s.size() == 2) return -1;

        char mn = *min_element(s.begin(), s.end());
        int pos = -1;

        for (int i = 0; i < n; i++) {
            if (s[i] == mn) {
                pos = i;
                break;
            }
        }

        if (pos == 0) {
            string temp = s;
            sort(temp.begin()+1, temp.end());
            return 1;
        }
        else if (pos == n - 1) {
            string temp = s;

            sort(temp.begin() + 1, temp.end());

            if (temp[0] > temp[1]) {
                sort(temp.begin(),temp.end()-1);
                if(temp==sorted) return 2;
                return 3;
              
            }

            if (temp == sorted) return 1;
        }
        else {
            string temp = s;

            sort(temp.begin(), temp.end() - 1);

            if (temp == sorted) return 1;   // 🔧 added fix

            if (temp[n - 2] > temp[n - 1]) {  
                return 2;
            }
        }

        return -1;
    }
};