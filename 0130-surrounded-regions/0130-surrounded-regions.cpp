class Solution {
public:
    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(m,0));

        for(int j=0;j<m;j++){
            if(board[0][j] == 'O'){
                q.push({0,j});
                vis[0][j] = 1;
            }

            if(board[n-1][j] == 'O'){
                q.push({n-1,j});
                vis[n-1][j] = 1;
            }
        }

        for(int i=0;i<n;i++){
            if(board[i][0] == 'O'){
                q.push({i,0});
                vis[i][0] = 1;
            }

            if(board[i][m-1] == 'O'){
                q.push({i,m-1});
                vis[i][m-1] = 1;
            }
        }

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        while(!q.empty()){

            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){

                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] &&
                   board[nrow][ncol] == 'O')
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(board[i][j] == 'O' && !vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};