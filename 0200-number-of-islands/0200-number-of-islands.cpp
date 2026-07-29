class Solution {
private:
    void dfs(int row,int col,int n,int m,vector<vector<char>> &grid,vector<vector<int>> &visited,int aRow[],int aCol[]){
        visited[row][col]=1;
        for(int i=0;i<4;i++){
            int nrow=row+aRow[i];
            int ncol=col+aCol[i];
            if((nrow>=0 && nrow<n) && (ncol>=0 && ncol<m) && !visited[nrow][ncol] && grid[nrow][ncol]=='1'){
                dfs(nrow,ncol,n,m,grid,visited,aRow,aCol);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int aRow[]={-1,0,1,0};
        int aCol[]={0,1,0,-1};
        int cnt=0;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,n,m,grid,visited,aRow,aCol);
                }
            }
        }
        return cnt;
    }
};