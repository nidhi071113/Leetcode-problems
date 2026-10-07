class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long diff=0;

        for(int i=1;i < nums.size();i++){
            if(nums[i-1] > nums[i]){
                diff += nums[i-1] - nums[i];
            }
        }
        return diff;
    }
};