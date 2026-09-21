class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            int v = num % k;
            vector<long long> next_dp(k, 0);
            
            // Subarray starting at the current element
            next_dp[v]++;

            // Extend existing subarrays ending at the previous element
            for (int r = 0; r < k; r++) {
                if (dp[r] > 0) {
                    int new_r = (r * v) % k;
                    next_dp[new_r] += dp[r];
                }
            }

            // Accumulate counts into the global result
            for (int r = 0; r < k; r++) {
                result[r] += next_dp[r];
            }

            dp = move(next_dp);
        }

        return result;
    }
};