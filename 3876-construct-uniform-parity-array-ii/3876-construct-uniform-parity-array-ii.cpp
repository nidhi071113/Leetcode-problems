class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini = INT_MAX;
        for(int x : nums1){
            if(x % 2 == 1) mini = min(mini,x);
        }   
        for(int x : nums1){
            if(x % 2 == 0 && mini != INT_MAX && x < mini) return false;
        }
        return true;
    }
};