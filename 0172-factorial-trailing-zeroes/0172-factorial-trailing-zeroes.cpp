class Solution {
public:
    int trailingZeroes(int n) {
        int c=0;
      
        if(n==0)
    return 0;
        else
            return n/5+trailingZeroes(n/5);
        return c;
    }
};