class Solution {
private:
    int solve(int i,vector<int> &stoneValue,vector<int> &dp){
        if(i>=stoneValue.size()) return 0;
        int sum=0;
        int ans=INT_MIN;
        if(dp[i]!=INT_MIN) return dp[i];
        for(int k=0;k<3 && i+k<stoneValue.size();k++){
            sum +=stoneValue[i+k];
            ans=max(ans,sum-solve(i+k+1,stoneValue,dp));
        }
        return dp[i]=ans;
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int> dp(n,INT_MIN);
        solve(0,stoneValue,dp);
        if(dp[0]>0) return "Alice";
        else if(dp[0]<0) return "Bob";
        else{
            return "Tie";
        }
    }
};