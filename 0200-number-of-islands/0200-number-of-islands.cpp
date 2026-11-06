class Solution {
private:
    void solve(int row,int col,int n,int m,vector<vector<int>> &visited,vector<vector<char>> &grid ,int aRow[],int aCol[]){
        visited[row][col]=1;
        for(int i=0;i<4;i++){
            int nrow=row+aRow[i];
            int ncol=col+aCol[i];
            if((nrow>=0 && nrow<n) && (ncol>=0 && ncol<m) && !visited[nrow][ncol] &&
              grid[nrow][ncol]=='1'){
                solve(nrow,ncol,n,m,visited,grid,aRow,aCol);
              }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        int aRow[]={1,0,-1,0};
        int aCol[]={0,1,0,-1};
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    count++;
                    solve(i,j,n,m,visited,grid,aRow,aCol);
                }
            }
        }
        return count;
    }
};