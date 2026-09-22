// Comparator function to sort intervals by their end time in ascending order
bool comp(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return 0;

        // Step 1: Sort intervals based on end time
        sort(intervals.begin(), intervals.end(), comp);

        // Step 2: Initialize count of non-overlapping intervals and track last end time
        int cnt = 1;
        int lastEndTime = intervals[0][1];

        // Step 3: Iterate through remaining intervals
        for (int i = 1; i < n; i++) {
            // If the current interval's start time >= last interval's end time
            if (intervals[i][0] >= lastEndTime) {
                cnt = cnt + 1;
                lastEndTime = intervals[i][1];
            }
        }

        // Step 4: Minimum removals = total intervals - max non-overlapping intervals
        return n - cnt;
    }
};