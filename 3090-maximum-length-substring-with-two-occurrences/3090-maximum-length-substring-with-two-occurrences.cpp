class Solution {
public:
    int maximumLengthSubstring(string s) {
        int cnt[256] = {0};
        int l = 0, ans = 0;

        for(int r = 0; r < s.size(); r++) {
            cnt[s[r]]++;

            while(cnt[s[r]] > 2) {
                cnt[s[l]]--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};