class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int a=1;
        vector<vector<int>> ans(n,vector<int>(n,0));
        int srow=0;
        int scol=0;
        int erow=n-1;
        int ecol=n-1;
        while(srow<=erow && scol<=ecol){
            for(int i=scol;i<=ecol;i++){
                ans[srow][i]=a;
                a++;
            }
            srow++;
            for(int i=srow;i<=erow;i++){
                ans[i][ecol]=a;
                a++;
            }
            ecol--;
            if(srow<=erow){
                for(int i=ecol;i>=scol;i--){
                    ans[erow][i]=a;
                    a++;
                }
                erow--;
            }
            if(scol<=ecol){
                for(int i=erow;i>=srow;i--){
                    ans[i][scol]=a;
                    a++;
                }
                scol++;
            }
        }
        return ans;
    }
};