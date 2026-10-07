class Solution {
    vector<string> ans;

    void solve(string& s, int i, int l, int r, int open, string cur) {
        if (i == s.size()) {
            if (l == 0 && r == 0 && open == 0) {
                ans.push_back(cur);
            }
            return;
        }

        if (s[i] == '(') {
            if (l > 0) {
                solve(s, i + 1, l - 1, r, open, cur);
            }
            solve(s, i + 1, l, r, open + 1, cur + '(');
        } 
        else if (s[i] == ')') {
            if (r > 0) {
                solve(s, i + 1, l, r - 1, open, cur);
            }
            if (open > 0) {
                solve(s, i + 1, l, r, open - 1, cur + ')');
            }
        } 
        else {
            solve(s, i + 1, l, r, open, cur + s[i]);
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        int l = 0, r = 0;

        for (char c : s) {
            if (c == '(') {
                l++;
            } else if (c == ')') {
                if (l > 0) l--;
                else r++;
            }
        }

        solve(s, 0, l, r, 0, "");

        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};