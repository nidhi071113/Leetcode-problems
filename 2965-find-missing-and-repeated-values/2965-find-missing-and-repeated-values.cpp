class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        // int n = grid.size();
        //brute approach
        // int range = n*n;
        // unordered_map<int,int> freq;

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         freq[grid[i][j]]++;
        //     }
        // }

        // int cnt1 = -1;
        // int cnt2 = -1;

        // for(int i=1;i<=range;i++){
        //     if(freq[i] == 2){
        //         cnt1 = i;
        //     }
        //     else if(freq[i] == 0){
        //         cnt2 = i;
        //     }
        // }

        // return {cnt1,cnt2};


        //optimal approach is using sums 
        long long n = grid.size();
        long long range = n*n;
        long long sumActual = 0 , sqSumActual = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sumActual += grid[i][j];
                sqSumActual += (long long)grid[i][j] * grid[i][j];
            }
        }

        long long sumExpect = (range * (range +1)) / 2;
        long long sqSumExpect = (range*(range+1) * (2*range+1)) / 6;

        long long R = sumActual - sumExpect;
        long long M = sqSumActual - sqSumExpect;

        long long val = M/R;

        long long repeated = (R+val)/2;
        long long missing = repeated - R;

        return {(int)repeated , (int)missing};
    }
};