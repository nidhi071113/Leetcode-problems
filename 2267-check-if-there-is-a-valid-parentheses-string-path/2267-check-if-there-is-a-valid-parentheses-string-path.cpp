class Solution {
public:
    int m, n;
    int memo[100][100][101];

    bool dfs(int r, int c, int bal, vector<vector<char>>& grid) {
        if(grid[r][c] == '(')
            bal++;
        else
            bal--;

        if(bal < 0)
            return false;

        if(r == m-1 && c == n-1)
            return bal == 0;

        if(memo[r][c][bal] != -1)
            return memo[r][c][bal];

        int dr[2] = {1, 0};
        int dc[2] = {0, 1};

        for(int i = 0; i < 2; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < m && nc < n) {
                if(dfs(nr, nc, bal, grid))
                    return memo[r][c][bal] = 1;
            }
        }

        return memo[r][c][bal] = 0;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if((m+n-1)%2 != 0)
            return false;

        if(grid[0][0] == ')' || grid[m-1][n-1] == '(')
            return false;

        memset(memo, -1, sizeof(memo));

        return dfs(0, 0, 0, grid);
    }
};