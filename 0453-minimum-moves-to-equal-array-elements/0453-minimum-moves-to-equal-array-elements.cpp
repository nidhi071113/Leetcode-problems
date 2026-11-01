class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        int mini = nums[0];
        for(int i=0 ; i<n ; i++){
            sum += nums[i];
            if(nums[i] < mini){
                mini = nums[i];
            }
        }

        return sum - ((long long)n * mini);
    }
};