class Solution {
private:
    int solve(vector<int> &nums,vector<int> &dp,int n){
        if(n<0) return 0;
        if(n==0) return nums[0];
        if(dp[n]!=-1) return dp[n];
        int inc=solve(nums,dp,n-2)+nums[n];
        int exc=solve(nums,dp,n-1)+0;
        dp[n]=max(inc,exc);
        return dp[n];
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(nums,dp,n-1);
    }
};