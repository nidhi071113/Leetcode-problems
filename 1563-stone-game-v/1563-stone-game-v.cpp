class Solution {
public:
    vector<vector<int>> memo;
    vector<int> pre;

    int solve(int i, int j) {
        if (i == j) return 0;
        if (memo[i][j] != -1) return memo[i][j];

        int total = pre[j + 1] - pre[i];
        int best = 0;

        for (int k = i; k < j; k++) {
            int left = pre[k + 1] - pre[i];
            int right = total - left;

            if (left < right) {
                best = max(best, left + solve(i, k));
            } else if (left > right) {
                best = max(best, right + solve(k + 1, j));
            } else {
                best = max(best, left + max(solve(i, k), solve(k + 1, j)));
            }
        }

        return memo[i][j] = best;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        pre.assign(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + stoneValue[i];
        }

        memo.assign(n, vector<int>(n, -1));
        return solve(0, n - 1);
    }
};