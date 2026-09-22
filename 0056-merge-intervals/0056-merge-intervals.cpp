class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());

        vector<vector<int>> ans;

        for(auto num : intervals){
            if(ans.empty() || ans.back()[1] < num[0]){
                ans.push_back(num);
            }   
            else{
                ans.back()[1] = max(num[1],ans.back()[1]);
            }
        }
        return ans;
    }
};