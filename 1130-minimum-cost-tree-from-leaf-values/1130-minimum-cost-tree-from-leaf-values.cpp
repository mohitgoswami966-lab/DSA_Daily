class Solution {
private:
    int solve(vector<int>& arr,map<pair<int,int>,int> &maxi){
        int n=arr.size();
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        for(int start=n-1;start>=0;start--){
            for(int end=start;end<n;end++){
                int ans=INT_MAX;
                for(int i=start;i<end;i++){
                    ans =min(ans,maxi[{start,i}]*maxi[{i+1,end}]+dp[start][i]+dp[i+1][end]);
                }
                if(start==end) ans=0;
                dp[start][end]=ans;
            }
        }
        return dp[0][n-1];
    }
public:
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>,int> maxi;
        for(int i=0;i<arr.size();i++){
            maxi[{i,i}]=arr[i];
            for(int j=i+1;j<arr.size();j++){
                maxi[{i,j}]=max(arr[j],maxi[{i,j-1}]);
            }
        }
        return solve(arr,maxi);
    }
};