class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1,0));
        for(int j=0;j<word2.size();j++){
            dp[word1.size()][j]=word2.size()-j;
        }
        for(int j=0;j<word1.size();j++){
            dp[j][word2.size()]=word1.size()-j;
        }
        for(int i=word1.size()-1;i>=0;i--){
            for(int j=word2.size()-1;j>=0;j--){
                int ans=0;
                if(word1[i]==word2[j]){
                    ans=dp[i+1][j+1];
                }
                else{
                    int insertAns=1+dp[i][j+1];
                    int deleteAns=1+dp[i+1][j];
                    int replaceAns=1+dp[i+1][j+1];
                    ans=min({insertAns,deleteAns,replaceAns});
                }
                dp[i][j]=ans;
            }
        }
        return dp[0][0];
    }
};