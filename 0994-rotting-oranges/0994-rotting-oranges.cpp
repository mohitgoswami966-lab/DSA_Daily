class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cntFresh=0;
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> visited(n,vector(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visited[i][j]=2;
                }
                else{
                    visited[i][j]=0;
                }
                if(grid[i][j]==1) cntFresh++;
            }
        }
        int tm=0;
        int cnt=0;
        int aRow[]={-1,0,1,0};
        int aCol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            tm=max(tm,t);
            for(int i=0;i<4;i++){
                int nRow=r+aRow[i];
                int nCol=c+aCol[i];
                if((nRow>=0 && nRow<n) && (nCol>=0 && nCol<m) && !visited[nRow][nCol] &&
                grid[nRow][nCol]==1){
                    q.push({{nRow,nCol},t+1});
                    visited[nRow][nCol]=2;
                    cnt++;
                }
            }
        }
        if(cnt!=cntFresh) return -1;
        return tm;
    }
};