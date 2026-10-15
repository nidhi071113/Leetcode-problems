class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        // sort(nums.begin(),nums.end());
        // for(int i = 0 ; i < n ; i++){
        //     if(nums[i] != i){
        //         return i;
        //     }
        // }
        // return n;

        int total = n*(n+1)/2;
        int actualSum = 0;
        for(int num : nums){
            actualSum += num;
        }

        return total - actualSum;
    }
};