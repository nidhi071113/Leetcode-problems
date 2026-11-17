class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.length();
        vector<vector<int>> cost(n, vector<int>(n, 1e9));

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int len = j - i + 1;
                for (int d = 1; d < len; d++) {
                    if (len % d == 0) {
                        int currentCost = 0;
                        for (int start = i; start < i + d; start++) {
                            int l = start;
                            int r = start + (len / d - 1) * d;
                            while (l < r) {
                                if (s[l] != s[r]) currentCost++;
                                l += d;
                                r -= d;
                            }
                        }
                        cost[i][j] = min(cost[i][j], currentCost);
                    }
                }
            }
        }

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1e9));
        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                for (int p = 0; p < i; p++) {
                    if (dp[p][j - 1] != 1e9 && cost[p][i - 1] != 1e9) {
                        dp[i][j] = min(dp[i][j], dp[p][j - 1] + cost[p][i - 1]);
                    }
                }
            }
        }

        return dp[n][k];
    }
};