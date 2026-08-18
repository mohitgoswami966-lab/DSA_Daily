class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int x:nums){
            sum+=x;
        }
        if(sum%2!=0) return false;
        int W=sum/2;
        vector<bool> curr(W+1,false);
        curr[0]=true;
        for(int i=0;i<nums.size();i++){
            for(int j=W;j>=0;j--){
                bool include=false;
                if(nums[i]<=j){
                    include=curr[j-nums[i]];
                }
                bool exclude=curr[j];
                curr[j]=include||exclude;
            }
        }
        return curr[W];
    }
};