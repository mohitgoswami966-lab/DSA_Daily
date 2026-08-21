class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<int> curr(col+1,0);
        vector<int> next(col+1,0);
        int maxi=0;
        for(int i=row-1;i>=0;i--){
            for(int j=col-1;j>=0;j--){
                int right=curr[j+1];
                int diagonal=next[j+1];
                int down=next[j];
                if(matrix[i][j]=='1'){
                    curr[j]=1+min(right,min(diagonal,down));
                    maxi=max(maxi,curr[j]);
                }
                else{
                    curr[j]=0;
                }
            }
            next=curr;
        }
        return maxi*maxi;
    }
};