class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int maxF = 1;
        for (const auto& item : items) {
            maxF = max(maxF, item[0]);
        }

        vector<int> divCount(maxF + 1, 0);
        for (const auto& item : items) {
            divCount[item[0]]++;
        }

        vector<int> multCount(maxF + 1, 0);
        for (int f = 1; f <= maxF; f++) {
            for (int m = f; m <= maxF; m += f) {
                multCount[f] += divCount[m];
            }
        }

        vector<int> dp(budget + 1, 0);
        for (const auto& item : items) {
            int f = item[0];
            int p = item[1];
            if (p > budget) continue;

            int firstGain = multCount[f];

            // First copy: gives `firstGain` items (1 bought + freebies from factor `f`)
            for (int b = budget; b >= p; b--) {
                dp[b] = max(dp[b], dp[b - p] + firstGain);
            }

            // Extra copies of the same item: each gives +1 item
            for (int b = p; b <= budget; b++) {
                dp[b] = max(dp[b], dp[b - p] + 1);
            }
        }

        int ans = 0;
        for (int b = 0; b <= budget; b++) {
            ans = max(ans, dp[b]);
        }
        return ans;
    }
};