class Solution {
public:
    int bfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid){
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int n = grid.size();
        int m = grid[0].size();
        int delrow[] = {0,0,1,-1};
        int delcol[] = {1,-1,0,0};
        int maxIsland = 1;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            int island = 0;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = row+delrow[i];
                int ncol = col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                    maxIsland++;
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
        return maxIsland;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0, len = 0;
        vector<vector<int>> vis(n, vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    len = bfs(i,j,vis,grid);
                    ans = max(ans, len);
                }
            }
        }
        return ans;
    }
};