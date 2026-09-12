class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<long long,3>> a(n);
        for(int i = 0; i < n; i++)
            a[i] = {intervals[i][0], intervals[i][1], i};

        sort(a.begin(), a.end());

        vector<int> next(n);

        for(int i = 0; i < n; i++) {
            int l = i + 1, r = n;
            while(l < r) {
                int mid = (l + r) / 2;
                if(a[mid][0] > a[i][1])
                    r = mid;
                else
                    l = mid + 1;
            }
            next[i] = l;
        }

        vector<vector<long long>> dp(5, vector<long long>(n + 1, 0));
        vector<vector<vector<int>>> path(5, vector<vector<int>>(n + 1));

        for(int k = 1; k <= 4; k++) {
            for(int i = n - 1; i >= 0; i--) {
                dp[k][i] = dp[k][i + 1];
                path[k][i] = path[k][i + 1];

                long long take = intervals[a[i][2]][2];

                if(k > 1)
                    take += dp[k - 1][next[i]];

                vector<int> cur = path[k - 1][next[i]];
                cur.push_back(a[i][2]);
                sort(cur.begin(), cur.end());

                if(take > dp[k][i] ||
                   (take == dp[k][i] && cur < path[k][i])) {
                    dp[k][i] = take;
                    path[k][i] = cur;
                }
            }
        }

        return path[4][0];
    }
};