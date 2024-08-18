class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v(n);
        v[0] = 1; 

        int p2 = 0, p3 = 0, p5 = 0; 

        for (int i = 1; i < n; i++) {
            
            int nextUgly = min({2 * v[p2], 3 * v[p3], 5 * v[p5]});

            v[i] = nextUgly;

            // Increment the respective pointer(s)
            if (nextUgly == 2 * v[p2]) p2++;
            if (nextUgly == 3 * v[p3]) p3++;
            if (nextUgly == 5 * v[p5]) p5++;
        }

        return v[n - 1]; // Return the nth ugly number
    }
};
