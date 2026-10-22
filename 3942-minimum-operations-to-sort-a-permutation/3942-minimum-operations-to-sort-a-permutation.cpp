class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int best = INT_MAX;

        auto isSorted = [&](vector<int>& a) {
            for (int i = 0; i < n; i++) {
                if (a[i] != i) return false;
            }
            return true;
        };

        vector<int> arr = nums;
        int r = find(arr.begin(), arr.end(), 0) - arr.begin();
        rotate(arr.begin(), arr.begin() + r, arr.end());
        if (isSorted(arr)) best = min(best, r);

        arr = nums;
        reverse(arr.begin(), arr.end());
        r = find(arr.begin(), arr.end(), 0) - arr.begin();
        rotate(arr.begin(), arr.begin() + r, arr.end());
        if (isSorted(arr)) best = min(best, r + 1);

        arr = nums;
        r = find(arr.begin(), arr.end(), n - 1) - arr.begin();
        rotate(arr.begin(), arr.begin() + r, arr.end());
        reverse(arr.begin(), arr.end());
        if (isSorted(arr)) best = min(best, r + 1);

        arr = nums;
        reverse(arr.begin(), arr.end());
        r = find(arr.begin(), arr.end(), n - 1) - arr.begin();
        rotate(arr.begin(), arr.begin() + r, arr.end());
        reverse(arr.begin(), arr.end());
        if (isSorted(arr)) best = min(best, r + 2);

        if (best == INT_MAX) return -1;
        return best;
    }
};