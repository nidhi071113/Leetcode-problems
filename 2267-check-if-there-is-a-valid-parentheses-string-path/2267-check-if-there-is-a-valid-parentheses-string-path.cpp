class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Path length must be even, and must start with '(' and end with ')'
        if ((m + n - 1) % 2 != 0 || grid[0][0] == ')' || grid[m - 1][n - 1] == '(') {
            return false;
        }

        // dp[i][j] stores all possible balance values reachable at cell (i, j)
        vector<vector<unordered_set<int>>> dp(m, vector<unordered_set<int>>(n));

        // Base case: Starting point
        dp[0][0].insert(1); // grid[0][0] is always '(' here

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;

                int delta = (grid[i][j] == '(') ? 1 : -1;

                // Collect balances coming from top cell (i-1, j)
                if (i > 0) {
                    for (int b : dp[i - 1][j]) {
                        int next_b = b + delta;
                        if (next_b >= 0) dp[i][j].insert(next_b);
                    }
                }

                // Collect balances coming from left cell (i, j-1)
                if (j > 0) {
                    for (int b : dp[i][j - 1]) {
                        int next_b = b + delta;
                        if (next_b >= 0) dp[i][j].insert(next_b);
                    }
                }
            }
        }

        // If '0' exists in the balance set of bottom-right cell, path is valid!
        return dp[m - 1][n - 1].count(0) > 0;
    }
};