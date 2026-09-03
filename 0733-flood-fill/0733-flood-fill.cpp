class Solution {
private:
    void dfs(int row,int col,vector<vector<int>>& ans,vector<vector<int>>& image,int color,
    int dlrow[],int dlcol[],int init){
        int n = image.size();
        int m = image[0].size();
        ans[row][col] = color;

        for(int i = 0 ; i<4 ; i++){
            int nrow = row + dlrow[i];
            int ncol = col + dlcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
            image[nrow][ncol] == init && ans[nrow][ncol] != color)
            {
                dfs(nrow,ncol,ans,image,color,dlrow,dlcol,init);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int init = image[sr][sc];
        vector<vector<int>> ans = image;
        int dlrow[] = {-1,0,+1,0};
        int dlcol[] = {0,+1,0,-1};
        dfs(sr,sc,ans,image,color,dlrow,dlcol,init);
        return ans;
    }
};