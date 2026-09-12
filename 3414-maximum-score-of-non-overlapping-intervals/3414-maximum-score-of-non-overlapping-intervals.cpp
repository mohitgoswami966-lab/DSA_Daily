class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n=intervals.size();
        for(int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }
        sort(intervals.begin(),intervals.end(),[](vector<int> &a,vector<int> &b){
            return a[1]<b[1];
        });
        vector<int> end(n);
        for(int i=0;i<n;i++){
            end[i]=intervals[i][1];
        }
        vector<vector<long long>> dp(n+1,vector<long long>(5,0));
        vector<vector<vector<int>>> choice(n + 1, vector<vector<int>>(5));
        for(int i=1;i<=n;i++){
            int start=intervals[i-1][0];
            int score=intervals[i-1][2];
            int index = intervals[i-1][3];
            int low=0,high=i-2;
            int prev=-1;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(end[mid]<start){
                    prev=mid;
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            for(int k=1;k<=4;k++){
                dp[i][k]=dp[i-1][k];
                choice[i][k] = choice[i-1][k];
                long long take=score;
                vector<int> takeIds;
                if(prev!=-1){
                    take+=dp[prev+1][k-1];
                    takeIds = choice[prev+1][k-1];
                }
                takeIds.push_back(index);
                sort(takeIds.begin(), takeIds.end());
                if(take > dp[i][k]) {

                    dp[i][k] = take;
                    choice[i][k] = takeIds;
                }
                else if(take == dp[i][k]) {

                    if(takeIds < choice[i][k]) {
                        choice[i][k] = takeIds;
                    }
                }
            }
        }
        return choice[n][4];
    }
};