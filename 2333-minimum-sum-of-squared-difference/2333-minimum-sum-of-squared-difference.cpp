class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> diff(n);
        
        int maxDiff = 0;
        for(int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxDiff = max(maxDiff, diff[i]);
        }
        
        vector<int> count(maxDiff + 1, 0);
        for(int i = 0; i < n; i++) {
            count[diff[i]]++;
        }
        
        long long k = k1 + k2;
        
        for(int d = maxDiff; d > 0; d--) {
            if(count[d] == 0) continue;
            
            if(k >= count[d]) {
                k -= count[d];
                count[d - 1] += count[d];
                count[d] = 0;
            } else {
                count[d] -= k;
                count[d - 1] += k;
                k = 0;
                break;
            }
        }
        
        long long result = 0;
        for(long long d = 0; d <= maxDiff; d++) {
            if(count[d] > 0) {
                result += count[d] * d * d;
            }
        }
        
        return result;
    }
};