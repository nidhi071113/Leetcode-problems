class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int cnt[26] = {};
        for(char c : s)
            cnt[c - 'a']++;

        int n = s.size();
        int i = 0;

        while(i < n && cnt[target[i] - 'a'] > 0) {
            cnt[target[i] - 'a']--;
            i++;
        }

        if(i == n) {
            i--;
            cnt[target[i] - 'a']++;
        }

        for(int j = i; j >= 0; j--) {
            if(j < i)
                cnt[target[j] - 'a']++;

            int x = target[j] - 'a';

            for(int c = x + 1; c < 26; c++) {
                if(cnt[c] == 0)
                    continue;

                string ans = target.substr(0, j);
                ans += char('a' + c);
                cnt[c]--;

                for(int k = 0; k < 26; k++) {
                    while(cnt[k] > 0) {
                        ans += char('a' + k);
                        cnt[k]--;
                    }
                }

                return ans;
            }
        }

        return "";
    }
};