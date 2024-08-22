class Solution {
public:
    int findComplement(int num) {
        if (num == 0) return 1;  // Special case: complement of 0 is 1.
        
        int n = 0;
        int temp = num;
        
        // Calculate the number of bits in the binary representation of num
        while (temp > 0) {
            temp /= 2;
            n++;
        }
        
        // Generate a bitmask with n bits set to 1
        int mask = (1LL << n) - 1;
        
        // XOR num with the mask to get the complement
        return num ^ mask;
    }
};
