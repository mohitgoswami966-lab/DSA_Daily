class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        vector<int> rowZero(r,0);
        vector<int> colZero(c,0);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]==0){
                    rowZero[i]=1;
                    colZero[j]=1;
                }
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(rowZero[i]==1 || colZero[j]==1){
                    matrix[i][j]=0;
                }
            }
        }
    }
};