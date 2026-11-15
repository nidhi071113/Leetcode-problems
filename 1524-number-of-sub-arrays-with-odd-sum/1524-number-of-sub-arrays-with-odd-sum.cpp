class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9+7;
        int even =1,odd=0;
        int parity=0;
        long long ans=0;

        for(int x:arr){
            parity =(parity+x)%2;

            if(parity==1){
                ans += even;
                odd++;
            }
            else{
                ans += odd;
                even++;
            }

            ans %= MOD;
        }
        return ans;
    }
};