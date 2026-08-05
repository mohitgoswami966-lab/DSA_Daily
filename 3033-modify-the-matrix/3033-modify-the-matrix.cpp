class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> ans=matrix;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                int maxCol=INT_MIN;
                if(matrix[i][j]==-1){
                    for(int k=0;k<matrix.size();k++){
                        maxCol=max(maxCol,matrix[k][j]);
                    }
                    ans[i][j]=maxCol;
                }
            }
        }
        return ans;
    }
};