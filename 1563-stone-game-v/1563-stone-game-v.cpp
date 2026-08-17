class Solution {
public:

    int solver(vector<int>& prefsum , int i , int j , vector<vector<int>>&dp) {

        if (i==j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int cost = 0 , maxcost = INT_MIN;
        for (int k = i; k < j; k++) {

            int left  = prefsum[k] - prefsum[i-1];
            int right = prefsum[j] - prefsum[k];

            if (left < right) {

                // Bob removes right, Alice keeps left
                cost = left + solver(prefsum, i, k, dp);

            } 
            else if (left > right) {

                // Bob removes left, Alice keeps right....in case of 
                cost = right + solver(prefsum, k+1, j, dp);

            } 
            else {

                // Equal -> Alice can choose either of the sides 
                cost = left + max(
                    solver(prefsum, i, k, dp),
                    solver(prefsum, k+1, j, dp)
                );
            }

            maxcost = max(maxcost, cost);
        }

        return dp[i][j] = maxcost;

    }

    int stoneGameV(vector<int>& stones) {
        
        //dp[i][j] tells us the maximum sum alice can get from subarray i,j//
        int n = stones.size();
        vector<int> prefsum;
        int sum = 0;
        prefsum.push_back(0);
        for (auto it:stones) {
            sum += it;
            prefsum.push_back(sum);
        }

        vector<vector<int>> dp(n+2 , vector<int>(n+2 , -1));

        return solver(prefsum , 1 , n, dp);

    }
};