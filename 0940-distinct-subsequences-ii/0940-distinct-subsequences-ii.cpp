class Solution {
public:
    int distinctSubseqII(string s) {
        const int mod = 1e9 + 7;
        vector<long long> dp(26, 0);

        for(char c : s) {
            long long total = 1;

            for(int i = 0; i < 26; i++){
                total = (total + dp[i]) % mod;
            }
            dp[c - 'a'] = total;
        }

        long long ans = 0;

        for(int i = 0; i < 26; i++){
            ans = (ans + dp[i]) % mod;
        }
        return ans;
    }
};