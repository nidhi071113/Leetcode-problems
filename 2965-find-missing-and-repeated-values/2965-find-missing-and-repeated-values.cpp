class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int range = n*n;
        unordered_map<int,int> freq;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                freq[grid[i][j]]++;
            }
        }

        int cnt1 = -1;
        int cnt2 = -1;

        for(int i=1;i<=range;i++){
            if(freq[i] == 2){
                cnt1 = i;
            }
            else if(freq[i] == 0){
                cnt2 = i;
            }
        }

        return {cnt1,cnt2};
    }
};