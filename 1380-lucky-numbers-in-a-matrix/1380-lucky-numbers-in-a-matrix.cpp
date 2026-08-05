class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> ans;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                int minRow=INT_MAX;
                int maxCol=INT_MIN;
                for(int k=0;k<matrix.size();k++){
                    maxCol=max(maxCol,matrix[k][j]);
                }
                for(int k=0;k<matrix[0].size();k++){
                    minRow=min(minRow,matrix[i][k]);
                }
                if(minRow==maxCol){
                    ans.push_back(minRow);
                }
            }
        }
        return ans;
    }
};