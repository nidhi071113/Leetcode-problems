class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = (int)nums.size();
        const long long MOD1 = 1000000007LL;
        const long long MOD2 = 1000000009LL;
        const long long B1 = 100003LL;
        const long long B2 = 100019LL;

        vector<long long> p1(n + 1, 1), p2(n + 1, 1);
        vector<long long> h1(n + 1, 0), h2(n + 1, 0);

        for (int i = 0; i < n; i++) {
            long long val = nums[i] + 1LL;
            p1[i + 1] = (p1[i] * B1) % MOD1;
            p2[i + 1] = (p2[i] * B2) % MOD2;
            h1[i + 1] = (h1[i] * B1 + val) % MOD1;
            h2[i + 1] = (h2[i] * B2 + val) % MOD2;
        }

        auto getHash = [&](int l, int r) -> unsigned long long {
            long long x1 = (h1[r + 1] - h1[l] * p1[r - l + 1]) % MOD1;
            if (x1 < 0) x1 += MOD1;
            long long x2 = (h2[r + 1] - h2[l] * p2[r - l + 1]) % MOD2;
            if (x2 < 0) x2 += MOD2;
            return (static_cast<unsigned long long>(x1) << 32) | static_cast<unsigned long long>(x2);
        };

        auto hasUniqueOfLen = [&](int len) -> bool {
            unordered_map<unsigned long long, int> freq;
            freq.reserve((n - len + 1) * 2);
            for (int i = 0; i + len <= n; i++) {
                freq[getHash(i, i + len - 1)]++;
            }
            for (const auto& kv : freq) {
                if (kv.second == 1) return true;
            }
            return false;
        };

        int lo = 1, hi = n, ans = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (hasUniqueOfLen(mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return ans;
    }
};