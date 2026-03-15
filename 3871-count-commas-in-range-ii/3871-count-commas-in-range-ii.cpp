class Solution {
public:
    long long countCommas(long long n) {
        long long total = 0;

        if(n >= 1000)
            total += min(n, 999999LL) - 1000 + 1;

        if(n >= 1000000LL)
            total += 2LL * (min(n, 999999999LL) - 1000000 + 1);

        if(n >= 1000000000LL)
            total += 3LL * (min(n, 999999999999LL) - 1000000000 + 1);

        if(n >= 1000000000000LL)
            total += 4LL * (min(n, 999999999999999LL) - 1000000000000 + 1);

        // new block
        if(n >= 1000000000000000LL)
            total += 5LL * (n - 1000000000000000LL + 1);

        return total;
    }
};