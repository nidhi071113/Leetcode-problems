class Solution {
private:
    int memo[21][21];

    bool solve(int i, int j, string& s, string& p) {
        // Base case: if pattern is fully processed, string must also be fully matched
        if (j == p.length()) {
            return i == s.length();
        }

        // Return memoized result if already computed
        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        // Check if current characters match
        bool firstMatch = (i < s.length()) && (s[i] == p[j] || p[j] == '.');

        // Case 1: Next character in pattern is '*'
        if (j + 1 < p.length() && p[j + 1] == '*') {
            // Choice A: Ignore 'x*' (matches 0 occurrences of x)
            // Choice B: Use '*' to match current character (requires firstMatch)
            bool ignoreStar = solve(i, j + 2, s, p);
            bool useStar = firstMatch && solve(i + 1, j, s, p);

            return memo[i][j] = ignoreStar || useStar;
        }

        // Case 2: Standard character match without '*'
        if (firstMatch) {
            return memo[i][j] = solve(i + 1, j + 1, s, p);
        }

        return memo[i][j] = false;
    }

public:
    bool isMatch(string s, string p) {
        memset(memo, -1, sizeof(memo));
        return solve(0, 0, s, p);
    }
};