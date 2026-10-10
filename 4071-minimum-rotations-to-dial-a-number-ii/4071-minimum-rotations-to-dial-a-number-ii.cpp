class Solution {
public:
    int minRotations(int n, string s) {
        auto dist = [](int a, int b) {
            int diff = abs(a - b);
            return min(diff, 10 - diff);
        };

        int total = 0;

        for (int i = 1; i < n; i++) {
            total += dist(s[i - 1] - '0', s[i] - '0');
        }

        int first = s[0] - '0';
        int last = s[n - 1] - '0';

        int ans = total + dist(0, last);

        for (int i = 1; i < n; i++) {
            int oldCost = dist(s[i - 1] - '0', s[i] - '0');
            int newCost = dist(s[i - 1] - '0', last);

            int candidate = total - oldCost + dist(0, first) + newCost;

            ans = min(ans, candidate);
        }

        return ans;
    }
};