class Solution {
private:
    void solve(int col,int n,vector<vector<string>> &ans,vector<string> &board,vector<int> &leftRow,vector<int> &leftDiagonal,vector<int> &rightDiagonal){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(leftRow[row]==0 && leftDiagonal[row+col]==0 && rightDiagonal[(n-1)+(col-row)]==0){
                board[row][col]='Q';
                leftRow[row]=1;
                leftDiagonal[row+col]=1;
                rightDiagonal[(n-1)+(col-row)]=1;
                solve(col+1,n,ans,board,leftRow,leftDiagonal,rightDiagonal);
                board[row][col]='.';
                leftRow[row]=0;
                leftDiagonal[row+col]=0;
                rightDiagonal[(n-1)+(col-row)]=0;
            }
        }
    }
public:
    int totalNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        vector<int> leftRow(n,0);
        vector<int> leftDiagonal(2*n-1,0);
        vector<int> rightDiagonal(2*n-1,0);
        solve(0,n,ans,board,leftRow,leftDiagonal,rightDiagonal);
        return ans.size();
    }
};