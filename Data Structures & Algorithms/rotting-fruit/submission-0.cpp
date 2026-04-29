class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int vis[n][m];
        int cntFresh=0;
        queue<pair<int, pair<int,int>>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    vis[i][j]=2;
                    q.push({0,{i,j}});
                }
                else vis[i][j]=0;
                if(grid[i][j]==1) cntFresh++;
            }
        }
        int tm=0;
        int delrow[]={0,0,1,-1};
        int delcol[]={1,-1,0,0};
        int cnt=0;
        while(!q.empty()){
            int time = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            tm = max(tm, time);
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = row+delrow[i];
                int ncol = col+delcol[i];
                if(nrow>=0 and ncol>=0 and nrow<n and ncol<m and vis[nrow][ncol]!=2 and grid[nrow][ncol]==1){
                    q.push({time+1,{nrow,ncol}});
                    vis[nrow][ncol]=2;
                    cnt++;
                }
            }
        }
        if(cntFresh!=cnt) return -1;
        return tm;
    }
};