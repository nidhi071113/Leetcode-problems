class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> bitCount(32, 0);
        
        // Step 1: Count how many numbers have each bit set
        for (int num : nums) {
            for (int i = 0; i < 32; i++) {
                if ((num >> i) & 1) {
                    bitCount[i]++;
                }
            }
        }
        
        long long totalSum = 0;
        long long MOD = 1e9 + 7;
        
        // Step 2: Rebuild k numbers by placing the bits from most significant to least
        for (int i = 0; i < k; i++) {
            long long currentNum = 0;
            for (int bit = 31; bit >= 0; bit--) {
                if (bitCount[bit] > 0) {
                    currentNum |= (1LL << bit);
                    bitCount[bit]--;
                }
            }
            // Add square of this number modulo 10^9 + 7
            totalSum = (totalSum + (currentNum * currentNum) % MOD) % MOD;
        }
        
        return totalSum;
    }
};