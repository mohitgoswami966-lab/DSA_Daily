class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(int x:nums){
            sum+=x;
        }
        if(abs(target)>sum)  return 0;
        if((sum+target)%2!=0) return 0;
        int W=(sum+target)/2;
        vector<int> curr(W+1,0);
        curr[0]=1;
        for(int i=0;i<nums.size();i++){
            for(int j=W;j>=0;j--){
                int include=0;
                if(nums[i]<=j){
                    include=curr[j-nums[i]];
                }
                int exclude=curr[j];
                curr[j]=include+exclude;
            }
        }
        return curr[W];
    }
};