class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<int> ans;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                int a=0;
                if(mat[i][j]==1){
                for(int k=0;k<mat.size();k++){
                    if(mat[k][j]==1 && k!=i) a++;
                }
                for(int k=0;k<mat[0].size();k++){
                    if(mat[i][k]==1 && k!=j) a++;
                }
                if(a==0){
                    ans.push_back(mat[i][j]);
                }}
            }
        }
        return ans.size();
    }
};