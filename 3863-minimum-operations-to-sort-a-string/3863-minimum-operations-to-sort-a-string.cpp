class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        string t = s;
        sort(t.begin(), t.end());

        if (s == t) return 0;
        if (n == 2) return -1;

        char mn = t[0];
        char mx = t[n - 1];

        if (s[0] == mn || s[n - 1] == mx) return 1;

        if (s[0] == mx && s[n - 1] == mn &&
            count(s.begin(), s.end(), mx) == 1 &&
            count(s.begin(), s.end(), mn) == 1) {
            return 3;
        }

        return 2;
    }
};