class Solution {
private:
    void reverse(vector<int> &nums, int left, int right) {
        while (left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }

public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= 1) return;
        
        k = k % n;
        if (k == 0) return;
        
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);      
    }
};