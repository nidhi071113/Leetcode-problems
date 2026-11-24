class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int ans=0;

        for(int i=0;i<n;i++){
            long long prod =1;
            long long curGcd = 0;
            long long curLcm = 1;

            for(int j=i;j<n;j++){
                prod *= nums[j];
                curGcd = gcd(curGcd,(long long)nums[j]);
                curLcm = lcm(curLcm,(long long)nums[j]);

                if(prod == curLcm * curGcd){
                    ans = max(ans,j-i+1);
                }

                if(prod > 25200){
                    break;
                }
            }
            
        }
        return ans;
    }
};