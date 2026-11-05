class Solution {
private:
    void sol(int row,int col,int n,int m,vector<vector<int>> &visited,int aRow[],int aCol[],vector<vector<char>> board){
        visited[row][col]=1;
        for(int i=0;i<4;i++){
            int nrow=row+aRow[i];
            int ncol=col+aCol[i];
            if((nrow>=0 && nrow<n) && (ncol>=0 && ncol<m) && !visited[nrow][ncol] && board[nrow][ncol]=='O'){
                sol(nrow,ncol,n,m,visited,aRow,aCol,board);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int aRow[]={0,1,0,-1};
        int aCol[]={1,0,-1,0};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(!visited[i][j] && board[i][j]=='O'){
                        sol(i,j,n,m,visited,aRow,aCol,board);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};